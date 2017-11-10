#include <nan.h>
#include "meta.h"
#include "lib.h"

using namespace Nan;

NAN_METHOD(SetGamePath) {
    PWChar gamePath = (PWChar) node::Buffer::Data(info[0]->ToObject());
    WordBool success = xelib.functions.SetGamePath(gamePath);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetLanguage) {
    PWChar language = (PWChar) node::Buffer::Data(info[0]->ToObject());
    WordBool success = xelib.functions.SetGamePath(language);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetBackupPath) {
    PWChar backupPath = (PWChar) node::Buffer::Data(info[0]->ToObject());
    WordBool success = xelib.functions.SetBackupPath(backupPath);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(SetGameMode) {
    int gameMode = info[0]->Int32Value();
    WordBool success = xelib.functions.SetGameMode(gameMode);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetGamePath) {
    int gameMode = info[0]->Int32Value();
    PInteger len = (PInteger) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.GetGamePath(gameMode, len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetLoadOrder) {
    PInteger len = (PInteger) node::Buffer::Data(info[0]->ToObject());
    WordBool success = xelib.functions.GetLoadOrder(len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetActivePlugins) {
    PInteger len = (PInteger) node::Buffer::Data(info[0]->ToObject());
    WordBool success = xelib.functions.GetActivePlugins(len);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(LoadPlugins) {
    PWChar plugins = (PWChar) node::Buffer::Data(info[0]->ToObject());
    WordBool smartLoad(info[1]->BooleanValue());
    WordBool success = xelib.functions.LoadPlugins(plugins, smartLoad);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(LoadPlugin) {
    PWChar filename = (PWChar) node::Buffer::Data(info[0]->ToObject());
    WordBool success = xelib.functions.LoadPlugin(filename);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(LoadPluginHeader) {
    PWChar filename = (PWChar) node::Buffer::Data(info[0]->ToObject());
    PCardinal handle = (PCardinal) node::Buffer::Data(info[1]->ToObject());
    WordBool success = xelib.functions.LoadPluginHeader(filename, handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(BuildReferences) {
    Cardinal handle = info[0]->Uint32Value();
    WordBool success = xelib.functions.BuildReferences(handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(GetLoaderStatus) {
    PByte state = (PByte) node::Buffer::Data(info[0]->ToObject());
    WordBool success = xelib.functions.GetLoaderStatus(state);
    info.GetReturnValue().Set(Nan::New((bool) success));
}

NAN_METHOD(UnloadPlugin) {
    Cardinal handle = info[0]->Uint32Value();
    WordBool success = xelib.functions.UnloadPlugin(handle);
    info.GetReturnValue().Set(Nan::New((bool) success));
}