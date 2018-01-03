#include <nan.h>
#include "elements.h"
#include "lib.h"

using namespace Nan;

NAN_METHOD(HasElement) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PWordBool _res = (PWordBool) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.HasElement(element, path, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetElement) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PCardinal _res = (PCardinal) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.GetElement(element, path, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(AddElement) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PCardinal _res = (PCardinal) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.AddElement(element, path, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(AddElementValue) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PWChar value = (PWChar) node::Buffer::Data(info[2]->ToObject());
    PCardinal _res = (PCardinal) node::Buffer::Data(info[3]->ToObject());
    WordBool success = xelib.functions.AddElementValue(element, path, value, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(RemoveElement) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.RemoveElement(element, path);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(RemoveElementOrParent) {
    Cardinal element = info[0]->Uint32Value();
    WordBool success = xelib.functions.RemoveElementOrParent(element);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetElement) {
    Cardinal e1 = info[0]->Uint32Value();
    Cardinal e2 = info[1]->Uint32Value();
    WordBool success = xelib.functions.SetElement(e1, e2);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetElements) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    WordBool sort = (WordBool) info[2]->BooleanValue();
    WordBool filter = (WordBool) info[3]->BooleanValue();
    PInteger len = (PInteger) node::Buffer::Data(info[4]->ToObject());
    WordBool success = xelib.functions.GetElements(element, path, sort, filter, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetDefNames) {
    Cardinal element = info[0]->Uint32Value();
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetDefNames(element, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetAddList) {
    Cardinal element = info[0]->Uint32Value();
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetAddList(element, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetContainer) {
    Cardinal element = info[0]->Uint32Value();
    PCardinal _res = (PCardinal) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetContainer(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetElementFile) {
    Cardinal element = info[0]->Uint32Value();
    PCardinal _res = (PCardinal) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetElementFile(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetElementGroup) {
    Cardinal element = info[0]->Uint32Value();
    PCardinal _res = (PCardinal) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetElementGroup(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetElementRecord) {
    Cardinal element = info[0]->Uint32Value();
    PCardinal _res = (PCardinal) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetElementRecord(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetLinksTo) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PCardinal _res = (PCardinal) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.GetLinksTo(element, path, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetLinksTo) {
    Cardinal e1 = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    Cardinal e2 = info[2]->Uint32Value();
    WordBool success = xelib.functions.SetLinksTo(e1, path, e2);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ElementCount) {
    Cardinal element = info[0]->Uint32Value();
    PInteger count = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.ElementCount(element, count);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ElementEquals) {
    Cardinal e1 = info[0]->Uint32Value();
    Cardinal e2 = info[1]->Uint32Value();
    PWordBool _res = (PWordBool) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.ElementEquals(e1, e2, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ElementMatches) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PWChar value = (PWChar) node::Buffer::Data(info[2]->ToObject());
    PWordBool _res = (PWordBool) node::Buffer::Data(info[3]->ToObject());
    WordBool success = xelib.functions.ElementMatches(element, path, value, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(HasArrayItem) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PWChar subpath = (PWChar) node::Buffer::Data(info[2]->ToObject());
    PWChar value = (PWChar) node::Buffer::Data(info[3]->ToObject());
    PWordBool _res = (PWordBool) node::Buffer::Data(info[4]->ToObject());
    WordBool success = xelib.functions.HasArrayItem(element, path, subpath, value, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetArrayItem) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PWChar subpath = (PWChar) node::Buffer::Data(info[2]->ToObject());
    PWChar value = (PWChar) node::Buffer::Data(info[3]->ToObject());
    PCardinal _res = (PCardinal) node::Buffer::Data(info[4]->ToObject());
    WordBool success = xelib.functions.GetArrayItem(element, path, subpath, value, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(AddArrayItem) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PWChar subpath = (PWChar) node::Buffer::Data(info[2]->ToObject());
    PWChar value = (PWChar) node::Buffer::Data(info[3]->ToObject());
    PCardinal _res = (PCardinal) node::Buffer::Data(info[4]->ToObject());
    WordBool success = xelib.functions.AddArrayItem(element, path, subpath, value, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(RemoveArrayItem) {
    Cardinal element = info[0]->Uint32Value();
    PWChar path = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PWChar subpath = (PWChar) node::Buffer::Data(info[2]->ToObject());
    PWChar value = (PWChar) node::Buffer::Data(info[3]->ToObject());
    WordBool success = xelib.functions.RemoveArrayItem(element, path, subpath, value);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(MoveArrayItem) {
    Cardinal element = info[0]->Uint32Value();
    Cardinal index = info[1]->Int32Value();
    WordBool success = xelib.functions.MoveArrayItem(element, index);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(CopyElement) {
    Cardinal e1 = info[0]->Uint32Value();
    Cardinal e2 = info[1]->Uint32Value();
    WordBool asNew = (WordBool) info[2]->BooleanValue();
    PCardinal _res = (PCardinal) node::Buffer::Data(info[3]->ToObject());
    WordBool success = xelib.functions.CopyElement(e1, e2, asNew, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(FindNextElement) {
    Cardinal element = info[0]->Uint32Value();
    PWChar search = (PWChar) node::Buffer::Data(info[1]->ToObject());
    WordBool byPath = (WordBool) info[2]->BooleanValue();
    WordBool byValue = (WordBool) info[3]->BooleanValue();
    PCardinal _res = (PCardinal) node::Buffer::Data(info[4]->ToObject());
    WordBool success = xelib.functions.FindNextElement(element, search, byPath, byValue, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(FindPreviousElement) {
    Cardinal element = info[0]->Uint32Value();
    PWChar search = (PWChar) node::Buffer::Data(info[1]->ToObject());
    WordBool byPath = (WordBool) info[2]->BooleanValue();
    WordBool byValue = (WordBool) info[3]->BooleanValue();
    PCardinal _res = (PCardinal) node::Buffer::Data(info[4]->ToObject());
    WordBool success = xelib.functions.FindPreviousElement(element, search, byPath, byValue, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetSignatureAllowed) {
    Cardinal element = info[0]->Uint32Value();
    PWChar signature = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PWordBool _res = (PWordBool) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.GetSignatureAllowed(element, signature, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetAllowedSignatures) {
    Cardinal element = info[0]->Uint32Value();
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetAllowedSignatures(element, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetIsModified) {
    Cardinal element = info[0]->Uint32Value();
    PWordBool _res = (PWordBool) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetIsModified(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetIsEditable) {
    Cardinal element = info[0]->Uint32Value();
    PWordBool _res = (PWordBool) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetIsEditable(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetIsEditable) {
    Cardinal element = info[0]->Uint32Value();
    WordBool value = info[1]->BooleanValue();
    WordBool success = xelib.functions.SetIsEditable(element, value);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetIsRemoveable) {
    Cardinal element = info[0]->Uint32Value();
    PWordBool _res = (PWordBool) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetIsRemoveable(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetCanAdd) {
    Cardinal element = info[0]->Uint32Value();
    PWordBool _res = (PWordBool) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetCanAdd(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SortKey) {
    Cardinal element = info[0]->Uint32Value();
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.SortKey(element, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ElementType) {
    Cardinal element = info[0]->Uint32Value();
    PByte _res = (PByte) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.ElementType(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(DefType) {
    Cardinal element = info[0]->Uint32Value();
    PByte _res = (PByte) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.DefType(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SmashType) {
    Cardinal element = info[0]->Uint32Value();
    PByte _res = (PByte) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.SmashType(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ValueType) {
    Cardinal element = info[0]->Uint32Value();
    PByte _res = (PByte) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.ValueType(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(IsSorted) {
    Cardinal element = info[0]->Uint32Value();
    PWordBool _res = (PWordBool) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.IsSorted(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}