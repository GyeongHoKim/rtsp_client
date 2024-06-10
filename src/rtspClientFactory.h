#ifndef RTSP_CLIENT_H
#define RTSP_CLIENT_H

#include <napi.h>
#include <string>
#include "liveMedia.hh"
#include "BasicUsageEnvironment.hh"

class RtspClientNapi : public Napi::ObjectWrap<RtspClientNapi> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);

    RtspClientNapi(const Napi::CallbackInfo &info);

private:
    Napi::Value Test(const Napi::CallbackInfo &info);

    std::string id_;
    std::string password_;
    std::string url_;
};

#endif