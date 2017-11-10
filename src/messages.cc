#include <nan.h>
#include "meta.h"
#include "lib.h"

using namespace Nan;

NAN_METHOD(GetMessagesLength) {
    PInteger len = (PInteger) node::Buffer::Data(info[0]->ToObject());
    xelib.functions.GetMessagesLength(len);
}

NAN_METHOD(GetMessages) {
    PWChar result = (PWChar) node::Buffer::Data(info[0]->ToObject());
    Integer len = info[1]->Int32Value();
    WordBool success = true;
    if (len > 0) success = xelib.functions.GetMessages(result, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ClearMessages) {
    xelib.functions.ClearMessages();
}

NAN_METHOD(GetExceptionMessageLength) {
    PInteger len = (PInteger) node::Buffer::Data(info[0]->ToObject());
    xelib.functions.GetExceptionMessageLength(len);
}

NAN_METHOD(GetExceptionMessage) {
    PWChar result = (PWChar) node::Buffer::Data(info[0]->ToObject());
    Integer len = info[1]->Int32Value();
    WordBool success = true;
    if (len > 0) success = xelib.functions.GetExceptionMessage(result, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}