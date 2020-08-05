#include <iostream>
#include "helpers.h"
#include "meta.h"
#include "lib.h"

NAN_METHOD(InitXEdit) {
    std::string libPath = GetString(info[0]);
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
    PWChar result = (PWChar) BufferToPointer(info[0]);
    Integer len = GetInt(info[1]);
    WordBool success = true;
    if (len > 0) success = xelib.functions.GetResultString(result, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetResultArray) {
    PCardinal result = (PCardinal) BufferToPointer(info[0]);
    Integer len = GetInt(info[1]);
    WordBool success = true;
    if (len > 0) success = xelib.functions.GetResultArray(result, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetResultBytes) {
    PByte result = (PByte) BufferToPointer(info[0]);
    Integer len = GetInt(info[1]);
    WordBool success = true;
    if (len > 0) success = xelib.functions.GetResultBytes(result, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetGlobal) {
    PWChar key = (PWChar) BufferToPointer(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetGlobal(key, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetGlobals) {
    PInteger len = (PInteger) BufferToPointer(info[0]);
    WordBool success = xelib.functions.GetGlobals(len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetSortMode) {
    Byte mode = (Byte) GetCardinal(info[0]);
    WordBool reverse = (WordBool) GetCardinal(info[1]);
    WordBool success = xelib.functions.SetSortMode(mode, reverse);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(Release) {
    Cardinal handle = GetCardinal(info[0]);
    WordBool success = xelib.functions.Release(handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ReleaseNodes) {
    Cardinal handle = GetCardinal(info[0]);
    WordBool success = xelib.functions.ReleaseNodes(handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(Switch) {
    Cardinal h1 = GetCardinal(info[0]);
    Cardinal h2 = GetCardinal(info[1]);
    WordBool success = xelib.functions.Switch(h1, h2);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetDuplicateHandles) {
    Cardinal handle = GetCardinal(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
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
