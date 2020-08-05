#include <nan.h>
#include "meta.h"
#include "lib.h"
#include "helpers.h"

using namespace Nan;

NAN_METHOD(GetMessagesLength) {
    PInteger len = (PInteger) BufferToPointer(info[0]);
    xelib.functions.GetMessagesLength(len);
}

NAN_METHOD(GetMessages) {
    PWChar result = (PWChar) BufferToPointer(info[0]);
    Integer len = GetInt(info[1]);
    WordBool success = true;
    if (len > 0) success = xelib.functions.GetMessages(result, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ClearMessages) {
    xelib.functions.ClearMessages();
}

NAN_METHOD(GetExceptionMessageLength) {
    PInteger len = (PInteger) BufferToPointer(info[0]);
    xelib.functions.GetExceptionMessageLength(len);
}

NAN_METHOD(GetExceptionMessage) {
    PWChar result = (PWChar) BufferToPointer(info[0]);
    Integer len = GetInt(info[1]);
    WordBool success = true;
    if (len > 0) success = xelib.functions.GetExceptionMessage(result, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetExceptionStackLength) {
    PInteger len = (PInteger) BufferToPointer(info[0]);
    xelib.functions.GetExceptionStackLength(len);
}

NAN_METHOD(GetExceptionStack) {
    PWChar result = (PWChar) BufferToPointer(info[0]);
    Integer len = GetInt(info[1]);
    WordBool success = true;
    if (len > 0) success = xelib.functions.GetExceptionStack(result, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}