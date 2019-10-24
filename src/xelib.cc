#include "meta.h"
#include "messages.h"
#include "setup.h"
#include "resources.h"
#include "files.h"
#include "masters.h"
#include "elements.h"
#include "errors.h"
#include "serialization.h"
#include "elementValues.h"
#include "records.h"
#include "filter.h"

using v8::FunctionTemplate;

// This represents the top level of the module.
// C++ constructs that are exposed to javascript are exported here

NAN_MODULE_INIT(InitAll) {
    // META METHODS
    NAN_EXPORT(target, InitXEdit);
    NAN_EXPORT(target, CloseXEdit);
    NAN_EXPORT(target, GetResultString);
    NAN_EXPORT(target, GetResultArray);
    NAN_EXPORT(target, GetResultBytes);
    NAN_EXPORT(target, GetGlobal);
    NAN_EXPORT(target, GetGlobals);
    NAN_EXPORT(target, SetSortMode);
    NAN_EXPORT(target, Release);
    NAN_EXPORT(target, ReleaseNodes);
    NAN_EXPORT(target, Switch);
    NAN_EXPORT(target, GetDuplicateHandles);
    NAN_EXPORT(target, CleanStore);
    NAN_EXPORT(target, ResetStore);

    // MESSAGE METHODS
    NAN_EXPORT(target, GetMessagesLength);
    NAN_EXPORT(target, GetMessages);
    NAN_EXPORT(target, ClearMessages);
    NAN_EXPORT(target, GetExceptionMessageLength);
    NAN_EXPORT(target, GetExceptionMessage);
    NAN_EXPORT(target, GetExceptionStackLength);
    NAN_EXPORT(target, GetExceptionStack);

    // LOADING AND SET UP METHODS
    NAN_EXPORT(target, GetGamePath);
    NAN_EXPORT(target, SetGamePath);
    NAN_EXPORT(target, GetGameLanguage);
    NAN_EXPORT(target, SetLanguage);
    NAN_EXPORT(target, SetBackupPath);
    NAN_EXPORT(target, SetGameMode);
    NAN_EXPORT(target, GetLoadOrder);
    NAN_EXPORT(target, GetActivePlugins);
    NAN_EXPORT(target, LoadPlugins);
    NAN_EXPORT(target, LoadPlugin);
    NAN_EXPORT(target, LoadPluginHeader);
    NAN_EXPORT(target, BuildReferences);
    NAN_EXPORT(target, GetLoaderStatus);
    NAN_EXPORT(target, UnloadPlugin);

    // RESOURCE HANDLING METHODS
    NAN_EXPORT(target, ExtractContainer);
    NAN_EXPORT(target, ExtractFile);
    NAN_EXPORT(target, GetContainerFiles);
    NAN_EXPORT(target, GetFileContainer);
    NAN_EXPORT(target, GetLoadedContainers);
    NAN_EXPORT(target, LoadContainer);
    NAN_EXPORT(target, BuildArchive);
    NAN_EXPORT(target, GetTextureData);

    // FILE HANDLING METHODS
    NAN_EXPORT(target, AddFile);
    NAN_EXPORT(target, FileByIndex);
    NAN_EXPORT(target, FileByLoadOrder);
    NAN_EXPORT(target, FileByName);
    NAN_EXPORT(target, FileByAuthor);
    NAN_EXPORT(target, NukeFile);
    NAN_EXPORT(target, RenameFile);
    NAN_EXPORT(target, SaveFile);
    NAN_EXPORT(target, GetRecordCount);
    NAN_EXPORT(target, GetOverrideRecordCount);
    NAN_EXPORT(target, MD5Hash);
    NAN_EXPORT(target, CRCHash);
    NAN_EXPORT(target, SortEditorIDs);
    NAN_EXPORT(target, SortNames);
    NAN_EXPORT(target, GetFileLoadOrder);

    // MASTER HANDLING METHODS
    NAN_EXPORT(target, CleanMasters);
    NAN_EXPORT(target, SortMasters);
    NAN_EXPORT(target, AddMaster);
    NAN_EXPORT(target, AddMasters);
    NAN_EXPORT(target, AddRequiredMasters);
    NAN_EXPORT(target, GetMasters);
    NAN_EXPORT(target, GetRequiredBy);
    NAN_EXPORT(target, GetMasterNames);

    // ELEMENT HANDLING METHODS
    NAN_EXPORT(target, HasElement);
    NAN_EXPORT(target, GetElement);
    NAN_EXPORT(target, AddElement);
    NAN_EXPORT(target, AddElementValue);
    NAN_EXPORT(target, RemoveElement);
    NAN_EXPORT(target, RemoveElementOrParent);
    NAN_EXPORT(target, SetElement);
    NAN_EXPORT(target, GetElements);
    NAN_EXPORT(target, GetDefNames);
    NAN_EXPORT(target, GetAddList);
    NAN_EXPORT(target, GetContainer);
    NAN_EXPORT(target, GetElementFile);
    NAN_EXPORT(target, GetElementGroup);
    NAN_EXPORT(target, GetElementRecord);
    NAN_EXPORT(target, GetLinksTo);
    NAN_EXPORT(target, SetLinksTo);
    NAN_EXPORT(target, ElementCount);
    NAN_EXPORT(target, ElementEquals);
    NAN_EXPORT(target, ElementMatches);
    NAN_EXPORT(target, HasArrayItem);
    NAN_EXPORT(target, GetArrayItem);
    NAN_EXPORT(target, AddArrayItem);
    NAN_EXPORT(target, RemoveArrayItem);
    NAN_EXPORT(target, MoveArrayItem);
    NAN_EXPORT(target, CopyElement);
    NAN_EXPORT(target, FindNextElement);
    NAN_EXPORT(target, FindPreviousElement);
    NAN_EXPORT(target, GetSignatureAllowed);
    NAN_EXPORT(target, GetAllowedSignatures);
    NAN_EXPORT(target, GetIsModified);
    NAN_EXPORT(target, GetIsEditable);
    NAN_EXPORT(target, SetIsEditable);
    NAN_EXPORT(target, GetIsRemoveable);
    NAN_EXPORT(target, GetCanAdd);
    NAN_EXPORT(target, SortKey);
    NAN_EXPORT(target, ElementType);
    NAN_EXPORT(target, DefType);
    NAN_EXPORT(target, SmashType);
    NAN_EXPORT(target, ValueType);
    NAN_EXPORT(target, IsSorted);
    NAN_EXPORT(target, IsFixed);

    // PLUGIN ERROR METHODS
    NAN_EXPORT(target, CheckForErrors);
    NAN_EXPORT(target, GetErrorThreadDone);
    NAN_EXPORT(target, GetErrors);
    NAN_EXPORT(target, RemoveIdenticalRecords);

    // SERIALIZATION METHODS
    NAN_EXPORT(target, ElementToJson);
    NAN_EXPORT(target, ElementFromJson);
    NAN_EXPORT(target, DefToJson);

    // ELEMENT VALUE METHODS
    NAN_EXPORT(target, Name);
    NAN_EXPORT(target, LongName);
    NAN_EXPORT(target, DisplayName);
    NAN_EXPORT(target, Path);
    NAN_EXPORT(target, PathName);
    NAN_EXPORT(target, Signature);
    NAN_EXPORT(target, GetValue);
    NAN_EXPORT(target, SetValue);
    NAN_EXPORT(target, GetIntValue);
    NAN_EXPORT(target, SetIntValue);
    NAN_EXPORT(target, GetUIntValue);
    NAN_EXPORT(target, SetUIntValue);
    NAN_EXPORT(target, GetFloatValue);
    NAN_EXPORT(target, SetFloatValue);
    NAN_EXPORT(target, GetFlag);
    NAN_EXPORT(target, SetFlag);
    NAN_EXPORT(target, GetEnabledFlags);
    NAN_EXPORT(target, SetEnabledFlags);
    NAN_EXPORT(target, GetAllFlags);
    NAN_EXPORT(target, GetEnumOptions);
    NAN_EXPORT(target, SignatureFromName);
    NAN_EXPORT(target, NameFromSignature);
    NAN_EXPORT(target, GetSignatureNameMap);

    // RECORD HANDLING METHODS
    NAN_EXPORT(target, GetFormID);
    NAN_EXPORT(target, SetFormID);
    NAN_EXPORT(target, GetRecord);
    NAN_EXPORT(target, GetRecords);
    NAN_EXPORT(target, GetREFRs);
    NAN_EXPORT(target, GetOverrides);
    NAN_EXPORT(target, GetReferencedBy);
    NAN_EXPORT(target, GetMasterRecord);
    NAN_EXPORT(target, GetPreviousOverride);
    NAN_EXPORT(target, GetWinningOverride);
    NAN_EXPORT(target, GetInjectionTarget);
    NAN_EXPORT(target, FindNextRecord);
    NAN_EXPORT(target, FindPreviousRecord);
    NAN_EXPORT(target, FindValidReferences);
    NAN_EXPORT(target, ExchangeReferences);
    NAN_EXPORT(target, IsMaster);
    NAN_EXPORT(target, IsInjected);
    NAN_EXPORT(target, IsOverride);
    NAN_EXPORT(target, IsWinningOverride);
    NAN_EXPORT(target, GetRecordDef);
    NAN_EXPORT(target, GetNodes);
    NAN_EXPORT(target, GetConflictData);
    NAN_EXPORT(target, GetNodeElements);

    // RECORD HANDLING METHODS
    NAN_EXPORT(target, FilterRecord);
    NAN_EXPORT(target, ResetFilter);
}

NODE_MODULE(xelib, InitAll)
