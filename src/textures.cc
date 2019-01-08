#include <nan.h>
#include "textures.h"
#include "lib.h"

using namespace Nan;

NAN_METHOD(GetBitmapResource) {
    PWChar name = (PWChar) node::Buffer::Data(info[0]->ToObject());
    PInteger width = (PInteger) node::Buffer::Data(info[1]->ToObject());
    PInteger height = (PInteger) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.GetBitmapResource(name, width, height);
    info.GetReturnValue().Set(Nan::New((bool) success));
}