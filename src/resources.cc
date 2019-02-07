#include <nan.h>
#include "resources.h"
#include "lib.h"

using namespace Nan;

NAN_METHOD(ExtractContainer) {
    PWChar name = (PWChar) node::Buffer::Data(info[0]->ToObject());
    PWChar destination = (PWChar) node::Buffer::Data(info[1]->ToObject());
    WordBool replace = (WordBool) info[2]->BooleanValue();
    WordBool success = xelib.functions.ExtractContainer(name, destination, replace);
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
    PWChar folder = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PInteger len = (PInteger) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.GetContainerFiles(name, folder, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetFileContainer) {
    PWChar filePath = (PWChar) node::Buffer::Data(info[0]->ToObject());
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetFileContainer(filePath, len);
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

NAN_METHOD(BuildArchive) {
    PWChar name = (PWChar) node::Buffer::Data(info[0]->ToObject());
    PWChar folder = (PWChar) node::Buffer::Data(info[1]->ToObject());
    PWChar filePaths = (PWChar) node::Buffer::Data(info[2]->ToObject());
    Integer archiveType = info[3]->Int32Value();
    WordBool bCompress = (WordBool) info[4]->Uint32Value();
    WordBool bShare = (WordBool) info[5]->Uint32Value();
    PWChar ff = (PWChar) node::Buffer::Data(info[6]->ToObject());
    PWChar af = (PWChar) node::Buffer::Data(info[7]->ToObject());
    WordBool success = xelib.functions.BuildArchive(name, folder, filePaths, archiveType, bCompress, bShare, ff, af);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetTextureData) {
    PWChar name = (PWChar) node::Buffer::Data(info[0]->ToObject());
    PInteger width = (PInteger) node::Buffer::Data(info[1]->ToObject());
    PInteger height = (PInteger) node::Buffer::Data(info[2]->ToObject());
    WordBool success = xelib.functions.GetTextureData(name, width, height);
    info.GetReturnValue().Set(Nan::New((bool) success));
}