#ifndef __XELIB_META_H__
#define __XELIB_META_H__

#include <nan.h>

NAN_METHOD(InitXEdit);
NAN_METHOD(CloseXEdit);
NAN_METHOD(GetResultString);
NAN_METHOD(GetResultArray);
NAN_METHOD(GetGlobal);
NAN_METHOD(GetGlobals);
NAN_METHOD(SetSortMode);
NAN_METHOD(Release);
NAN_METHOD(ReleaseNodes);
NAN_METHOD(Switch);
NAN_METHOD(GetDuplicateHandles);
NAN_METHOD(CleanStore);
NAN_METHOD(ResetStore);

#endif