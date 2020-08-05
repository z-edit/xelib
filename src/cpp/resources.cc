#include <nan.h>
#include "resources.h"
#include "lib.h"
#include "helpers.h"

using namespace Nan;

NAN_METHOD(ExtractContainer) {
    PWChar name = (PWChar) BufferToPointer(info[0]);
    PWChar destination = (PWChar) BufferToPointer(info[1]);
    WordBool replace = (WordBool) GetBool(info[2]);
    WordBool success = xelib.functions.ExtractContainer(name, destination, replace);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ExtractFile) {
    PWChar name = (PWChar) BufferToPointer(info[0]);
    PWChar source = (PWChar) BufferToPointer(info[1]);
    PWChar destination = (PWChar) BufferToPointer(info[2]);
    WordBool success = xelib.functions.ExtractFile(name, source, destination);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetContainerFiles) {
    PWChar name = (PWChar) BufferToPointer(info[0]);
    PWChar folder = (PWChar) BufferToPointer(info[1]);
    PInteger len = (PInteger) BufferToPointer(info[2]);
    WordBool success = xelib.functions.GetContainerFiles(name, folder, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetFileContainer) {
    PWChar filePath = (PWChar) BufferToPointer(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetFileContainer(filePath, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetLoadedContainers) {
    PInteger len = (PInteger) BufferToPointer(info[0]);
    WordBool success = xelib.functions.GetLoadedContainers(len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(LoadContainer) {
    PWChar filePath = (PWChar) BufferToPointer(info[0]);
    WordBool success = xelib.functions.LoadContainer(filePath);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(BuildArchive) {
    PWChar name = (PWChar) BufferToPointer(info[0]);
    PWChar folder = (PWChar) BufferToPointer(info[1]);
    PWChar filePaths = (PWChar) BufferToPointer(info[2]);
    Integer archiveType = GetInt(info[3]);
    WordBool bCompress = (WordBool) GetCardinal(info[4]);
    WordBool bShare = (WordBool) GetCardinal(info[5]);
    PWChar ff = (PWChar) BufferToPointer(info[6]);
    PWChar af = (PWChar) BufferToPointer(info[7]);
    WordBool success = xelib.functions.BuildArchive(name, folder, filePaths, archiveType, bCompress, bShare, ff, af);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetTextureData) {
    PWChar name = (PWChar) BufferToPointer(info[0]);
    PInteger width = (PInteger) BufferToPointer(info[1]);
    PInteger height = (PInteger) BufferToPointer(info[2]);
    WordBool success = xelib.functions.GetTextureData(name, width, height);
    info.GetReturnValue().Set(Nan::New((bool) success));
}