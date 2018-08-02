#include <nan.h>
#include <windows.h>
#include "records.h"
#include "lib.h"

using namespace Nan;

NAN_METHOD(GetFormID) {
    Cardinal element = info[0]->Uint32Value();
    PCardinal _res = (PCardinal) node::Buffer::Data(info[1]->ToObject());
    WordBool native = (WordBool) info[2]->BooleanValue();
    WordBool success = xelib.functions.GetFormID(element, _res, native);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetFormID) {
    Cardinal element = info[0]->Uint32Value();
    Cardinal formId = info[1]->Uint32Value();
    WordBool native = (WordBool) info[2]->BooleanValue();
    WordBool fixRefs = (WordBool) info[3]->BooleanValue();
    WordBool success = xelib.functions.SetFormID(element, formId, native, fixRefs);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetRecord) {
    Cardinal element = info[0]->Uint32Value();
    Cardinal formId = info[1]->Uint32Value();
    PCardinal _res = (PCardinal) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.GetRecord(element, formId, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetRecords) {
    Cardinal element = info[0]->Uint32Value();
    PWChar search = (PWChar) node::Buffer::Data(info[1]->ToObject());
    WordBool includeOverrides = (WordBool) info[2]->BooleanValue();
    PInteger len = (PInteger) node::Buffer::Data(info[3]->ToObject());
    WordBool success = xelib.functions.GetRecords(element, search, includeOverrides, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetRecordsByRef) {
    Cardinal element = info[0]->Uint32Value();
    PWChar search = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PWChar path = (PWChar) node::Buffer::Data(info[2]->ToObject());
    PWChar target = (PWChar) node::Buffer::Data(info[3]->ToObject());
    WordBool includeOverrides = (WordBool) info[4]->BooleanValue();
    PInteger len = (PInteger) node::Buffer::Data(info[5]->ToObject());
    WordBool success = xelib.functions.GetRecordsByRef(element, search, path, target, includeOverrides, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetOverrides) {
    Cardinal element = info[0]->Uint32Value();
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetOverrides(element, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetReferencedBy) {
    Cardinal element = info[0]->Uint32Value();
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetReferencedBy(element, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetMasterRecord) {
    Cardinal element = info[0]->Uint32Value();
    PCardinal _res = (PCardinal) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetMasterRecord(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetPreviousOverride) {
    Cardinal e1 = info[0]->Uint32Value();
    Cardinal e2 = info[1]->Uint32Value();
    PCardinal _res = (PCardinal) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.GetPreviousOverride(e1, e2, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetWinningOverride) {
    Cardinal element = info[0]->Uint32Value();
    PCardinal _res = (PCardinal) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetWinningOverride(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(FindNextRecord) {
    Cardinal element = info[0]->Uint32Value();
    PWChar search = (PWChar) node::Buffer::Data(info[1]->ToObject());
    WordBool byEdid = (WordBool) info[2]->BooleanValue();
    WordBool byName = (WordBool) info[3]->BooleanValue();
    PCardinal _res = (PCardinal) node::Buffer::Data(info[4]->ToObject());
    WordBool success = xelib.functions.FindNextRecord(element, search, byEdid, byName, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(FindPreviousRecord) {
    Cardinal element = info[0]->Uint32Value();
    PWChar search = (PWChar) node::Buffer::Data(info[1]->ToObject());
    WordBool byEdid = (WordBool) info[2]->BooleanValue();
    WordBool byName = (WordBool) info[3]->BooleanValue();
    PCardinal _res = (PCardinal) node::Buffer::Data(info[4]->ToObject());
    WordBool success = xelib.functions.FindPreviousRecord(element, search, byEdid, byName, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(FindValidReferences) {
    Cardinal element = info[0]->Uint32Value();
    PWChar signature = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PWChar search = (PWChar) node::Buffer::Data(info[2]->ToObject());
    Integer limitTo = info[3]->Int32Value();
    PInteger len = (PInteger) node::Buffer::Data(info[4]->ToObject());
    WordBool success = xelib.functions.FindValidReferences(element, signature, search, limitTo, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ExchangeReferences) {
    Cardinal element = info[0]->Uint32Value();
    Cardinal oldFormId = info[1]->Uint32Value();
    Cardinal newFormId = info[2]->Uint32Value();
    WordBool success = xelib.functions.ExchangeReferences(element, oldFormId, newFormId);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(IsMaster) {
    Cardinal element = info[0]->Uint32Value();
    PWordBool _res = (PWordBool) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.IsMaster(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(IsInjected) {
    Cardinal element = info[0]->Uint32Value();
    PWordBool _res = (PWordBool) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.IsInjected(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(IsOverride) {
    Cardinal element = info[0]->Uint32Value();
    PWordBool _res = (PWordBool) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.IsOverride(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(IsWinningOverride) {
    Cardinal element = info[0]->Uint32Value();
    PWordBool _res = (PWordBool) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.IsWinningOverride(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetNodes) {
    Cardinal element = info[0]->Uint32Value();
    PCardinal _res = (PCardinal) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetNodes(element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetConflictData) {
    Cardinal e1 = info[0]->Uint32Value();
    Cardinal e2 = info[1]->Uint32Value();
    PByte _res1 = (PByte) node::Buffer::Data(info[2]->ToObject());
    PByte _res2 = (PByte) node::Buffer::Data(info[3]->ToObject());
    WordBool success = xelib.functions.GetConflictData(e1, e2, _res1, _res2);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetNodeElements) {
    Cardinal nodes = info[0]->Uint32Value();
    Cardinal element = info[1]->Uint32Value();
    PInteger _res = (PInteger) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.GetNodeElements(nodes, element, _res);
    info.GetReturnValue().Set(Nan::New((bool) success));
}