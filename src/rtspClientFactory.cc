#include "rtsp_client.h"

Napi::Object RtspClientNapi::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "RtspClientNapi", {
            InstanceMethod("test", &RtspClientNapi::Test),
    });

    Napi::FunctionReference *constructor = new Napi::FunctionReference();
    *constructor = Napi::Persistent(func);
    exports.Set("RtspClientNapi", func);
    return exports;
}

RtspClientNapi::RtspClientNapi(const Napi::CallbackInfo &info) : Napi::ObjectWrap<RtspClientNapi>(info) {
    Napi::Env env = info.Env();
    if (info.Length() < 1 || !info[0].IsObject()) {
        Napi::TypeError::New(env, "Expected an object").ThrowAsJavaScriptException();
        return;
    }

    Napi::Object options = info[0].As<Napi::Object>();
    if (!options.Has("id") || !options.Get("id").IsString()) {
        Napi::TypeError::New(env, "Expected 'id' to be a string").ThrowAsJavaScriptException();
        return;
    }
    if (!options.Has("password") || !options.Get("password").IsString()) {
        Napi::TypeError::New(env, "Expected 'password' to be a string").ThrowAsJavaScriptException();
        return;
    }
    if (!options.Has("url") || !options.Get("url").IsString()) {
        Napi::TypeError::New(env, "Expected 'url' to be a string").ThrowAsJavaScriptException();
        return;
    }
    this->id_ = options.Get("id").As<Napi::String>().Utf8Value();
    this->password_ = options.Get("password").As<Napi::String>().Utf8Value();
    this->url_ = options.Get("url").As<Napi::String>().Utf8Value();
}

Napi::Value RtspClientNapi::Test(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    return Napi::String::New(env, "test");
}