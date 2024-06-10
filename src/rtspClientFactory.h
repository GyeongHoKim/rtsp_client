#ifndef RTSP_CLIENT_H
#define RTSP_CLIENT_H

#include <napi.h>
#include <string>
#include "liveMedia.hh"
#include "BasicUsageEnvironment.hh"

class RTSPClientFactory : public Napi::ObjectWrap<RTSPClientFactory> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);

    RTSPClientFactory(const Napi::CallbackInfo &info);

    Napi::Value Test(const Napi::CallbackInfo &info);

    Napi::Value Play(const Napi::CallbackInfo &info);

    Napi::Value TearDown(const Napi::CallbackInfo &info);

private:
    TaskScheduler *taskScheduler;
    UsageEnvironment *usageEnvironment;
};

#endif