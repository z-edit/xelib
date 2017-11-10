#ifndef XELIB_FILES_H
#define XELIB_FILES_H

#include <nan.h>

// NAN METHODS
NAN_METHOD(AddFile);
NAN_METHOD(FileByIndex);
NAN_METHOD(FileByLoadOrder);
NAN_METHOD(FileByName);
NAN_METHOD(FileByAuthor);
NAN_METHOD(NukeFile);
NAN_METHOD(RenameFile);
NAN_METHOD(SaveFile);
NAN_METHOD(GetRecordCount);
NAN_METHOD(GetOverrideRecordCount);
NAN_METHOD(MD5Hash);
NAN_METHOD(CRCHash);
NAN_METHOD(SortEditorIDs);
NAN_METHOD(SortNames);
NAN_METHOD(GetFileLoadOrder);

#endif