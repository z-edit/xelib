#include <nan.h>
#include "masters.h"
#include "lib.h"
#include "helpers.h"

using namespace Nan;

NAN_METHOD(CleanMasters) {
    Cardinal handle = GetCardinal(info[0]);
    WordBool success = xelib.functions.CleanMasters(handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SortMasters) {
    Cardinal handle = GetCardinal(info[0]);
    WordBool success = xelib.functions.SortMasters(handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(AddMaster) {
    Cardinal handle = GetCardinal(info[0]);
    PWChar filename = (PWChar) BufferToPointer(info[1]);
    WordBool success = xelib.functions.AddMaster(handle, filename);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(AddMasters) {
    Cardinal handle = GetCardinal(info[0]);
    PWChar masters = (PWChar) BufferToPointer(info[1]);
    WordBool success = xelib.functions.AddMasters(handle, masters);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(AddRequiredMasters) {
    Cardinal h1 = GetCardinal(info[0]);
    Cardinal h2 = GetCardinal(info[1]);
    WordBool asNew(GetBool(info[2]));
    WordBool success = xelib.functions.AddRequiredMasters(h1, h2, asNew);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetMasters) {
    Cardinal handle = GetCardinal(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetMasters(handle, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetRequiredBy) {
    Cardinal handle = GetCardinal(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetRequiredBy(handle, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetMasterNames) {
    Cardinal handle = GetCardinal(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetMasterNames(handle, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}