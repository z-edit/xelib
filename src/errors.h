#ifndef XELIB_ERRORS_H
#define XELIB_ERRORS_H

#include <nan.h>

// NAN METHODS
NAN_METHOD(CheckForErrors);
NAN_METHOD(GetErrorThreadDone);
NAN_METHOD(GetErrors);
NAN_METHOD(RemoveIdenticalRecords);

#endif