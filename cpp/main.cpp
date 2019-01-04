
/* cppsrc/main.cpp */
#include <napi.h>
#include "module/modulefunction.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return modulefunction::Init(env, exports);
}

NODE_API_MODULE(nodeNativeXor, InitAll)