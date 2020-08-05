#include <nan.h>
#include "resources.h"
#include "lib.h"
#include "helpers.h"

using namespace Nan;

NAN_METHOD(ExtractContainer) {
    if (!TestArguments(info, { atBuffer, atBuffer, atBool })) return;
    PWChar name = (PWChar) BufferToPointer(info[0]);
    PWChar destination = (PWChar) BufferToPointer(info[1]);
    WordBool replace = (WordBool) GetBool(info[2]);
    WordBool success = xelib.functions.ExtractContainer(name, destination, replace);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(ExtractFile) {
    if (!TestArguments(info, { atBuffer, atBuffer, atBuffer })) return;
    PWChar name = (PWChar) BufferToPointer(info[0]);
    PWChar source = (PWChar) BufferToPointer(info[1]);
    PWChar destination = (PWChar) BufferToPointer(info[2]);
    WordBool success = xelib.functions.ExtractFile(name, source, destination);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetContainerFiles) {
    if (!TestArguments(info, { atBuffer, atBuffer, atBuffer })) return;
    PWChar name = (PWChar) BufferToPointer(info[0]);
    PWChar folder = (PWChar) BufferToPointer(info[1]);
    PInteger len = (PInteger) BufferToPointer(info[2]);
    WordBool success = xelib.functions.GetContainerFiles(name, folder, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetFileContainer) {
    if (!TestArguments(info, { atBuffer, atBuffer })) return;
    PWChar filePath = (PWChar) BufferToPointer(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetFileContainer(filePath, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetLoadedContainers) {
    if (!TestArguments(info, { atBuffer })) return;
    PInteger len = (PInteger) BufferToPointer(info[0]);
    WordBool success = xelib.functions.GetLoadedContainers(len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(LoadContainer) {
    if (!TestArguments(info, { atBuffer })) return;
    PWChar filePath = (PWChar) BufferToPointer(info[0]);
    WordBool success = xelib.functions.LoadContainer(filePath);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(BuildArchive) {
    if (!TestArguments(info, { 
            atBuffer, atBuffer, atBuffer, atNumber, 
            atBool, atBool, atBuffer, atBuffer 
        })) return;
    PWChar name = (PWChar) BufferToPointer(info[0]);
    PWChar folder = (PWChar) BufferToPointer(info[1]);
    PWChar filePaths = (PWChar) BufferToPointer(info[2]);
    Integer archiveType = GetInt(info[3]);
    WordBool bCompress = (WordBool) GetBool(info[4]);
    WordBool bShare = (WordBool) GetBool(info[5]);
    PWChar ff = (PWChar) BufferToPointer(info[6]);
    PWChar af = (PWChar) BufferToPointer(info[7]);
    WordBool success = xelib.functions.BuildArchive(name, folder, filePaths, archiveType, bCompress, bShare, ff, af);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetTextureData) {
    if (!TestArguments(info, { atBuffer, atBuffer, atBuffer })) return;
    PWChar name = (PWChar) BufferToPointer(info[0]);
    PInteger width = (PInteger) BufferToPointer(info[1]);
    PInteger height = (PInteger) BufferToPointer(info[2]);
    WordBool success = xelib.functions.GetTextureData(name, width, height);
    info.GetReturnValue().Set(Nan::New((bool) success));
}