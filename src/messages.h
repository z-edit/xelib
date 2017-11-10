#ifndef XELIB_MESSAGES_H
#define XELIB_MESSAGES_H

#include <nan.h>

// NAN METHODS
NAN_METHOD(GetMessagesLength);
NAN_METHOD(GetMessages);
NAN_METHOD(ClearMessages);
NAN_METHOD(GetExceptionMessageLength);
NAN_METHOD(GetExceptionMessage);

#endif