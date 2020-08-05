#include <nan.h>
#include <windows.h>
#include "records.h"
#include "lib.h"
#include "helpers.h"

using namespace Nan;

NAN_METHOD(GetFormID) {
    Cardinal element = GetCardinal(info[0]);
    PCardinal _res = (PCardinal) BufferToPointer(info[1]);
    WordBool native = (WordBool) GetBool(info[2]);
    WordBool success = xelib.functions.GetFormID(element, _res, native);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetFormID) {
    Cardinal element = GetCardinal(info[0]);
    Cardinal formId = GetCardinal(info[1]);
    WordBool native = (WordBool) GetBool(info[2]);
    WordBool fixRefs = (WordBool) GetBool(info[3]);
    WordBool success = xelib.functions.SetFormID(element, formId, native, fixRefs);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetRecord) {
    Cardinal element = GetCardinal(info[0]);
    Cardinal formId = GetCardinal(info[1]);
    WordBool searchMasters = (WordBool) GetBool(info[2]);
    PCardinal _res = (PCardinal) BufferToPointer(info[3]);
    WordBool success = xelib.functions.GetRecord(element, formId, searchMasters, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetRecords) {
    Cardinal element = GetCardinal(info[0]);
    PWChar search = (PWChar) BufferToPointer(info[1]);
    WordBool includeOverrides = (WordBool) GetBool(info[2]);
    PInteger len = (PInteger) BufferToPointer(info[3]);
    WordBool success = xelib.functions.GetRecords(element, search, includeOverrides, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetREFRs) {
    Cardinal element = GetCardinal(info[0]);
    PWChar search = (PWChar) BufferToPointer(info[1]);
    Cardinal flags = GetCardinal(info[2]);
    PInteger len = (PInteger) BufferToPointer(info[3]);
    WordBool success = xelib.functions.GetREFRs(element, search, flags, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetOverrides) {
    Cardinal element = GetCardinal(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetOverrides(element, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetReferencedBy) {
    Cardinal element = GetCardinal(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetReferencedBy(element, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetMasterRecord) {
    Cardinal element = GetCardinal(info[0]);
    PCardinal _res = (PCardinal) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetMasterRecord(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetPreviousOverride) {
    Cardinal e1 = GetCardinal(info[0]);
    Cardinal e2 = GetCardinal(info[1]);
    PCardinal _res = (PCardinal) BufferToPointer(info[2]);
    WordBool success = xelib.functions.GetPreviousOverride(e1, e2, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetWinningOverride) {
    Cardinal element = GetCardinal(info[0]);
    PCardinal _res = (PCardinal) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetWinningOverride(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetInjectionTarget) {
    Cardinal element = GetCardinal(info[0]);
    PCardinal _res = (PCardinal) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetInjectionTarget(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(FindNextRecord) {
    Cardinal element = GetCardinal(info[0]);
    PWChar search = (PWChar) BufferToPointer(info[1]);
    WordBool byEdid = (WordBool) GetBool(info[2]);
    WordBool byName = (WordBool) GetBool(info[3]);
    PCardinal _res = (PCardinal) BufferToPointer(info[4]);
    WordBool success = xelib.functions.FindNextRecord(element, search, byEdid, byName, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(FindPreviousRecord) {
    Cardinal element = GetCardinal(info[0]);
    PWChar search = (PWChar) BufferToPointer(info[1]);
    WordBool byEdid = (WordBool) GetBool(info[2]);
    WordBool byName = (WordBool) GetBool(info[3]);
    PCardinal _res = (PCardinal) BufferToPointer(info[4]);
    WordBool success = xelib.functions.FindPreviousRecord(element, search, byEdid, byName, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(FindValidReferences) {
    Cardinal element = GetCardinal(info[0]);
    PWChar signature = (PWChar) BufferToPointer(info[1]);
    PWChar search = (PWChar) BufferToPointer(info[2]);
    Integer limitTo = GetInt(info[3]);
    PInteger len = (PInteger) BufferToPointer(info[4]);
    WordBool success = xelib.functions.FindValidReferences(element, signature, search, limitTo, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ExchangeReferences) {
    Cardinal element = GetCardinal(info[0]);
    Cardinal oldFormId = GetCardinal(info[1]);
    Cardinal newFormId = GetCardinal(info[2]);
    WordBool success = xelib.functions.ExchangeReferences(element, oldFormId, newFormId);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(IsMaster) {
    Cardinal element = GetCardinal(info[0]);
    PWordBool _res = (PWordBool) BufferToPointer(info[1]);
    WordBool success = xelib.functions.IsMaster(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(IsInjected) {
    Cardinal element = GetCardinal(info[0]);
    PWordBool _res = (PWordBool) BufferToPointer(info[1]);
    WordBool success = xelib.functions.IsInjected(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(IsOverride) {
    Cardinal element = GetCardinal(info[0]);
    PWordBool _res = (PWordBool) BufferToPointer(info[1]);
    WordBool success = xelib.functions.IsOverride(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(IsWinningOverride) {
    Cardinal element = GetCardinal(info[0]);
    PWordBool _res = (PWordBool) BufferToPointer(info[1]);
    WordBool success = xelib.functions.IsWinningOverride(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetRecordDef) {
    PWChar sig = (PWChar) BufferToPointer(info[0]);
    PCardinal _res = (PCardinal) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetRecordDef(sig, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetNodes) {
    Cardinal element = GetCardinal(info[0]);
    PCardinal _res = (PCardinal) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetNodes(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetConflictData) {
    Cardinal e1 = GetCardinal(info[0]);
    Cardinal e2 = GetCardinal(info[1]);
    PByte _res1 = (PByte) BufferToPointer(info[2]);
    PByte _res2 = (PByte) BufferToPointer(info[3]);
    WordBool success = xelib.functions.GetConflictData(e1, e2, _res1, _res2);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetNodeElements) {
    Cardinal nodes = GetCardinal(info[0]);
    Cardinal element = GetCardinal(info[1]);
    PInteger _res = (PInteger) BufferToPointer(info[2]);
    WordBool success = xelib.functions.GetNodeElements(nodes, element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}