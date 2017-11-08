#include <nan.h>
#include "lib.h"

using namespace Nan;
using namespace v8;

NAN_METHOD(InitXEdit) {
    xelib.functions.InitXEdit();
}

NAN_METHOD(CloseXEdit) {
    xelib.functions.CloseXEdit();
}

NAN_METHOD(GetGlobal) {
    PWChar key = (PWChar) node::Buffer::Data(info[0]->ToObject());
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetGlobal(key, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetGlobals) {
    PInteger len = (PInteger) node::Buffer::Data(info[0]->ToObject());
    WordBool success = xelib.functions.GetGlobals(len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetSortMode) {
    Byte mode = (Byte) info[0]->Uint32Value();
    WordBool reverse = (WordBool) info[1]->Uint32Value();
    WordBool success = xelib.functions.SetSortMode(mode, reverse);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(Release) {
    Cardinal handle = info[0]->Uint32Value();
    WordBool success = xelib.functions.Release(handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetResultString) {
    PWChar result = (PWChar) node::Buffer::Data(info[0]->ToObject());
    int len(info[1]->Int32Value());
    WordBool success = true;
    if (len > 0) {
        success = xelib.functions.GetResultString(result, len);
    }
    info.GetReturnValue().Set(Nan::New((bool) success));
}
