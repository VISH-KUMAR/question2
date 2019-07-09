#include <napi.h>
namespace functionexample {
  std::double distance();
  Napi::Number DistanceWrapped(const Napi::CallbackInfo& info);
  Napi::Object Init(Napi::Env env, Napi::Object exports);
}
