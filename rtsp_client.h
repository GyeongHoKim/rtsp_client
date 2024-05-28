// rtsp_client.h
#ifndef RTSP_CLIENT_H
#define RTSP_CLIENT_H

#include <napi.h>
#include <string>
#include <liveMedia.hh>
#include <BasicUsageEnvironment.hh>

class RTSPClientWrapper : public Napi::ObjectWrap<RTSPClientWrapper>
{
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  RTSPClientWrapper(const Napi::CallbackInfo &info);

private:
  static Napi::FunctionReference constructor;
  Napi::Value Connect(const Napi::CallbackInfo &info);
  Napi::Value Play(const Napi::CallbackInfo &info);

  std::string rtsp_url;
  RTSPClient *rtsp_client;
  TaskScheduler *scheduler;
  UsageEnvironment *env;
};

#endif // RTSP_CLIENT_H