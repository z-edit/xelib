#include <nan.h>
#include <sstream>
#include "elements.h"
#include "helpers.h"
#include "lib.h"

NAN_METHOD(HasElement) {
    if (!TestArguments(info, { atNumber, atBuffer, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PWordBool _res = (PWordBool) BufferToPointer(info[2]);
    WordBool success = xelib.functions.HasElement(element, path, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetElement) {
    if (!TestArguments(info, { atNumber, atBuffer, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar)BufferToPointer(info[1]);
    PCardinal _res = (PCardinal)BufferToPointer(info[2]);
    WordBool success = xelib.functions.GetElement(element, path, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(AddElement) {
    if (!TestArguments(info, { atNumber, atBuffer, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PCardinal _res = (PCardinal) BufferToPointer(info[2]);
    WordBool success = xelib.functions.AddElement(element, path, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(AddElementValue) {
    if (!TestArguments(info, { atNumber, atBuffer, atBuffer, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PWChar value = (PWChar) BufferToPointer(info[2]);
    PCardinal _res = (PCardinal) BufferToPointer(info[3]);
    WordBool success = xelib.functions.AddElementValue(element, path, value, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(RemoveElement) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    WordBool success = xelib.functions.RemoveElement(element, path);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(RemoveElementOrParent) {
    if (!TestArguments(info, { atNumber })) return;
    Cardinal element = GetCardinal(info[0]);
    WordBool success = xelib.functions.RemoveElementOrParent(element);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetElement) {
    if (!TestArguments(info, { atNumber, atNumber })) return;
    Cardinal e1 = GetCardinal(info[0]);
    Cardinal e2 = GetCardinal(info[1]);
    WordBool success = xelib.functions.SetElement(e1, e2);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetElements) {
    if (!TestArguments(info, { atNumber, atBuffer, atBool, atBool, atBool, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    WordBool sort = (WordBool) GetBool(info[2]);
    WordBool filter = (WordBool) GetBool(info[3]);
    WordBool sparse = (WordBool) GetBool(info[4]);
    PInteger len = (PInteger) BufferToPointer(info[5]);
    WordBool success = xelib.functions.GetElements(element, path, sort, filter, sparse, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetDefNames) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetDefNames(element, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetAddList) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetAddList(element, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetContainer) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PCardinal _res = (PCardinal) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetContainer(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetElementFile) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PCardinal _res = (PCardinal) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetElementFile(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetElementGroup) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PCardinal _res = (PCardinal) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetElementGroup(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetElementRecord) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PCardinal _res = (PCardinal) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetElementRecord(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetLinksTo) {
    if (!TestArguments(info, { atNumber, atBuffer, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PCardinal _res = (PCardinal) BufferToPointer(info[2]);
    WordBool success = xelib.functions.GetLinksTo(element, path, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetLinksTo) {
    if (!TestArguments(info, { atNumber, atBuffer, atNumber })) return;
    Cardinal e1 = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    Cardinal e2 = GetCardinal(info[2]);
    WordBool success = xelib.functions.SetLinksTo(e1, path, e2);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ElementCount) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PInteger count = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.ElementCount(element, count);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ElementEquals) {
    if (!TestArguments(info, { atNumber, atNumber, atBuffer })) return;
    Cardinal e1 = GetCardinal(info[0]);
    Cardinal e2 = GetCardinal(info[1]);
    PWordBool _res = (PWordBool) BufferToPointer(info[2]);
    WordBool success = xelib.functions.ElementEquals(e1, e2, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ElementMatches) {
    if (!TestArguments(info, { atNumber, atBuffer, atBuffer, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PWChar value = (PWChar) BufferToPointer(info[2]);
    PWordBool _res = (PWordBool) BufferToPointer(info[3]);
    WordBool success = xelib.functions.ElementMatches(element, path, value, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(HasArrayItem) {
    if (!TestArguments(info, { atNumber, atBuffer, atBuffer, atBuffer, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PWChar subpath = (PWChar) BufferToPointer(info[2]);
    PWChar value = (PWChar) BufferToPointer(info[3]);
    PWordBool _res = (PWordBool) BufferToPointer(info[4]);
    WordBool success = xelib.functions.HasArrayItem(element, path, subpath, value, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetArrayItem) {
    if (!TestArguments(info, { atNumber, atBuffer, atBuffer, atBuffer, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PWChar subpath = (PWChar) BufferToPointer(info[2]);
    PWChar value = (PWChar) BufferToPointer(info[3]);
    PCardinal _res = (PCardinal) BufferToPointer(info[4]);
    WordBool success = xelib.functions.GetArrayItem(element, path, subpath, value, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(AddArrayItem) {
    if (!TestArguments(info, { atNumber, atBuffer, atBuffer, atBuffer, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PWChar subpath = (PWChar) BufferToPointer(info[2]);
    PWChar value = (PWChar) BufferToPointer(info[3]);
    PCardinal _res = (PCardinal) BufferToPointer(info[4]);
    WordBool success = xelib.functions.AddArrayItem(element, path, subpath, value, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(RemoveArrayItem) {
    if (!TestArguments(info, { atNumber, atBuffer, atBuffer, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PWChar path = (PWChar) BufferToPointer(info[1]);
    PWChar subpath = (PWChar) BufferToPointer(info[2]);
    PWChar value = (PWChar) BufferToPointer(info[3]);
    WordBool success = xelib.functions.RemoveArrayItem(element, path, subpath, value);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(MoveArrayItem) {
    if (!TestArguments(info, { atNumber, atNumber })) return;
    Cardinal element = GetCardinal(info[0]);
    Cardinal index = GetCardinal(info[1]);
    WordBool success = xelib.functions.MoveArrayItem(element, index);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(CopyElement) {
    if (!TestArguments(info, { atNumber, atNumber })) return;
    Cardinal e1 = GetCardinal(info[0]);
    Cardinal e2 = GetCardinal(info[1]);
    WordBool asNew = (WordBool) GetBool(info[2]);
    PCardinal _res = (PCardinal) BufferToPointer(info[3]);
    WordBool success = xelib.functions.CopyElement(e1, e2, asNew, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(FindNextElement) {
    if (!TestArguments(info, { atNumber, atBuffer, atBool, atBool, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PWChar search = (PWChar) BufferToPointer(info[1]);
    WordBool byPath = (WordBool) GetBool(info[2]);
    WordBool byValue = (WordBool) GetBool(info[3]);
    PCardinal _res = (PCardinal) BufferToPointer(info[4]);
    WordBool success = xelib.functions.FindNextElement(element, search, byPath, byValue, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(FindPreviousElement) {
    if (!TestArguments(info, { atNumber, atBuffer, atBool, atBool, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PWChar search = (PWChar) BufferToPointer(info[1]);
    WordBool byPath = (WordBool) GetBool(info[2]);
    WordBool byValue = (WordBool) GetBool(info[3]);
    PCardinal _res = (PCardinal) BufferToPointer(info[4]);
    WordBool success = xelib.functions.FindPreviousElement(element, search, byPath, byValue, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetSignatureAllowed) {
    if (!TestArguments(info, { atNumber, atBuffer, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PWChar signature = (PWChar) BufferToPointer(info[1]);
    PWordBool _res = (PWordBool) BufferToPointer(info[2]);
    WordBool success = xelib.functions.GetSignatureAllowed(element, signature, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetAllowedSignatures) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetAllowedSignatures(element, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetIsModified) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PWordBool _res = (PWordBool) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetIsModified(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetIsEditable) {
    Cardinal element = GetCardinal(info[0]);
    PWordBool _res = (PWordBool) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetIsEditable(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetIsEditable) {
    if (!TestArguments(info, { atNumber, atBool })) return;
    Cardinal element = GetCardinal(info[0]);
    WordBool value = GetBool(info[1]);
    WordBool success = xelib.functions.SetIsEditable(element, value);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetIsRemoveable) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PWordBool _res = (PWordBool) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetIsRemoveable(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetCanAdd) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PWordBool _res = (PWordBool) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetCanAdd(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SortKey) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.SortKey(element, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ElementType) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PByte _res = (PByte) BufferToPointer(info[1]);
    WordBool success = xelib.functions.ElementType(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(DefType) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PByte _res = (PByte) BufferToPointer(info[1]);
    WordBool success = xelib.functions.DefType(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SmashType) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PByte _res = (PByte) BufferToPointer(info[1]);
    WordBool success = xelib.functions.SmashType(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ValueType) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PByte _res = (PByte) BufferToPointer(info[1]);
    WordBool success = xelib.functions.ValueType(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(IsSorted) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PWordBool _res = (PWordBool) BufferToPointer(info[1]);
    WordBool success = xelib.functions.IsSorted(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(IsFixed) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    Cardinal element = GetCardinal(info[0]);
    PWordBool _res = (PWordBool) BufferToPointer(info[1]);
    WordBool success = xelib.functions.IsFixed(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}