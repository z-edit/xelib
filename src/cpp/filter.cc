#include <nan.h>
#include "filter.h"
#include "lib.h"
#include "helpers.h"

using namespace Nan;

NAN_METHOD(FilterRecord) {
    if (!TestArguments(info, { atNumber })) return;
    Cardinal handle = GetCardinal(info[0]);
    WordBool success = xelib.functions.FilterRecord(handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ResetFilter) {
    WordBool success = xelib.functions.ResetFilter();
    info.GetReturnValue().Set(Nan::New((bool) success));
}