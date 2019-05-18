#include <nan.h>
#include "serialization.h"
#include "lib.h"

using namespace Nan;

NAN_METHOD(ElementToJson) {
    Cardinal handle = info[0]->Uint32Value();
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.ElementToJson(handle, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ElementFromJson) {
    Cardinal handle = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PWChar json = (PWChar) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.ElementFromJson(handle, path, json);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(DefToJson) {
    Cardinal handle = info[0]->Uint32Value();
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.DefToJson(handle, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}