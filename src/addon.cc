#include <napi.h>
#include "rtspClientFactory.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
    return RTSPClientFactory::Init(env, exports);
}

NODE_API_MODULE(addon, InitAll)