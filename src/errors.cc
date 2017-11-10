#include <nan.h>
#include "errors.h"
#include "lib.h"

using namespace Nan;

NAN_METHOD(CheckForErrors) {
    Cardinal handle = info[0]->Uint32Value();
    WordBool success = xelib.functions.CheckForErrors(handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetErrorThreadDone) {
    WordBool done = xelib.functions.GetErrorThreadDone();
    info.GetReturnValue().Set(Nan::New((bool) done));
}

NAN_METHOD(GetErrors) {
    PInteger len = (PInteger) node::Buffer::Data(info[0]->ToObject());
    WordBool success = xelib.functions.GetErrors(len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(RemoveIdenticalRecords) {
    Cardinal handle = info[0]->Uint32Value();
    WordBool removeITMs = (WordBool) info[1]->BooleanValue();
    WordBool removeITPOs = (WordBool) info[2]->BooleanValue();
    WordBool success = xelib.functions.RemoveIdenticalRecords(handle, removeITMs, removeITPOs);
    info.GetReturnValue().Set(Nan::New((bool) success));
}