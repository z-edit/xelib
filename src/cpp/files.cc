#include <nan.h>
#include "files.h"
#include "lib.h"
#include "helpers.h"

using namespace Nan;

NAN_METHOD(AddFile) {
    PWChar filename = (PWChar) BufferToPointer(info[0]);
    WordBool ignoreExists(GetBool(info[1]));
    PCardinal handle = (PCardinal) BufferToPointer(info[2]);
    WordBool success = xelib.functions.AddFile(filename, ignoreExists, handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(FileByIndex) {
    Integer index = GetInt(info[0]);
    PCardinal handle = (PCardinal) BufferToPointer(info[1]);
    WordBool success = xelib.functions.FileByIndex(index, handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(FileByLoadOrder) {
    Integer loadOrder = GetInt(info[0]);
    PCardinal handle = (PCardinal) BufferToPointer(info[1]);
    WordBool success = xelib.functions.FileByLoadOrder(loadOrder, handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(FileByName) {
    PWChar filename = (PWChar) BufferToPointer(info[0]);
    PCardinal handle = (PCardinal) BufferToPointer(info[1]);
    WordBool success = xelib.functions.FileByName(filename, handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(FileByAuthor) {
    PWChar author = (PWChar) BufferToPointer(info[0]);
    PCardinal handle = (PCardinal) BufferToPointer(info[1]);
    WordBool success = xelib.functions.FileByAuthor(author, handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(NukeFile) {
    Cardinal handle = GetCardinal(info[0]);
    WordBool success = xelib.functions.NukeFile(handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(RenameFile) {
    Cardinal handle = GetCardinal(info[0]);
    PWChar filename = (PWChar) BufferToPointer(info[1]);
    WordBool success = xelib.functions.RenameFile(handle, filename);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SaveFile) {
    Cardinal handle = GetCardinal(info[0]);
    PWChar filePath = (PWChar) BufferToPointer(info[1]);
    WordBool success = xelib.functions.SaveFile(handle, filePath);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetRecordCount) {
    Cardinal handle = GetCardinal(info[0]);
    PInteger count = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetRecordCount(handle, count);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetOverrideRecordCount) {
    Cardinal handle = GetCardinal(info[0]);
    PInteger count = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetOverrideRecordCount(handle, count);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(MD5Hash) {
    Cardinal handle = GetCardinal(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.MD5Hash(handle, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(CRCHash) {
    Cardinal handle = GetCardinal(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.CRCHash(handle, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SortEditorIDs) {
    Cardinal handle = GetCardinal(info[0]);
    PWChar signature = (PWChar) BufferToPointer(info[1]);
    WordBool success = xelib.functions.SortEditorIDs(handle, signature);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SortNames) {
    Cardinal handle = GetCardinal(info[0]);
    PWChar signature = (PWChar) BufferToPointer(info[1]);
    WordBool success = xelib.functions.SortNames(handle, signature);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetFileLoadOrder) {
    Cardinal handle = GetCardinal(info[0]);
    PInteger loadOrder = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetFileLoadOrder(handle, loadOrder);
    info.GetReturnValue().Set(Nan::New((bool) success));
}