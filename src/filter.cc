#include <nan.h>
#include "filter.h"
#include "lib.h"

using namespace Nan;

NAN_METHOD(FilterRecord) {
    Cardinal handle = info[0]->Uint32Value();
    WordBool success = xelib.functions.FilterRecord(handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ResetFilter) {
    WordBool success = xelib.functions.ResetFilter();
    info.GetReturnValue().Set(Nan::New((bool) success));
}