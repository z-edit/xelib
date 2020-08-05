#include <nan.h>
#include <windows.h>
#include "elementValues.h"
#include "lib.h"
#include "helpers.h"

using namespace Nan;

NAN_METHOD(Name) {
    Cardinal element = GetCardinal(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.Name(element, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(LongName) {
    Cardinal element = GetCardinal(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.LongName(element, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(DisplayName) {
    Cardinal element = GetCardinal(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.DisplayName(element, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(Path) {
    Cardinal element = GetCardinal(info[0]);
    WordBool _short = (WordBool) GetBool(info[1]);
    WordBool local = (WordBool) GetBool(info[2]);
    WordBool sort = (WordBool) GetBool(info[3]);
    PInteger len = (PInteger) BufferToPointer(info[4]);
    WordBool success = xelib.functions.Path(element, _short, local, sort, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(PathName) {
    Cardinal element = GetCardinal(info[0]);
    WordBool sort = (WordBool) GetBool(info[1]);
    PInteger len = (PInteger) BufferToPointer(info[2]);
    WordBool success = xelib.functions.PathName(element, sort, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(Signature) {
    Cardinal element = GetCardinal(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.Signature(element, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetValue) {
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PInteger len = (PInteger) BufferToPointer(info[2]);
    WordBool success = xelib.functions.GetValue(element, path, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetRefValue) {
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PInteger len = (PInteger) BufferToPointer(info[2]);
    WordBool success = xelib.functions.GetRefValue(element, path, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetValue) {
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PWChar value = (PWChar) BufferToPointer(info[2]);
    WordBool success = xelib.functions.SetValue(element, path, value);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetIntValue) {
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PInteger _res = (PInteger) BufferToPointer(info[2]);
    WordBool success = xelib.functions.GetIntValue(element, path, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetIntValue) {
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    Integer value = GetInt(info[2]);
    WordBool success = xelib.functions.SetIntValue(element, path, value);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetUIntValue) {
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PCardinal _res = (PCardinal) BufferToPointer(info[2]);
    WordBool success = xelib.functions.GetUIntValue(element, path, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetUIntValue) {
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    Cardinal value = GetCardinal(info[2]);
    WordBool success = xelib.functions.SetUIntValue(element, path, value);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetFloatValue) {
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PDouble _res = (PDouble) BufferToPointer(info[2]);
    WordBool success = xelib.functions.GetFloatValue(element, path, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetFloatValue) {
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    double value = GetDouble(info[2]);
    WordBool success = xelib.functions.SetFloatValue(element, path, value);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetFlag) {
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PWChar flagName = (PWChar) BufferToPointer(info[2]);
    PWordBool _res = (PWordBool) BufferToPointer(info[3]);
    WordBool success = xelib.functions.GetFlag(element, path, flagName, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetFlag) {
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PWChar flagName = (PWChar) BufferToPointer(info[2]);
    WordBool state = (WordBool) GetBool(info[3]);
    WordBool success = xelib.functions.SetFlag(element, path, flagName, state);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetEnabledFlags) {
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PInteger len = (PInteger) BufferToPointer(info[2]);
    WordBool success = xelib.functions.GetEnabledFlags(element, path, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetEnabledFlags) {
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PWChar flags = (PWChar) BufferToPointer(info[2]);
    WordBool success = xelib.functions.SetEnabledFlags(element, path, flags);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetAllFlags) {
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PInteger len = (PInteger) BufferToPointer(info[2]);
    WordBool success = xelib.functions.GetAllFlags(element, path, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetEnumOptions) {
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PInteger len = (PInteger) BufferToPointer(info[2]);
    WordBool success = xelib.functions.GetEnumOptions(element, path, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SignatureFromName) {
    PWChar name = (PWChar) BufferToPointer(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.SignatureFromName(name, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(NameFromSignature) {
    PWChar signature = (PWChar) BufferToPointer(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.NameFromSignature(signature, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetSignatureNameMap) {
    PInteger len = (PInteger) BufferToPointer(info[0]);
    WordBool success = xelib.functions.GetSignatureNameMap(len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}
