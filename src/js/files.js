module.exports = function(lib, xelib, helpers) {
    let { Fail, elementContext, GetHandle, GetString, GetInteger, wcb } = helpers;

    // FILE HANDLING METHODS
    Object.assign(xelib, {
        AddFile: function(filename, ignoreExists = false) {
            return GetHandle(function(_res) {
                if (!lib.AddFile(wcb(filename), ignoreExists, _res))
                    Fail(`Failed to add new file: ${filename}`);
            });
        },
        FileByIndex: function(index) {
            return GetHandle((_res) => lib.FileByIndex(index, _res));
        },
        FileByLoadOrder: function(loadOrder) {
            return GetHandle((_res) => lib.FileByLoadOrder(loadOrder, _res));
        },
        FileByName: function(filename) {
            return GetHandle((_res) => lib.FileByName(wcb(filename), _res));
        },
        FileByAuthor: function(author) {
            return GetHandle((_res) => lib.FileByAuthor(wcb(author), _res));
        },
        NukeFile: function(id) {
            if (!lib.NukeFile(id))
                Fail(`Failed to nuke file: ${id}`);
        },
        RenameFile: function(id, newFileName) {
            if (!lib.RenameFile(id, wcb(newFileName)))
                Fail(() => `Failed to rename file ${elementContext(id)} to ${newFileName}`);
        },
        SaveFile: function(id, filePath = '') {
            if (!lib.SaveFile(id, wcb(filePath)))
                Fail(() => `Failed to save file: ${elementContext(id)}`);
        },
        GetRecordCount: function(id) {
            return GetInteger(function(_res) {
                if (!lib.GetRecordCount(id, _res))
                    Fail(() => `Failed to get record count for: ${elementContext(id)}`);
            });
        },
        GetOverrideRecordCount: function(id) {
            return GetInteger(function(_res) {
                if (!lib.GetOverrideRecordCount(id, _res))
                    Fail(() => `Failed to get override record count for: ${elementContext(id)}`);
            });
        },
        MD5Hash: function(id) {
            return GetString(function(_len) {
                if (!lib.MD5Hash(id, _len))
                    Fail(() => `Failed to get MD5 Hash for: ${elementContext(id)}`);
            });
        },
        CRCHash: function(id) {
            return GetString(function(_len) {
                if (!lib.CRCHash(id, _len))
                    Fail(() => `Failed to get CRC Hash for: ${elementContext(id)}`);
            });
        },
        GetFileLoadOrder: function(id) {
            return GetInteger(function(_res) {
                if (!lib.GetFileLoadOrder(id, _res))
                    Fail(() => `Failed to file load order for: ${elementContext(id)}`);
            });
        },
        GetFileHeader: function(id) {
            return xelib.GetElement(id, 'File Header');
        },
        SortEditorIDs: function(id, sig) {
            if (!lib.SortEditorIDs(id, wcb(sig)))
                Fail(() => `Failed to sort ${sig} EditorIDs for: ${elementContext(id)}`);
        },
        SortNames: function(id, sig) {
            if (!lib.SortNames(id, wcb(sig)))
                Fail(() => `Failed to sort ${sig} Names for: ${elementContext(id)}`);
        }
    });
};
