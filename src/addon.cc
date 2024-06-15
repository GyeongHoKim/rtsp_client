#include <napi.h>
#include "GyeonghoRtspClient.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return GyeonghoRtspClient::Init(env, exports);
}

NODE_API_MODULE(addon, InitAll)