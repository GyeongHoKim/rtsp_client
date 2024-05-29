#include "rtsp_client.h"

Napi::FunctionReference RTSPClientWrapper::constructor;

Napi::Object RTSPClientWrapper::Init(Napi::Env env, Napi::Object exports)
{
  Napi::Function func = DefineClass(env, "RTSPClientWrapper", {InstanceMethod("connect", &RTSPClientWrapper::Connect), InstanceMethod("play", &RTSPClientWrapper::Play)});

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("RTSPClientWrapper", func);
  return exports;
}

RTSPClientWrapper::RTSPClientWrapper(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<RTSPClientWrapper>(info)
{
  this->rtsp_url = info[0].As<Napi::String>().Utf8Value();
  this->scheduler = BasicTaskScheduler::createNew();
  this->env = BasicUsageEnvironment::createNew(*scheduler);
  this->rtsp_client = RTSPClient::createNew(*this->env, this->rtsp_url.c_str());
}

Napi::Value RTSPClientWrapper::Connect(const Napi::CallbackInfo &info)
{
  // RTSP 연결 로직 구현
  this->rtsp_client->sendDescribeCommand(continueAfterDESCRIBE);
  return info.Env().Undefined();
}

Napi::Value RTSPClientWrapper::Play(const Napi::CallbackInfo &info)
{
  // RTSP 재생 로직 구현
  this->rtsp_client->sendPlayCommand(*this->rtsp_client->scs.session, continueAfterPLAY);
  return info.Env().Undefined();
}

// RTSP 콜백 함수들 (생략)

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
  return RTSPClientWrapper::Init(env, exports);
}

NODE_API_MODULE(rtsp_client, InitAll)