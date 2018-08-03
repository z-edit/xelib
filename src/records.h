#ifndef XELIB_RECORDS_H
#define XELIB_RECORDS_H

#include <nan.h>

// NAN METHODS
NAN_METHOD(GetFormID);
NAN_METHOD(SetFormID);
NAN_METHOD(GetRecord);
NAN_METHOD(GetRecords);
NAN_METHOD(GetREFRs);
NAN_METHOD(GetOverrides);
NAN_METHOD(GetReferencedBy);
NAN_METHOD(GetMasterRecord);
NAN_METHOD(GetPreviousOverride);
NAN_METHOD(GetWinningOverride);
NAN_METHOD(FindNextRecord);
NAN_METHOD(FindPreviousRecord);
NAN_METHOD(FindValidReferences);
NAN_METHOD(ExchangeReferences);
NAN_METHOD(IsMaster);
NAN_METHOD(IsInjected);
NAN_METHOD(IsOverride);
NAN_METHOD(IsWinningOverride);
NAN_METHOD(GetNodes);
NAN_METHOD(GetConflictData);
NAN_METHOD(GetNodeElements);

#endif