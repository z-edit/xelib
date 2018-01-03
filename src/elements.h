#ifndef XELIB_ELEMENTS_H
#define XELIB_ELEMENTS_H

#include <nan.h>

// NAN METHODS
NAN_METHOD(HasElement);
NAN_METHOD(GetElement);
NAN_METHOD(AddElement);
NAN_METHOD(AddElementValue);
NAN_METHOD(RemoveElement);
NAN_METHOD(RemoveElementOrParent);
NAN_METHOD(SetElement);
NAN_METHOD(GetElements);
NAN_METHOD(GetDefNames);
NAN_METHOD(GetAddList);
NAN_METHOD(GetContainer);
NAN_METHOD(GetElementRecord);
NAN_METHOD(GetElementGroup);
NAN_METHOD(GetElementFile);
NAN_METHOD(GetLinksTo);
NAN_METHOD(SetLinksTo);
NAN_METHOD(ElementCount);
NAN_METHOD(ElementEquals);
NAN_METHOD(ElementMatches);
NAN_METHOD(HasArrayItem);
NAN_METHOD(GetArrayItem);
NAN_METHOD(AddArrayItem);
NAN_METHOD(RemoveArrayItem);
NAN_METHOD(MoveArrayItem);
NAN_METHOD(CopyElement);
NAN_METHOD(FindNextElement);
NAN_METHOD(FindPreviousElement);
NAN_METHOD(GetSignatureAllowed);
NAN_METHOD(GetAllowedSignatures);
NAN_METHOD(GetIsModified);
NAN_METHOD(GetIsEditable);
NAN_METHOD(SetIsEditable);
NAN_METHOD(GetIsRemoveable);
NAN_METHOD(GetCanAdd);
NAN_METHOD(SortKey);
NAN_METHOD(ElementType);
NAN_METHOD(DefType);
NAN_METHOD(SmashType);
NAN_METHOD(ValueType);
NAN_METHOD(IsSorted);

#endif