#ifndef XELIB_MASTERS_H
#define XELIB_MASTERS_H

#include <nan.h>

// NAN METHODS
NAN_METHOD(CleanMasters);
NAN_METHOD(SortMasters);
NAN_METHOD(AddMaster);
NAN_METHOD(AddMasters);
NAN_METHOD(AddRequiredMasters);
NAN_METHOD(GetMasters);
NAN_METHOD(GetRequiredBy);
NAN_METHOD(GetMasterNames);

#endif