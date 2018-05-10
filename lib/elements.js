module.exports = function(lib, xelib, helpers) {
    let { applyEnums, elementContext, arrayItemContext, Fail, GetArray, GetBool,
        GetEnumValue, GetHandle, GetInteger, GetStringArray, wcb } = helpers;

    // ENUMERATIONS
    const elementTypes = ['etFile', 'etMainRecord', 'etGroupRecord', 'etSubRecord', 'etSubRecordStruct', 'etSubRecordArray', 'etSubRecordUnion', 'etArray', 'etStruct', 'etValue', 'etFlag', 'etStringListTerminator', 'etUnion', 'etStructChapter'];
    const defTypes = ['dtRecord', 'dtSubRecord', 'dtSubRecordArray', 'dtSubRecordStruct', 'dtSubRecordUnion', 'dtString', 'dtLString', 'dtLenString', 'dtByteArray', 'dtInteger', 'dtIntegerFormater', 'dtIntegerFormaterUnion', 'dtFlag', 'dtFloat', 'dtArray', 'dtStruct', 'dtUnion', 'dtEmpty', 'dtStructChapter'];
    const smashTypes = ['stUnknown', 'stRecord', 'stString', 'stInteger', 'stFlag', 'stFloat', 'stStruct', 'stUnsortedArray', 'stUnsortedStructArray', 'stSortedArray', 'stSortedStructArray', 'stByteArray', 'stUnion'];
    const valueTypes = ['vtUnknown', 'vtBytes', 'vtNumber', 'vtString', 'vtText', 'vtReference', 'vtFlags', 'vtEnum', 'vtColor', 'vtArray', 'vtStruct'];

    applyEnums(xelib, elementTypes, 'elementTypes');
    applyEnums(xelib, defTypes, 'defTypes');
    applyEnums(xelib, smashTypes, 'smashTypes');
    applyEnums(xelib, valueTypes, 'valueTypes');

    // ELEMENT HANDLING METHODS
    Object.assign(xelib, {
        HasElement: function(id, path = '') {
            return GetBool(function(_bool) {
                if (!lib.HasElement(id, wcb(path), _bool))
                    Fail(() => `Failed to check if element exists at: ${elementContext(id, path)}`);
            });
        },
        GetElement: function(id, path = '') {
            return GetHandle((_res) => lib.GetElement(id, wcb(path), _res));
        },
        GetElementEx: function(id, path = '') {
            return GetHandle(function(_res) {
                if (!lib.GetElement(id, wcb(path), _res))
                    Fail(() => `Failed to get element at: ${elementContext(id, path)}`);
            });
        },
        AddElement: function(id, path = '') {
            return GetHandle(function(_res) {
                if (!lib.AddElement(id, wcb(path), _res))
                    Fail(() => `Failed to create new element at: ${elementContext(id, path)}`);
            });
        },
        AddElementValue: function(id, path, value) {
            return GetHandle(function(_res) {
                if (!lib.AddElementValue(id, wcb(path), wcb(value), _res))
                    Fail(() => `Failed to create new element at: ${elementContext(id, path)}, with value: ${value}`);
            });
        },
        RemoveElement: function(id, path = '') {
            lib.RemoveElement(id, wcb(path));
        },
        RemoveElementEx: function(id, path = '') {
            if (!lib.RemoveElement(id, wcb(path)))
                Fail(() => `Failed to remove element at: ${elementContext(id, path)}`);
        },
        RemoveElementOrParent: function(id) {
            if (!lib.RemoveElementOrParent(id))
                Fail(() => `Failed to remove element ${elementContext(id)}`);
        },
        SetElement: function(id1, id2) {
            if (!lib.SetElement(id1, id2))
                Fail(() => `Failed to set element at ${elementContext(id2)} to ${elementContext(id1)}`);
        },
        GetElements: function(id = 0, path = '', sort = false, filter = false) {
            return GetArray(function(_len) {
                if (!lib.GetElements(id, wcb(path), sort, filter, _len))
                    Fail(() => `Failed to get child elements at: ${elementContext(id, path)}`);
            });
        },
        GetDefNames: function(id) {
            return GetStringArray(function(_len) {
                if (!lib.GetDefNames(id, _len))
                    Fail(() => `Failed to get def names for: ${elementContext(id)}`);
            });
        },
        GetAddList: function(id) {
            return GetStringArray(function(_len) {
                if (!lib.GetAddList(id, _len))
                    Fail(() => `Failed to get add list for: ${elementContext(id)}`);
            });
        },
        GetLinksTo: function(id, path) {
            return GetHandle((_res) => lib.GetLinksTo(id, wcb(path), _res));
        },
        SetLinksTo: function(id, path, id2) {
            if (!lib.SetLinksTo(id, wcb(path), id2))
                Fail(() => `Failed to set reference at: ${elementContext(id, path)}`);
        },
        GetLinksToEx: function(id, path) {
            return GetHandle(function(_res) {
                if (!lib.GetLinksTo(id, wcb(path), _res))
                    Fail(() => `Failed to get reference at: ${elementContext(id, path)}`);
            });
        },
        GetContainer: function(id) {
            return GetHandle((_res) => lib.GetContainer(id, _res));
        },
        GetContainerEx: function(id) {
            return GetHandle(function(_res) {
                if (!lib.GetContainer(id, _res))
                    Fail(() => `Failed to get container for: ${elementContext(id)}`);
            });
        },
        GetElementFile: function(id) {
            return GetHandle(function(_res) {
                if (!lib.GetElementFile(id, _res))
                    Fail(() => `Failed to get element file for: ${elementContext(id)}`);
            });
        },
        GetElementGroup: function(id) {
            return GetHandle(function(_res) {
                if (!lib.GetElementGroup(id, _res))
                    Fail(() => `Failed to get element group for: ${elementContext(id)}`);
            });
        },
        GetElementRecord: function(id) {
            return GetHandle(function(_res) {
                if (!lib.GetElementRecord(id, _res))
                    Fail(() => `Failed to get element record for: ${elementContext(id)}`);
            });
        },
        ElementCount: function(id) {
            return GetInteger(function(_res) {
                if (!lib.ElementCount(id, _res))
                    Fail(() => `Failed to get element count for ${elementContext(id)}`);
            });
        },
        ElementEquals: function(id, id2) {
            return GetBool(function(_bool) {
                if (!lib.ElementEquals(id, id2, _bool))
                    Fail(() => `Failed to check element equality for ${elementContext(id)} and ${elementContext(id2)}`);
            });
        },
        ElementMatches: function(id, path, value) {
            return GetBool(function(_bool) {
                if (!lib.ElementMatches(id, wcb(path), wcb(value), _bool))
                    Fail(() => `Failed to check element matches for ${elementContext(id, path)},${value}`);
            });
        },
        HasArrayItem: function(id, path, subpath, value) {
            return GetBool(function(_bool) {
                lib.HasArrayItem(id, wcb(path), wcb(subpath), wcb(value), _bool);
            });
        },
        GetArrayItem: function(id, path, subpath, value) {
            return GetHandle(function(_res) {
                lib.GetArrayItem(id, wcb(path), wcb(subpath), wcb(value), _res);
            });
        },
        AddArrayItem: function(id, path, subpath, value) {
            return GetHandle(function(_res) {
                if (!lib.AddArrayItem(id, wcb(path), wcb(subpath), wcb(value), _res))
                    Fail(() => `Failed to add array item to ${arrayItemContext(id, path, subpath, value)}`);
            });
        },
        RemoveArrayItem: function(id, path, subpath, value) {
            lib.RemoveArrayItem(id, wcb(path), wcb(subpath), wcb(value));
        },
        MoveArrayItem: function(id, index) {
            if (!lib.MoveArrayItem(id, index))
                Fail(() => `Failed to move array item ${elementContext(id)} to ${index}`);
        },
        CopyElement: function(id, id2, asNew = false) {
            return GetHandle(function(_res) {
                if (!lib.CopyElement(id, id2, asNew, _res))
                    Fail(() => `Failed to copy element ${elementContext(id)} to ${id2}`);
            });
        },
        FindNextElement: function(id, search, byPath, byValue) {
            return GetHandle(function(_res) {
                lib.FindNextElement(id, wcb(search), byPath, byValue, _res);
            });
        },
        FindPreviousElement: function(id, search, byPath, byValue) {
            return GetHandle(function(_res) {
                lib.FindPreviousElement(id, wcb(search), byPath, byValue, _res);
            });
        },
        GetSignatureAllowed: function(id, signature) {
            return GetBool(function(_bool) {
                if (!lib.GetSignatureAllowed(id, wcb(signature), _bool))
                    Fail(() => `Failed to check if signature ${signature} is allowed on ${elementContext(id)}`);
            });
        },
        GetAllowedSignatures: function(id) {
            return GetStringArray(function(_len) {
                if (!lib.GetAllowedSignatures(id, _len))
                    Fail(() => `Failed to get allowed signatures for ${elementContext(id)}`);
            });
        },
        GetIsModified: function(id) {
            return GetBool(function(_bool) {
                if (!lib.GetIsModified(id, _bool))
                    Fail(() => `Failed to get is modified for ${elementContext(id)}`);
            });
        },
        GetIsEditable: function(id) {
            return GetBool(function(_bool) {
                if (!lib.GetIsEditable(id, _bool))
                    Fail(() => `Failed to get is editable for ${elementContext(id)}`);
            });
        },
        SetIsEditable: function(id, bool) {
            if (!lib.SetIsEditable(id, bool))
                Fail(() => `Failed to set is editable for ${elementContext(id)} to ${bool}`);
        },
        GetIsRemoveable: function(id) {
            return GetBool(function(_bool) {
                if (!lib.GetIsRemoveable(id, _bool))
                    Fail(() => `Failed to get is removeable for ${elementContext(id)}`);
            });
        },
        GetCanAdd: function(id) {
            return GetBool(function(_bool) {
                if (!lib.GetCanAdd(id, _bool))
                    Fail(() => `Failed to get can add for ${elementContext(id)}`);
            });
        },
        ElementType: function(id) {
            return GetEnumValue(id, 'ElementType');
        },
        DefType: function(id) {
            return GetEnumValue(id, 'DefType');
        },
        SmashType: function(id) {
            return GetEnumValue(id, 'SmashType');
        },
        ValueType: function(id) {
            return GetEnumValue(id, 'ValueType');
        },
        IsSorted: function(id) {
            return GetBool(function(_bool) {
                if (!lib.IsSorted(id, _bool))
                    Fail(() => `Failed to get is sorted for ${elementContext(id)}`);
            });
        },
        IsFixed: function(id) {
            return GetBool(function(_bool) {
                if (!lib.IsFixed(id, _bool))
                    Fail(() => `Failed to get is fixed for ${elementContext(id)}`);
            });
        },
        IsFlags: function(id) {
            return xelib.ValueType(id) === xelib.vtFlags;
        }
    });
};
