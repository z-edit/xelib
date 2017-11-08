#include <nan.h>
#include "meta.h"
#include "lib.h"

void grs(void* info, unsigned int len) {
    if (len == 0) {
        info.GetReturnValue().Set(Nan::New(L"").ToLocalChecked());
        return;
    }
    std::wstring result;
    result.resize(len);
    xelib.functions.GetResultString(&result, len);
    info.GetReturnValue().Set(Nan::New(result).ToLocalChecked());
}

NAN_METHOD(InitXEdit) {
    xelib.functions.InitXEdit();
}

NAN_METHOD(CloseXEdit) {
    xelib.functions.CloseXEdit();
}

NAN_METHOD(GetGlobal) {
    PWChar key(info[0]->ToString());
    Cardinal len = 0;
    xelib.functions.GetGlobal(key, &len);
    grs(info, len);
}

NAN_METHOD(GetGlobals) {
    Cardinal len = 0;
    xelib.functions.GetGlobals(&len);
    grs(info, len);
}

NAN_METHOD(SetSortMode) {
    char mode = info[0]->Uint32Value();
    info.GetReturnValue().Set(xelib.functions.SetSortMode(mode));
}

NAN_METHOD(Release) {
    Cardinal handle = info[0]->Uint32Value();
    xelib.functions.Release(handle);
}

