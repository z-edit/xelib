#include <nan.h>
#include "archives.h"
#include "lib.h"

using namespace Nan;

NAN_METHOD(ExtractContainer) {
    PWChar name = (PWChar) node::Buffer::Data(info[0]->ToObject());
    PWChar destination = (PWChar) node::Buffer::Data(info[1]->ToObject());
    WordBool replace = (WordBool) info[2]->BooleanValue();
    WordBool success = xelib.functions.ExtractContainer(name, path, replace);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ExtractFile) {
    PWChar name = (PWChar) node::Buffer::Data(info[0]->ToObject());
    PWChar source = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PWChar destination = (PWChar) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.ExtractFile(name, source, destination);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetContainerFiles) {
    PWChar name = (PWChar) node::Buffer::Data(info[0]->ToObject());
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetContainerFiles(name, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetLoadedContainers) {
    PInteger len = (PInteger) node::Buffer::Data(info[0]->ToObject());
    WordBool success = xelib.functions.GetLoadedContainers(len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(LoadContainer) {
    PWChar filePath = (PWChar) node::Buffer::Data(info[0]->ToObject());
    WordBool success = xelib.functions.LoadContainer(filePath);
    info.GetReturnValue().Set(Nan::New((bool) success));
}