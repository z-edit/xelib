#ifndef XELIB_META_H
#define XELIB_META_H

#include <nan.h>

// NAN METHODS
NAN_METHOD(InitXEdit);
NAN_METHOD(CloseXEdit);
NAN_METHOD(GetGlobal);
NAN_METHOD(GetGlobals);
NAN_METHOD(SetSortMode);
NAN_METHOD(Release);
//NAN_METHOD(ReleaseNodes);
//NAN_METHOD(Switch);
//NAN_METHOD(GetDuplicateHandles);
//NAN_METHOD(ResetStore);

#endif