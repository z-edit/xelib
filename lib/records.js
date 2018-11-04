module.exports = function(lib, xelib, helpers) {
    let { applyEnums, buildFlags, elementContext, Fail, GetArray,
        GetBoolValue, GetStringArray, GetHandle, wcb } = helpers;

    // ENUMERATIONS
    const conflictThis = ['ctUnknown', 'ctIgnored', 'ctNotDefined', 'ctIdenticalToMaster', 'ctOnlyOne', 'ctHiddenByModGroup', 'ctMaster', 'ctConflictBenign', 'ctOverride', 'ctIdenticalToMasterWinsConflict', 'ctConflictWins', 'ctConflictLoses'];
    const conflictAll = ['caUnknown', 'caOnlyOne', 'caNoConflict', 'caConflictBenign', 'caOverride', 'caConflict', 'caConflictCritical'];

    applyEnums(xelib, conflictThis, 'conflictThis');
    applyEnums(xelib, conflictAll, 'conflictAll');

    // FLAGS
    let getRefrsFlags = {
        excludeDeleted: 1,
        excludeDisabled: 2,
        excludeXESP: 4
    };

    // RECORD HANDLING METHODS
    Object.assign(xelib, {
        GetFormID: function(id, native = false, local = false) {
            let _res = Buffer.alloc(4, 0);
            if (!lib.GetFormID(id, _res, native))
                Fail(() => `Failed to get FormID for ${elementContext(id)}`);
            let formID = _res.readUInt32LE();
            return local ? formID & 0xFFFFFF : formID;
        },
        GetHexFormID: function(id, native = false, local = false) {
            return xelib.Hex(xelib.GetFormID(id, native, local), local ? 6 : 8);
        },
        SetFormID: function(id, newFormID, native = false, fixReferences = true) {
            if (!lib.SetFormID(id, newFormID, native, fixReferences))
                Fail(() => `Failed to set FormID on ${elementContext(id)} to ${newFormID}`);
        },
        GetRecord: function(id, formID, searchMasters = true) {
            return GetHandle(function(_res) {
                if (!lib.GetRecord(id, formID, searchMasters, _res))
                    Fail(() => `Failed to get record at: ${elementContext(id)}, ${formID}`);
            });
        },
        GetRecords: function(id, search = '', includeOverrides = false) {
            return GetArray(function(_len) {
                if (!lib.GetRecords(id, wcb(search), includeOverrides, _len))
                    Fail(() => `Failed to get ${search} records from: ${elementContext(id)}`);
            });
        },
        GetREFRs: function(id, search, opts = {}) {
            return GetArray(function(_len) {
                let flags = buildFlags(opts, getRefrsFlags);
                if (!lib.GetREFRs(id, wcb(search), flags, _len))
                    Fail(() => `Failed to get ${search} REFRs from: ${elementContext(id)}`);
            });
        },
        GetOverrides: function(id) {
            return GetArray(function(_len) {
                if (!lib.GetOverrides(id, _len))
                    Fail(() => `Failed to get overrides for: ${elementContext(id)}`);
            });
        },
        GetMasterRecord: function(id) {
            return GetHandle(function(_res) {
                if (!lib.GetMasterRecord(id, _res))
                    Fail(() => `Failed to get master record for: ${elementContext(id)}`);
            });
        },
        GetPreviousOverride: function(id, id2) {
            return GetHandle(function(_res) {
                if (!lib.GetPreviousOverride(id, id2, _res))
                    Fail(() => `Failed to get previous override record for: ${elementContext(id)}, targetting file ${elementContext(id2)}`);
            });
        },
        GetWinningOverride: function(id) {
            return GetHandle(function(_res) {
                if (!lib.GetWinningOverride(id, _res))
                    Fail(() => `Failed to get winning override record for: ${elementContext(id)}`);
            });
        },
        FindNextRecord: function(id, search, byEdid, byName) {
            return GetHandle(function(_res) {
                lib.FindNextRecord(id, wcb(search), byEdid, byName, _res);
            });
        },
        FindPreviousRecord: function(id, search, byEdid, byName) {
            return GetHandle(function(_res) {
                lib.FindPreviousRecord(id, wcb(search), byEdid, byName, _res);
            });
        },
        FindValidReferences: function(id, signature, search, limitTo) {
            return GetStringArray(function(_len) {
                if (!lib.FindValidReferences(id, wcb(signature), wcb(search), limitTo, _len))
                    Fail(() => `Failed to find valid ${signature} references on ${elementContext(id)} searching for: ${search}`);
            });
        },
        GetReferencedBy: function(id) {
            return GetArray(function(_len) {
                if (!lib.GetReferencedBy(id, _len))
                    Fail(() => `Failed to get referenced by for: ${elementContext(id)}`);
            });
        },
        ExchangeReferences: function(id, oldFormID, newFormID) {
            if (!lib.ExchangeReferences(id, oldFormID, newFormID))
                Fail(() => `Failed to exchange references on ${elementContext(id)} from ${oldFormID} to ${newFormID}`)
        },
        IsMaster: function(id) {
            return GetBoolValue(id, "IsMaster");
        },
        IsInjected: function(id) {
            return GetBoolValue(id, "IsInjected");
        },
        IsOverride: function(id) {
            return GetBoolValue(id, "IsOverride");
        },
        IsWinningOverride: function(id) {
            return GetBoolValue(id, "IsWinningOverride");
        },
        GetNodes: function(id) {
            return GetHandle(function(_res) {
                if (!lib.GetNodes(id, _res))
                    Fail(() => `Failed to get nodes for ${elementContext(id)}`);
            });
        },
        GetConflictData: function(id1, id2, asString = false) {
            let _res1 = Buffer.alloc(1, 0),
                _res2 = Buffer.alloc(1, 0);
            if (!lib.GetConflictData(id1, id2, _res1, _res2))
                return [0, 0];
            let n1 = _res1.readUInt8(0),
                n2 = _res2.readUInt8(0);
            return asString ? [conflictAll[n1], conflictThis[n2]] : [n1, n2];
        },
        GetConflictDataEx: function(id1, id2, asString = false) {
            let _res1 = Buffer.alloc(1, 0),
                _res2 = Buffer.alloc(1, 0);
            if (!lib.GetConflictData(id1, id2, _res1, _res2))
                Fail(`GetConflictData failed on ${id1}, ${id2}`);
            let n1 = _res1.readUInt8(0),
                n2 = _res2.readUInt8(0);
            return asString ? [conflictAll[n1], conflictThis[n2]] : [n1, n2];
        },
        GetRecordConflictData: function(id) {
            return xelib.GetConflictData(0, id);
        },
        GetNodeElements: function(id1, id2) {
            return GetArray(function(_len) {
                if (!lib.GetNodeElements(id1, id2, _len))
                    Fail(`GetNodeElements failed on ${elementContext(id1)}, ${elementContext(id2)}`);
            });
        }
    });
};
