#ifndef XELIB_ARCHIVES_H
#define XELIB_ARCHIVES_H

#include <nan.h>

// NAN METHODS
NAN_METHOD(ExtractContainer);
NAN_METHOD(ExtractFile);
NAN_METHOD(GetContainerFiles);
NAN_METHOD(GetFileContainer);
NAN_METHOD(GetLoadedContainers);
NAN_METHOD(LoadContainer);
NAN_METHOD(BuildArchive);

#endif