#include <node.h>
#include "meta.h"

using v8::FunctionTemplate;

// This represents the top level of the module.
// C++ constructs that are exposed to javascript are exported here

NAN_MODULE_INIT(InitAll) {
  Nan::Set(target, Nan::New("InitXEdit").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(InitXEdit)).ToLocalChecked());
  Nan::Set(target, Nan::New("CloseXEdit").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(CloseXEdit)).ToLocalChecked());
  Nan::Set(target, Nan::New("GetResultString").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(GetResultString)).ToLocalChecked());
  Nan::Set(target, Nan::New("GetGlobal").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(GetGlobal)).ToLocalChecked());
  Nan::Set(target, Nan::New("GetGlobals").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(GetGlobals)).ToLocalChecked());
  Nan::Set(target, Nan::New("SetSortMode").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(SetSortMode)).ToLocalChecked());
  Nan::Set(target, Nan::New("Release").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(Release)).ToLocalChecked());
}

NODE_MODULE(xelib, InitAll)
