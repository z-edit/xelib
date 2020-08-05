#include <iostream>
#include "helpers.h"
#include "meta.h"
#include "lib.h"

NAN_METHOD(InitXEdit) {
    if (!TestArguments(info, { atString })) return;
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
    if (!TestArguments(info, { atBuffer, atNumber })) return;
    PWChar result = (PWChar) BufferToPointer(info[0]);
    Integer len = GetInt(info[1]);
    WordBool success = true;
    if (len > 0) success = xelib.functions.GetResultString(result, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetResultArray) {
    if (!TestArguments(info, { atBuffer, atNumber })) return;
    PCardinal result = (PCardinal) BufferToPointer(info[0]);
    Integer len = GetInt(info[1]);
    WordBool success = true;
    if (len > 0) success = xelib.functions.GetResultArray(result, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetResultBytes) {
    if (!TestArguments(info, { atBuffer, atNumber })) return;
    PByte result = (PByte) BufferToPointer(info[0]);
    Integer len = GetInt(info[1]);
    WordBool success = true;
    if (len > 0) success = xelib.functions.GetResultBytes(result, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetGlobal) {
    if (!TestArguments(info, { atBuffer, atBuffer })) return;
    PWChar key = (PWChar) BufferToPointer(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetGlobal(key, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetGlobals) {
    if (!TestArguments(info, { atBuffer, atNumber })) return;
    PInteger len = (PInteger) BufferToPointer(info[0]);
    WordBool success = xelib.functions.GetGlobals(len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetSortMode) {
    if (!TestArguments(info, { atNumber, atBool })) return;
    Byte mode = (Byte) GetCardinal(info[0]);
    WordBool reverse = (WordBool) GetBool(info[1]);
    WordBool success = xelib.functions.SetSortMode(mode, reverse);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(Release) {
    if (!TestArguments(info, { atNumber })) return;
    Cardinal handle = GetCardinal(info[0]);
    WordBool success = xelib.functions.Release(handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ReleaseNodes) {
    if (!TestArguments(info, { atNumber })) return;
    Cardinal handle = GetCardinal(info[0]);
    WordBool success = xelib.functions.ReleaseNodes(handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(Switch) {
    if (!TestArguments(info, { atNumber, atNumber })) return;
    Cardinal h1 = GetCardinal(info[0]);
    Cardinal h2 = GetCardinal(info[1]);
    WordBool success = xelib.functions.Switch(h1, h2);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetDuplicateHandles) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
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
