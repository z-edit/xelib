#ifndef XELIB_LIB_H
#define XELIB_LIB_H

// DELPHI TYPES
typedef unsigned short WordBool;
typedef WordBool* PWordBool;
typedef unsigned long Cardinal;
typedef Cardinal* PCardinal;
typedef unsigned char Byte;
typedef Byte* PByte;
typedef signed long Integer;
typedef Integer* PInteger;
typedef wchar_t* PWChar;

// function declaration
const int NUM_FUNCTIONS = 30; // 139
typedef int (__cdecl* func_ptr_t)();
func_ptr_t function_pointers [NUM_FUNCTIONS];

const char* FUNCTION_NAMES [NUM_FUNCTIONS] = {
    // META METHODS
    "InitXEdit", "CloseXEdit", "GetResultString", "GetResultArray", "GetGlobal", "GetGlobals",
    "SetSortMode", "Release", "ReleaseNodes", "Switch", "GetDuplicateHandles", "ResetStore",
    // MESSAGE METHODS
    "GetMessagesLength", "GetMessages", "ClearMessages", "GetExceptionMessageLength",
    "GetExceptionMessage",
    // LOADING AND SET UP METHODS
    "GetGamePath", "SetGamePath", "SetLanguage", "SetBackupPath", "SetGameMode", "GetLoadOrder",
    "GetActivePlugins", "LoadPlugins", "LoadPlugin", "LoadPluginHeader", "BuildReferences",
    "GetLoaderStatus", "UnloadPlugin",
    // FILE HANDLING METHODS
    /*"AddFile", "FileByIndex", "FileByLoadOrder", "FileByName", "FileByAuthor", "NukeFile",
    "RenameFile", "SaveFile", "GetRecordCount", "GetOverrideRecordCount", "MD5Hash", "CRCHash",
    "SortEditorIDs", "SortNames", "GetFileLoadOrder",
    // MASTER HANDLING METHODS
    "CleanMasters", "SortMasters", "AddMaster", "AddMasters", "AddRequiredMasters", "GetMasters",
    "GetRequiredBy", "GetMasterNames",
    // ELEMENT HANDLING METHODS
    "HasElement", "GetElement", "AddElement", "AddElementValue", "RemoveElement",
    "RemoveElementOrParent", "SetElement", "GetElements", "GetDefNames", "GetAddList",
    "GetContainer", "GetElementFile", "GetElementRecord", "GetLinksTo", "SetLinksTo",
    "ElementCount", "ElementEquals", "ElementMatches", "HasArrayItem", "GetArrayItem",
    "AddArrayItem", "RemoveArrayItem", "MoveArrayItem", "CopyElement", "FindNextElement",
    "FindPreviousElement", "GetSignatureAllowed", "GetAllowedSignatures", "GetIsModified",
    "GetIsEditable", "GetIsRemoveable", "GetCanAdd", "SortKey", "ElementType", "DefType",
    "SmashType", "ValueType", "IsSorted",
    // PLUGIN ERROR METHODS
    "CheckForErrors", "GetErrorThreadDone", "GetErrors", "RemoveIdenticalRecords",
    // SERIALIZATION METHODS
    "ElementToJson", "ElementFromJson",
    // ELEMENT VALUE METHODS
    "Name", "LongName", "DisplayName", "Path", "Signature", "GetValue", "SetValue", "GetIntValue",
    "SetIntValue", "GetUIntValue", "SetUIntValue", "GetFloatValue", "SetFloatValue",
    "GetFlag", "SetFlag", "GetEnabledFlags", "SetEnabledFlags", "GetAllFlags", "GetEnumOptions",
    "SignatureFromName", "NameFromSignature", "GetSignatureNameMap",
    // RECORD HANDLING METHODS
    "GetFormID", "SetFormID", "GetRecord", "GetRecords", "GetOverrides", "GetReferencedBy",
    "GetMasterRecord", "GetPreviousOverride", "GetWinningOverride", "FindNextRecord",
    "FindPreviousRecord", "FindValidReferences", "ExchangeReferences", "IsMaster", "IsInjected",
    "IsOverride", "IsWinningOverride", "GetNodes", "GetConflictData", "GetNodeElements"*/
};

typedef struct {
    // META METHODS
    void  (__cdecl* InitXEdit)();
    void  (__cdecl* CloseXEdit)();
    WordBool  (__cdecl* GetResultString)(PWChar, Integer);
    WordBool  (__cdecl* GetResultArray)(PCardinal, Integer);
    WordBool  (__cdecl* GetGlobal)(PWChar, PInteger);
    WordBool  (__cdecl* GetGlobals)(PInteger);
    WordBool  (__cdecl* SetSortMode)(Byte, WordBool);
    WordBool  (__cdecl* Release)(Cardinal);
    WordBool  (__cdecl* ReleaseNodes)(Cardinal);
    WordBool  (__cdecl* Switch)(Cardinal, Cardinal);
    WordBool  (__cdecl* GetDuplicateHandles)(Cardinal, PInteger);
    WordBool  (__cdecl* ResetStore)();
    // MESSAGE METHODS
    void  (__cdecl* GetMessagesLength)(PInteger);
    WordBool  (__cdecl* GetMessages)(PWChar, Integer);
    void  (__cdecl* ClearMessages)();
    void  (__cdecl* GetExceptionMessageLength)(PInteger);
    WordBool  (__cdecl* GetExceptionMessage)(PWChar, Integer);
    // LOADING AND SET UP METHODS
    WordBool  (__cdecl* SetGamePath)(PWChar);
    WordBool  (__cdecl* SetLanguage)(PWChar);
    WordBool  (__cdecl* SetGameMode)(Integer);
    WordBool  (__cdecl* GetGamePath)(Integer, PInteger);
    WordBool  (__cdecl* GetLoadOrder)(PInteger);
    WordBool  (__cdecl* GetActivePlugins)(PInteger);
    WordBool  (__cdecl* LoadPlugins)(PWChar, WordBool);
    WordBool  (__cdecl* LoadPlugin)(PWChar);
    WordBool  (__cdecl* LoadPluginHeader)(PWChar, PCardinal);
    WordBool  (__cdecl* UnloadPlugin)(Cardinal);
    WordBool  (__cdecl* GetLoaderStatus)(PByte);
} functions_struct;

typedef union
{
  functions_struct  functions;
  func_ptr_t        function_pointers [NUM_FUNCTIONS];
} xelib;

#endif