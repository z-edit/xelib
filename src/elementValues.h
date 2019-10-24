#ifndef XELIB_ELEMENT_VALUES_H
#define XELIB_ELEMENT_VALUES_H

#include <nan.h>

// NAN METHODS
NAN_METHOD(Name);
NAN_METHOD(LongName);
NAN_METHOD(DisplayName);
NAN_METHOD(Path);
NAN_METHOD(PathName);
NAN_METHOD(Signature);
NAN_METHOD(GetValue);
NAN_METHOD(SetValue);
NAN_METHOD(GetIntValue);
NAN_METHOD(SetIntValue);
NAN_METHOD(GetUIntValue);
NAN_METHOD(SetUIntValue);
NAN_METHOD(GetFloatValue);
NAN_METHOD(SetFloatValue);
NAN_METHOD(GetFlag);
NAN_METHOD(SetFlag);
NAN_METHOD(GetEnabledFlags);
NAN_METHOD(SetEnabledFlags);
NAN_METHOD(GetAllFlags);
NAN_METHOD(GetEnumOptions);
NAN_METHOD(SignatureFromName);
NAN_METHOD(NameFromSignature);
NAN_METHOD(GetSignatureNameMap);

#endif
