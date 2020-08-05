#include <nan.h>
#include "errors.h"
#include "lib.h"
#include "helpers.h"

using namespace Nan;

NAN_METHOD(CheckForErrors) {
    Cardinal handle = GetCardinal(info[0]);
    WordBool success = xelib.functions.CheckForErrors(handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetErrorThreadDone) {
    WordBool done = xelib.functions.GetErrorThreadDone();
    info.GetReturnValue().Set(Nan::New((bool) done));
}

NAN_METHOD(GetErrors) {
    PInteger len = (PInteger) BufferToPointer(info[0]);
    WordBool success = xelib.functions.GetErrors(len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(RemoveIdenticalRecords) {
    Cardinal handle = GetCardinal(info[0]);
    WordBool removeITMs = (WordBool) GetBool(info[1]);
    WordBool removeITPOs = (WordBool) GetBool(info[2]);
    WordBool success = xelib.functions.RemoveIdenticalRecords(handle, removeITMs, removeITPOs);
    info.GetReturnValue().Set(Nan::New((bool) success));
}