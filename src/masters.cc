#include <nan.h>
#include "masters.h"
#include "lib.h"

using namespace Nan;

NAN_METHOD(CleanMasters) {
    Cardinal handle = info[0]->Uint32Value();
    WordBool success = xelib.functions.CleanMasters(handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SortMasters) {
    Cardinal handle = info[0]->Uint32Value();
    WordBool success = xelib.functions.SortMasters(handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(AddMaster) {
    Cardinal handle = info[0]->Uint32Value();
    PWChar filename = (PWChar) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.AddMaster(handle, filename);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(AddMasters) {
    Cardinal handle = info[0]->Uint32Value();
    PWChar masters = (PWChar) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.AddMasters(handle, masters);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(AddRequiredMasters) {
    Cardinal h1 = info[0]->Uint32Value();
    Cardinal h2 = info[1]->Uint32Value();
    WordBool asNew(info[2]->BooleanValue());
    WordBool success = xelib.functions.AddRequiredMasters(h1, h2, asNew);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetMasters) {
    Cardinal handle = info[0]->Uint32Value();
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetMasters(handle, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetRequiredBy) {
    Cardinal handle = info[0]->Uint32Value();
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetRequiredBy(handle, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetMasterNames) {
    Cardinal handle = info[0]->Uint32Value();
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetMasterNames(handle, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}