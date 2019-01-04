#include <napi.h>

namespace modulefunction {
  std::string exor(std::string value);
  Napi::String ExorWrapped(const Napi::CallbackInfo& info);

  Napi::Object Init(Napi::Env env, Napi::Object exports);
}