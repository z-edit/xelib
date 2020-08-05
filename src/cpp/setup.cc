#include <nan.h>
#include "meta.h"
#include "lib.h"
#include "helpers.h"

using namespace Nan;

NAN_METHOD(GetGamePath) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    int gameMode = GetInt(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetGamePath(gameMode, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetGamePath) {
    if (!TestArguments(info, { atBuffer })) return;
    PWChar gamePath = (PWChar) BufferToPointer(info[0]);
    WordBool success = xelib.functions.SetGamePath(gamePath);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetGameLanguage) {
    if (!TestArguments(info, { atNumber, atBuffer })) return;
    int gameMode = GetInt(info[0]);
    PInteger len = (PInteger) BufferToPointer(info[1]);
    WordBool success = xelib.functions.GetGameLanguage(gameMode, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetLanguage) {
    if (!TestArguments(info, { atBuffer })) return;
    PWChar language = (PWChar) BufferToPointer(info[0]);
    WordBool success = xelib.functions.SetLanguage(language);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetBackupPath) {
    if (!TestArguments(info, { atBuffer })) return;
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
    if (!TestArguments(info, { atBuffer })) return;
    PInteger len = (PInteger) BufferToPointer(info[0]);
    WordBool success = xelib.functions.GetLoadOrder(len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetActivePlugins) {
    if (!TestArguments(info, { atBuffer })) return;
    PInteger len = (PInteger) BufferToPointer(info[0]);
    WordBool success = xelib.functions.GetActivePlugins(len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(LoadPlugins) {
    if (!TestArguments(info, { atBuffer, atBool, atBool })) return;
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
    if (!TestArguments(info, { atBuffer, atBuffer })) return;
    PWChar filename = (PWChar) BufferToPointer(info[0]);
    PCardinal handle = (PCardinal) BufferToPointer(info[1]);
    WordBool success = xelib.functions.LoadPluginHeader(filename, handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(BuildReferences) {
    if (!TestArguments(info, { atNumber, atBool })) return;
    Cardinal handle = GetCardinal(info[0]);
    WordBool sync = GetBool(info[1]);
    WordBool success = xelib.functions.BuildReferences(handle, sync);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetLoaderStatus) {
    if (!TestArguments(info, { atBuffer })) return;
    PByte state = (PByte) BufferToPointer(info[0]);
    WordBool success = xelib.functions.GetLoaderStatus(state);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(UnloadPlugin) {
    if (!TestArguments(info, { atNumber })) return;
    Cardinal handle = GetCardinal(info[0]);
    WordBool success = xelib.functions.UnloadPlugin(handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}