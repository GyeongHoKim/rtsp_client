#include <napi.h>
#include "rtsp_client.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
    return RtspClientNapi::Init(env, exports);
}

NODE_API_MODULE(addon, InitAll)