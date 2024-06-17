#include "GyeonghoRtspClient.h"

bool byeFromServerFlag = false;

Napi::Object GyeonghoRtspClient::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "GyeonghoRtspClient", {
            InstanceMethod("test", &GyeonghoRtspClient::Test),
            InstanceMethod("setURL", &GyeonghoRtspClient::SetURL),
            InstanceMethod("describe", &GyeonghoRtspClient::Describe),
            InstanceMethod("setup", &GyeonghoRtspClient::Setup),
            InstanceMethod("play", &GyeonghoRtspClient::Play),
            InstanceMethod("teardown", &GyeonghoRtspClient::Teardown)
    });

    Napi::FunctionReference *constructor = new Napi::FunctionReference();
    *constructor = Napi::Persistent(func);
    env.SetInstanceData(constructor);

    exports.Set("GyeonghoRtspClient", func);
    return exports;
}

GyeonghoRtspClient::GyeonghoRtspClient(const Napi::CallbackInfo &info) : Napi::ObjectWrap<GyeonghoRtspClient>(info) {
    Napi::Env env = info.Env();

    int length = info.Length();

    if (length <= 0 || !info[0].IsString()) {
        Napi::TypeError::New(env, "String expected").ThrowAsJavaScriptException();
        return;
    }

    Napi::String url = info[0].As<Napi::String>();
    this->url_ = url.Utf8Value();
    this->rtspClient_ = RtspClient(this->url_);
}

Napi::Value GyeonghoRtspClient::SetURL(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();

    int length = info.Length();

    if (length <= 0 || !info[0].IsString()) {
        Napi::TypeError::New(env, "String expected").ThrowAsJavaScriptException();
        return Napi::Boolean::New(env, false);
    }

    Napi::String url = info[0].As<Napi::String>();
    this->url_ = url.Utf8Value();
    this->rtspClient_.SetURI(this->url_);
    std::string uri = this->rtspClient_.GetURI();
    if (uri.empty()) {
        std::string errMsg = this->url_ + " is not a valid URI";
        Napi::TypeError::New(info.Env(), errMsg).ThrowAsJavaScriptException();
    }

    return Napi::String::New(env, uri);
}

Napi::Value GyeonghoRtspClient::Test(const Napi::CallbackInfo &info) {
    return Napi::String::New(info.Env(), "test");
}

Napi::Value GyeonghoRtspClient::Describe(const Napi::CallbackInfo &info) {
    ErrorType signal = this->rtspClient_.DoDESCRIBE();
    if (signal > 0) {
        std::string errMsg = this->rtspClient_.ParseError(signal);
        Napi::SyntaxError::New(info.Env(), errMsg).ThrowAsJavaScriptException();
    }
    this->rtspClient_.ParseSDP();
    return Napi::String::New(info.Env(), this->rtspClient_.GetSDP());
}

Napi::Value GyeonghoRtspClient::Setup(const Napi::CallbackInfo &info) {
    ErrorType signal = this->rtspClient_.DoSETUP("video", true);
    if (signal > 0) {
        std::string errMsg = this->rtspClient_.ParseError(signal);
        Napi::SyntaxError::New(info.Env(), errMsg).ThrowAsJavaScriptException();
    }
    this->rtspClient_.SetVideoByeFromServerClbk([]() {
        byeFromServerFlag = true;
    });
    return Napi::Boolean::New(info.Env(), true);
}

Napi::Value GyeonghoRtspClient::Play(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    if (info.Length() < 1 || !info[0].IsFunction()) {
        Napi::TypeError::New(info.Env(), "Function expected").ThrowAsJavaScriptException();
        return Napi::Boolean::New(info.Env(), false);
    }
    Napi::Function cb = info[0].As<Napi::Function>();
    ErrorType signal = this->rtspClient_.DoPLAY();
    if (signal > 0) {
        std::string errMsg = this->rtspClient_.ParseError(signal);
        Napi::SyntaxError::New(info.Env(), errMsg).ThrowAsJavaScriptException();
        return Napi::Boolean::New(info.Env(), false);
    }
    while (true) {
        const size_t BufSize = 98304;
        uint8_t buf[BufSize];
        size_t size = 0;
        if (!this->rtspClient_.GetMediaData("video", buf, &size, BufSize)) {
            continue;
        }
        cb.Call(env.Global(), {Napi::Buffer<uint8_t>::New(env, buf, size)});
        if (byeFromServerFlag) {
            break;
        }
    }
    this->rtspClient_.DoTEARDOWN();
    return Napi::Boolean::New(info.Env(), true);
}

Napi::Value GyeonghoRtspClient::Teardown(const Napi::CallbackInfo &info) {
    this->rtspClient_.DoTEARDOWN();
    return Napi::Boolean::New(info.Env(), true);
}