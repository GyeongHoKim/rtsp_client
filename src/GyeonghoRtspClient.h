#ifndef RTSP_CLIENT_GYEONGHORTSPCLIENT_H
#define RTSP_CLIENT_GYEONGHORTSPCLIENT_H

#include <napi.h>
#include "rtspClient.h"

class GyeonghoRtspClient : public Napi::ObjectWrap<GyeonghoRtspClient> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);

    GyeonghoRtspClient(const Napi::CallbackInfo &info);

private:
    Napi::Value Test(const Napi::CallbackInfo &info);

    Napi::Value SetURL(const Napi::CallbackInfo &info);

    Napi::Value Describe(const Napi::CallbackInfo &info);

    Napi::Value Setup(const Napi::CallbackInfo &info);

    Napi::Value Play(const Napi::CallbackInfo &info);

    Napi::Value Teardown(const Napi::CallbackInfo &info);

    std::string url_;
    RtspClient rtspClient_;
};

#endif //RTSP_CLIENT_GYEONGHORTSPCLIENT_H
