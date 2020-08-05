#include <nan.h>
#include "meta.h"
#include "lib.h"
#include "helpers.h"

using namespace Nan;

NAN_METHOD(GetGamePath) {
    int gameMode = GetInt(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetGamePath(gameMode, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetGamePath) {
    PWChar gamePath = (PWChar) BufferToPointer(info[0]);
    WordBool success = xelib.functions.SetGamePath(gamePath);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetGameLanguage) {
    int gameMode = GetInt(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetGameLanguage(gameMode, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetLanguage) {
    PWChar language = (PWChar) BufferToPointer(info[0]);
    WordBool success = xelib.functions.SetLanguage(language);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetBackupPath) {
    PWChar backupPath = (PWChar) BufferToPointer(info[0]);
    WordBool success = xelib.functions.SetBackupPath(backupPath);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetGameMode) {
    int gameMode = GetInt(info[0]);
    WordBool success = xelib.functions.SetGameMode(gameMode);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetLoadOrder) {
    PInteger len = (PInteger) BufferToPointer(info[0]);
    WordBool success = xelib.functions.GetLoadOrder(len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetActivePlugins) {
    PInteger len = (PInteger) BufferToPointer(info[0]);
    WordBool success = xelib.functions.GetActivePlugins(len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(LoadPlugins) {
    PWChar plugins = (PWChar) BufferToPointer(info[0]);
    WordBool smartLoad(GetBool(info[1]));
    WordBool useDummies(GetBool(info[2]));
    WordBool success = xelib.functions.LoadPlugins(plugins, smartLoad, useDummies);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(LoadPlugin) {
    PWChar filename = (PWChar) BufferToPointer(info[0]);
    WordBool success = xelib.functions.LoadPlugin(filename);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(LoadPluginHeader) {
    PWChar filename = (PWChar) BufferToPointer(info[0]);
    PCardinal handle = (PCardinal) BufferToPointer(info[1]);
    WordBool success = xelib.functions.LoadPluginHeader(filename, handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(BuildReferences) {
    Cardinal handle = GetCardinal(info[0]);
    WordBool sync = GetBool(info[1]);
    WordBool success = xelib.functions.BuildReferences(handle, sync);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetLoaderStatus) {
    PByte state = (PByte) BufferToPointer(info[0]);
    WordBool success = xelib.functions.GetLoaderStatus(state);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(UnloadPlugin) {
    Cardinal handle = GetCardinal(info[0]);
    WordBool success = xelib.functions.UnloadPlugin(handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}