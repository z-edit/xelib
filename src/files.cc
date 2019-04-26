#include <nan.h>
#include "files.h"
#include "lib.h"

using namespace Nan;

NAN_METHOD(AddFile) {
    PWChar filename = (PWChar) node::Buffer::Data(info[0]->ToObject());
    WordBool ignoreExists(info[1]->BooleanValue());
    PCardinal handle = (PCardinal) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.AddFile(filename, ignoreExists, handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(FileByIndex) {
    Integer index = info[0]->Int32Value();
    PCardinal handle = (PCardinal) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.FileByIndex(index, handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(FileByLoadOrder) {
    Integer loadOrder = info[0]->Int32Value();
    PCardinal handle = (PCardinal) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.FileByLoadOrder(loadOrder, handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(FileByName) {
    PWChar filename = (PWChar) node::Buffer::Data(info[0]->ToObject());
    PCardinal handle = (PCardinal) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.FileByName(filename, handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(FileByAuthor) {
    PWChar author = (PWChar) node::Buffer::Data(info[0]->ToObject());
    PCardinal handle = (PCardinal) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.FileByAuthor(author, handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(NukeFile) {
    Cardinal handle = info[0]->Uint32Value();
    WordBool success = xelib.functions.NukeFile(handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(RenameFile) {
    Cardinal handle = info[0]->Uint32Value();
    PWChar filename = (PWChar) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.RenameFile(handle, filename);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SaveFile) {
    Cardinal handle = info[0]->Uint32Value();
    PWChar filePath = (PWChar) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.SaveFile(handle, filePath);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetRecordCount) {
    Cardinal handle = info[0]->Uint32Value();
    PInteger count = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetRecordCount(handle, count);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetOverrideRecordCount) {
    Cardinal handle = info[0]->Uint32Value();
    PInteger count = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetOverrideRecordCount(handle, count);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(MD5Hash) {
    Cardinal handle = info[0]->Uint32Value();
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.MD5Hash(handle, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(CRCHash) {
    Cardinal handle = info[0]->Uint32Value();
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.CRCHash(handle, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SortEditorIDs) {
    Cardinal handle = info[0]->Uint32Value();
    PWChar signature = (PWChar) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.SortEditorIDs(handle, signature);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SortNames) {
    Cardinal handle = info[0]->Uint32Value();
    PWChar signature = (PWChar) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.SortNames(handle, signature);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetFileLoadOrder) {
    Cardinal handle = info[0]->Uint32Value();
    PInteger loadOrder = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetFileLoadOrder(handle, loadOrder);
    info.GetReturnValue().Set(Nan::New((bool) success));
}