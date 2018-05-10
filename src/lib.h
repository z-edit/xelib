#ifndef __XELIB_LIB_H__
#define __XELIB_LIB_H__

#include <string>

// DELPHI TYPES
typedef unsigned short WordBool;
typedef WordBool* PWordBool;
typedef unsigned long Cardinal;
typedef Cardinal* PCardinal;
typedef double* PDouble;
typedef unsigned char Byte;
typedef Byte* PByte;
typedef signed long Integer;
typedef Integer* PInteger;
typedef std::wstring* PWChar;

// function declaration
const int NUM_FUNCTIONS = 152;

static const char* FUNCTION_NAMES [NUM_FUNCTIONS] = {
    // META METHODS
    "InitXEdit", "CloseXEdit", "GetResultString", "GetResultArray", "GetGlobal", "GetGlobals",
    "SetSortMode", "Release", "ReleaseNodes", "Switch", "GetDuplicateHandles", "CleanStore",
    "ResetStore",
    // MESSAGE METHODS
    "GetMessagesLength", "GetMessages", "ClearMessages", "GetExceptionMessageLength",
    "GetExceptionMessage", "GetExceptionStackLength", "GetExceptionStack",
    // LOADING AND SET UP METHODS
    "GetGamePath", "SetGamePath", "SetLanguage", "SetBackupPath", "SetGameMode", "GetLoadOrder",
    "GetActivePlugins", "LoadPlugins", "LoadPlugin", "LoadPluginHeader", "BuildReferences",
    "GetLoaderStatus", "UnloadPlugin",
    // ARCHIVE HANDLING METHODS
    "ExtractContainer", "ExtractFile", "GetContainerFiles", "GetLoadedContainers", "LoadContainer",
    // FILE HANDLING METHODS
    "AddFile", "FileByIndex", "FileByLoadOrder", "FileByName", "FileByAuthor", "NukeFile",
    "RenameFile", "SaveFile", "GetRecordCount", "GetOverrideRecordCount", "MD5Hash", "CRCHash",
    "SortEditorIDs", "SortNames", "GetFileLoadOrder",
    // MASTER HANDLING METHODS
    "CleanMasters", "SortMasters", "AddMaster", "AddMasters", "AddRequiredMasters", "GetMasters",
    "GetRequiredBy", "GetMasterNames",
    // ELEMENT HANDLING METHODS
    "HasElement", "GetElement", "AddElement", "AddElementValue", "RemoveElement",
    "RemoveElementOrParent", "SetElement", "GetElements", "GetDefNames", "GetAddList",
    "GetContainer", "GetElementFile", "GetElementGroup", "GetElementRecord", "GetLinksTo",
    "SetLinksTo", "ElementCount", "ElementEquals", "ElementMatches", "HasArrayItem",
    "GetArrayItem", "AddArrayItem", "RemoveArrayItem", "MoveArrayItem", "CopyElement",
    "FindNextElement", "FindPreviousElement", "GetSignatureAllowed", "GetAllowedSignatures",
    "GetIsModified", "GetIsEditable", "SetIsEditable", "GetIsRemoveable", "GetCanAdd", "SortKey",
    "ElementType", "DefType", "SmashType", "ValueType", "IsSorted", "IsFixed",
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
    "IsOverride", "IsWinningOverride", "GetNodes", "GetConflictData", "GetNodeElements",
    // FILTERING METHODS
    "FilterRecord", "ResetFilter"
};

struct functions_struct {
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
    WordBool  (__cdecl* CleanStore)();
    WordBool  (__cdecl* ResetStore)();
    // MESSAGE METHODS
    void  (__cdecl* GetMessagesLength)(PInteger);
    WordBool  (__cdecl* GetMessages)(PWChar, Integer);
    void  (__cdecl* ClearMessages)();
    void  (__cdecl* GetExceptionMessageLength)(PInteger);
    WordBool  (__cdecl* GetExceptionMessage)(PWChar, Integer);
    void  (__cdecl* GetExceptionStackLength)(PInteger);
    WordBool  (__cdecl* GetExceptionStack)(PWChar, Integer);
    // LOADING AND SET UP METHODS
    WordBool  (__cdecl* GetGamePath)(Integer, PInteger);
    WordBool  (__cdecl* SetGamePath)(PWChar);
    WordBool  (__cdecl* SetLanguage)(PWChar);
    WordBool  (__cdecl* SetBackupPath)(PWChar);
    WordBool  (__cdecl* SetGameMode)(Integer);
    WordBool  (__cdecl* GetLoadOrder)(PInteger);
    WordBool  (__cdecl* GetActivePlugins)(PInteger);
    WordBool  (__cdecl* LoadPlugins)(PWChar, WordBool);
    WordBool  (__cdecl* LoadPlugin)(PWChar);
    WordBool  (__cdecl* LoadPluginHeader)(PWChar, PCardinal);
    WordBool  (__cdecl* BuildReferences)(Cardinal, WordBool);
    WordBool  (__cdecl* GetLoaderStatus)(PByte);
    WordBool  (__cdecl* UnloadPlugin)(Cardinal);
    // ARCHIVE HANDLING METHODS
    WordBool  (__cdecl* ExtractContainer)(PWChar, PWChar, WordBool);
    WordBool  (__cdecl* ExtractFile)(PWChar, PWChar, PWChar);
    WordBool  (__cdecl* GetContainerFiles)(PWChar, PInteger);
    WordBool  (__cdecl* GetLoadedContainers)(PInteger);
    WordBool  (__cdecl* LoadContainer)(PWChar);
    // FILE HANDLING METHODS
    WordBool  (__cdecl* AddFile)(PWChar, PCardinal);
    WordBool  (__cdecl* FileByIndex)(Integer, PCardinal);
    WordBool  (__cdecl* FileByLoadOrder)(Integer, PCardinal);
    WordBool  (__cdecl* FileByName)(PWChar, PCardinal);
    WordBool  (__cdecl* FileByAuthor)(PWChar, PCardinal);
    WordBool  (__cdecl* NukeFile)(Cardinal);
    WordBool  (__cdecl* RenameFile)(Cardinal, PWChar);
    WordBool  (__cdecl* SaveFile)(Cardinal, PWChar);
    WordBool  (__cdecl* GetRecordCount)(Cardinal, PInteger);
    WordBool  (__cdecl* GetOverrideRecordCount)(Cardinal, PInteger);
    WordBool  (__cdecl* MD5Hash)(Cardinal, PInteger);
    WordBool  (__cdecl* CRCHash)(Cardinal, PInteger);
    WordBool  (__cdecl* SortEditorIDs)(Cardinal, PWChar);
    WordBool  (__cdecl* SortNames)(Cardinal, PWChar);
    WordBool  (__cdecl* GetFileLoadOrder)(Cardinal, PInteger);
    // MASTER HANDLING METHODS
    WordBool  (__cdecl* CleanMasters)(Cardinal);
    WordBool  (__cdecl* SortMasters)(Cardinal);
    WordBool  (__cdecl* AddMaster)(Cardinal, PWChar);
    WordBool  (__cdecl* AddMasters)(Cardinal, PWChar);
    WordBool  (__cdecl* AddRequiredMasters)(Cardinal, Cardinal, WordBool);
    WordBool  (__cdecl* GetMasters)(Cardinal, PInteger);
    WordBool  (__cdecl* GetRequiredBy)(Cardinal, PInteger);
    WordBool  (__cdecl* GetMasterNames)(Cardinal, PInteger);
    // ELEMENT HANDLING METHODS
    WordBool  (__cdecl* HasElement)(Cardinal, PWChar, PWordBool);
    WordBool  (__cdecl* GetElement)(Cardinal, PWChar, PCardinal);
    WordBool  (__cdecl* AddElement)(Cardinal, PWChar, PCardinal);
    WordBool  (__cdecl* AddElementValue)(Cardinal, PWChar, PWChar, PCardinal);
    WordBool  (__cdecl* RemoveElement)(Cardinal, PWChar);
    WordBool  (__cdecl* RemoveElementOrParent)(Cardinal);
    WordBool  (__cdecl* SetElement)(Cardinal, Cardinal);
    WordBool  (__cdecl* GetElements)(Cardinal, PWChar, WordBool, WordBool, PInteger);
    WordBool  (__cdecl* GetDefNames)(Cardinal, PInteger);
    WordBool  (__cdecl* GetAddList)(Cardinal, PInteger);
    WordBool  (__cdecl* GetContainer)(Cardinal, PCardinal);
    WordBool  (__cdecl* GetElementFile)(Cardinal, PCardinal);
    WordBool  (__cdecl* GetElementGroup)(Cardinal, PCardinal);
    WordBool  (__cdecl* GetElementRecord)(Cardinal, PCardinal);
    WordBool  (__cdecl* GetLinksTo)(Cardinal, PWChar, PCardinal);
    WordBool  (__cdecl* SetLinksTo)(Cardinal, PWChar, Cardinal);
    WordBool  (__cdecl* ElementCount)(Cardinal, PInteger);
    WordBool  (__cdecl* ElementEquals)(Cardinal, Cardinal, PWordBool);
    WordBool  (__cdecl* ElementMatches)(Cardinal, PWChar, PWChar, PWordBool);
    WordBool  (__cdecl* HasArrayItem)(Cardinal, PWChar, PWChar, PWChar, PWordBool);
    WordBool  (__cdecl* GetArrayItem)(Cardinal, PWChar, PWChar, PWChar, PCardinal);
    WordBool  (__cdecl* AddArrayItem)(Cardinal, PWChar, PWChar, PWChar, PCardinal);
    WordBool  (__cdecl* RemoveArrayItem)(Cardinal, PWChar, PWChar, PWChar);
    WordBool  (__cdecl* MoveArrayItem)(Cardinal, Integer);
    WordBool  (__cdecl* CopyElement)(Cardinal, Cardinal, WordBool, PCardinal);
    WordBool  (__cdecl* FindNextElement)(Cardinal, PWChar, WordBool, WordBool, PCardinal);
    WordBool  (__cdecl* FindPreviousElement)(Cardinal, PWChar, WordBool, WordBool, PCardinal);
    WordBool  (__cdecl* GetSignatureAllowed)(Cardinal, PWChar, PWordBool);
    WordBool  (__cdecl* GetAllowedSignatures)(Cardinal, PInteger);
    WordBool  (__cdecl* GetIsModified)(Cardinal, PWordBool);
    WordBool  (__cdecl* GetIsEditable)(Cardinal, PWordBool);
    WordBool  (__cdecl* SetIsEditable)(Cardinal, WordBool);
    WordBool  (__cdecl* GetIsRemoveable)(Cardinal, PWordBool);
    WordBool  (__cdecl* GetCanAdd)(Cardinal, PWordBool);
    WordBool  (__cdecl* SortKey)(Cardinal, PInteger);
    WordBool  (__cdecl* ElementType)(Cardinal, PByte);
    WordBool  (__cdecl* DefType)(Cardinal, PByte);
    WordBool  (__cdecl* SmashType)(Cardinal, PByte);
    WordBool  (__cdecl* ValueType)(Cardinal, PByte);
    WordBool  (__cdecl* IsSorted)(Cardinal, PWordBool);
    WordBool  (__cdecl* IsFixed)(Cardinal, PWordBool);
    // PLUGIN ERROR METHODS
    WordBool  (__cdecl* CheckForErrors)(Cardinal);
    WordBool  (__cdecl* GetErrorThreadDone)();
    WordBool  (__cdecl* GetErrors)(PInteger);
    WordBool  (__cdecl* RemoveIdenticalRecords)(Cardinal, WordBool, WordBool);
    // SERIALIZATION METHODS
    WordBool  (__cdecl* ElementToJson)(Cardinal, PInteger);
    WordBool  (__cdecl* ElementFromJson)(Cardinal, PWChar, PWChar);
    // ELEMENT VALUE METHODS
    WordBool  (__cdecl* Name)(Cardinal, PInteger);
    WordBool  (__cdecl* LongName)(Cardinal, PInteger);
    WordBool  (__cdecl* DisplayName)(Cardinal, PInteger);
    WordBool  (__cdecl* Path)(Cardinal, WordBool, WordBool, PInteger);
    WordBool  (__cdecl* Signature)(Cardinal, PInteger);
    WordBool  (__cdecl* GetValue)(Cardinal, PWChar, PInteger);
    WordBool  (__cdecl* SetValue)(Cardinal, PWChar, PWChar);
    WordBool  (__cdecl* GetIntValue)(Cardinal, PWChar, PInteger);
    WordBool  (__cdecl* SetIntValue)(Cardinal, PWChar, Integer);
    WordBool  (__cdecl* GetUIntValue)(Cardinal, PWChar, PCardinal);
    WordBool  (__cdecl* SetUIntValue)(Cardinal, PWChar, Cardinal);
    WordBool  (__cdecl* GetFloatValue)(Cardinal, PWChar, PDouble);
    WordBool  (__cdecl* SetFloatValue)(Cardinal, PWChar, double);
    WordBool  (__cdecl* GetFlag)(Cardinal, PWChar, PWChar, PWordBool);
    WordBool  (__cdecl* SetFlag)(Cardinal, PWChar, PWChar, WordBool);
    WordBool  (__cdecl* GetEnabledFlags)(Cardinal, PWChar, PInteger);
    WordBool  (__cdecl* SetEnabledFlags)(Cardinal, PWChar, PWChar);
    WordBool  (__cdecl* GetAllFlags)(Cardinal, PWChar, PInteger);
    WordBool  (__cdecl* GetEnumOptions)(Cardinal, PWChar, PInteger);
    WordBool  (__cdecl* SignatureFromName)(PWChar, PInteger);
    WordBool  (__cdecl* NameFromSignature)(PWChar, PInteger);
    WordBool  (__cdecl* GetSignatureNameMap)(PInteger);
    // RECORD HANDLING METHODS
    WordBool  (__cdecl* GetFormID)(Cardinal, PCardinal, WordBool);
    WordBool  (__cdecl* SetFormID)(Cardinal, Cardinal, WordBool, WordBool);
    WordBool  (__cdecl* GetRecord)(Cardinal, Cardinal, PCardinal);
    WordBool  (__cdecl* GetRecords)(Cardinal, PWChar, WordBool, PInteger);
    WordBool  (__cdecl* GetOverrides)(Cardinal, PInteger);
    WordBool  (__cdecl* GetReferencedBy)(Cardinal, PInteger);
    WordBool  (__cdecl* GetMasterRecord)(Cardinal, PCardinal);
    WordBool  (__cdecl* GetPreviousOverride)(Cardinal, Cardinal, PCardinal);
    WordBool  (__cdecl* GetWinningOverride)(Cardinal, PCardinal);
    WordBool  (__cdecl* FindNextRecord)(Cardinal, PWChar, WordBool, WordBool, PCardinal);
    WordBool  (__cdecl* FindPreviousRecord)(Cardinal, PWChar, WordBool, WordBool, PCardinal);
    WordBool  (__cdecl* FindValidReferences)(Cardinal, PWChar, PWChar, Integer, PInteger);
    WordBool  (__cdecl* ExchangeReferences)(Cardinal, Cardinal, Cardinal);
    WordBool  (__cdecl* IsMaster)(Cardinal, PWordBool);
    WordBool  (__cdecl* IsInjected)(Cardinal, PWordBool);
    WordBool  (__cdecl* IsOverride)(Cardinal, PWordBool);
    WordBool  (__cdecl* IsWinningOverride)(Cardinal, PWordBool);
    WordBool  (__cdecl* GetNodes)(Cardinal, PCardinal);
    WordBool  (__cdecl* GetConflictData)(Cardinal, Cardinal, PByte, PByte);
    WordBool  (__cdecl* GetNodeElements)(Cardinal, Cardinal, PInteger);
    // FILTERING METHODS
    WordBool  (__cdecl* FilterRecord)(Cardinal);
    WordBool  (__cdecl* ResetFilter)();
};

union functions_union
{
  functions_struct  functions;
  FARPROC           function_pointers [NUM_FUNCTIONS];
};

extern HINSTANCE XEditLib;
extern functions_union xelib;

int load(std::string dllPath);
void log(std::string message);

#endif