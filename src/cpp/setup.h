#ifndef XELIB_SETUP_H
#define XELIB_SETUP_H

#include <nan.h>

// NAN METHODS
NAN_METHOD(GetGamePath);
NAN_METHOD(SetGamePath);
NAN_METHOD(GetGameLanguage);
NAN_METHOD(SetLanguage);
NAN_METHOD(SetBackupPath);
NAN_METHOD(SetGameMode);
NAN_METHOD(GetLoadOrder);
NAN_METHOD(GetActivePlugins);
NAN_METHOD(LoadPlugins);
NAN_METHOD(LoadPlugin);
NAN_METHOD(LoadPluginHeader);
NAN_METHOD(BuildReferences);
NAN_METHOD(GetLoaderStatus);
NAN_METHOD(UnloadPlugin);

#endif