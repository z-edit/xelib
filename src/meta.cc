#include <nan.h>
#include <iostream>
#include "meta.h"
#include "lib.h"

using namespace Nan;

NAN_METHOD(InitXEdit) {
    std::string libPath(*Nan::Utf8String(info[0]->ToString()));
    if (load(libPath) != EXIT_FAILURE) {
        try {
            xelib.functions.InitXEdit();
        } catch (...) {
            log("Unknown exception");
        }
    }
}

NAN_METHOD(CloseXEdit) {
    xelib.functions.CloseXEdit();
    FreeLibrary(XEditLib);
    XEditLib = NULL;
}

NAN_METHOD(GetResultString) {
    PWChar result = (PWChar) node::Buffer::Data(info[0]->ToObject());
    Integer len = info[1]->Int32Value();
    WordBool success = true;
    if (len > 0) success = xelib.functions.GetResultString(result, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetResultArray) {
    PCardinal result = (PCardinal) node::Buffer::Data(info[0]->ToObject());
    Integer len = info[1]->Int32Value();
    WordBool success = true;
    if (len > 0) success = xelib.functions.GetResultArray(result, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetResultBytes) {
    PByte result = (PByte) node::Buffer::Data(info[0]->ToObject());
    Integer len = info[1]->Int32Value();
    WordBool success = true;
    if (len > 0) success = xelib.functions.GetResultBytes(result, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
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

NAN_METHOD(ReleaseNodes) {
    Cardinal handle = info[0]->Uint32Value();
    WordBool success = xelib.functions.ReleaseNodes(handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(Switch) {
    Cardinal h1 = info[0]->Uint32Value();
    Cardinal h2 = info[1]->Uint32Value();
    WordBool success = xelib.functions.Switch(h1, h2);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetDuplicateHandles) {
    Cardinal handle = info[0]->Uint32Value();
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetDuplicateHandles(handle, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(CleanStore) {
    WordBool success = xelib.functions.CleanStore();
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ResetStore) {
    WordBool success = xelib.functions.ResetStore();
    info.GetReturnValue().Set(Nan::New((bool) success));
}
