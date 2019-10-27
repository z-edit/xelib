#include <nan.h>
#include <windows.h>
#include "elementValues.h"
#include "lib.h"

using namespace Nan;

NAN_METHOD(Name) {
    Cardinal element = info[0]->Uint32Value();
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.Name(element, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(LongName) {
    Cardinal element = info[0]->Uint32Value();
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.LongName(element, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(DisplayName) {
    Cardinal element = info[0]->Uint32Value();
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.DisplayName(element, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(Path) {
    Cardinal element = info[0]->Uint32Value();
    WordBool _short = (WordBool) info[1]->BooleanValue();
    WordBool local = (WordBool) info[2]->BooleanValue();
    WordBool sort = (WordBool) info[3]->BooleanValue();
    PInteger len = (PInteger) node::Buffer::Data(info[4]->ToObject());
    WordBool success = xelib.functions.Path(element, _short, local, sort, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(PathName) {
    Cardinal element = info[0]->Uint32Value();
    WordBool sort = (WordBool) info[1]->BooleanValue();
    PInteger len = (PInteger) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.PathName(element, sort, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(Signature) {
    Cardinal element = info[0]->Uint32Value();
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.Signature(element, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetValue) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PInteger len = (PInteger) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.GetValue(element, path, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetValue) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PWChar value = (PWChar) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.SetValue(element, path, value);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetIntValue) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PInteger _res = (PInteger) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.GetIntValue(element, path, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetIntValue) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    Integer value = info[2]->Int32Value();
    WordBool success = xelib.functions.SetIntValue(element, path, value);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetUIntValue) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PCardinal _res = (PCardinal) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.GetUIntValue(element, path, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetUIntValue) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    Cardinal value = info[2]->Uint32Value();
    WordBool success = xelib.functions.SetUIntValue(element, path, value);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetFloatValue) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PDouble _res = (PDouble) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.GetFloatValue(element, path, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetFloatValue) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    double value = info[2]->NumberValue();
    WordBool success = xelib.functions.SetFloatValue(element, path, value);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetFlag) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PWChar flagName = (PWChar) node::Buffer::Data(info[2]->ToObject());
    PWordBool _res = (PWordBool) node::Buffer::Data(info[3]->ToObject());
    WordBool success = xelib.functions.GetFlag(element, path, flagName, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetFlag) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PWChar flagName = (PWChar) node::Buffer::Data(info[2]->ToObject());
    WordBool state = (WordBool) info[3]->BooleanValue();
    WordBool success = xelib.functions.SetFlag(element, path, flagName, state);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetEnabledFlags) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PInteger len = (PInteger) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.GetEnabledFlags(element, path, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetEnabledFlags) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PWChar flags = (PWChar) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.SetEnabledFlags(element, path, flags);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetAllFlags) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PInteger len = (PInteger) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.GetAllFlags(element, path, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetEnumOptions) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PInteger len = (PInteger) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.GetEnumOptions(element, path, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SignatureFromName) {
    PWChar name = (PWChar) node::Buffer::Data(info[0]->ToObject());
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.SignatureFromName(name, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(NameFromSignature) {
    PWChar signature = (PWChar) node::Buffer::Data(info[0]->ToObject());
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.NameFromSignature(signature, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetSignatureNameMap) {
    PInteger len = (PInteger) node::Buffer::Data(info[0]->ToObject());
    WordBool success = xelib.functions.GetSignatureNameMap(len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}
