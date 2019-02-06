module.exports = function(lib, xelib, helpers) {
    let { Fail, GetString, GetStringArray, wcb } = helpers;

    // FILE HANDLING METHODS
    Object.assign(xelib, {
        ExtractContainer: function(name, dst, replace) {
            return lib.ExtractContainer(wcb(name), wcb(dst), replace);
        },
        ExtractFile: function(name, src, dst) {
            return lib.ExtractFile(wcb(name), wcb(src), wcb(dst));
        },
        GetContainerFiles: function(name, folder) {
            return GetStringArray(function(_len) {
                if (!lib.GetContainerFiles(wcb(name), wcb(folder), _len))
                    Fail(`Failed to get files in container ${name}`);
            });
        },
        GetFileContainer: function(filePath) {
            return GetString(function(_len) {
                if (!lib.GetFileContainer(wcb(filePath), _len))
                    Fail(`Failed to get file container for ${filePath}`);
            });
        },
        GetLoadedContainers: function() {
            return GetStringArray(function(_len) {
                if (!lib.GetLoadedContainers(_len))
                    Fail(`Failed to get loaded containers`);
            });
        },
        LoadContainer: function(filePath) {
            return lib.LoadContainer(wcb(filePath));
        },
        BuildArchive: function(
            name,
            folder,
            filePaths,
            archiveType,
            compress = false,
            share = false,
            af = '',
            ff = ''
        ) {
            lib.BuildArchive(
                wcb(name),
                wcb(folder),
                wcb(filePaths),
                archiveType,
                compress,
                share,
                af,
                ff
            ) || Fail(`Failed to build archive ${name}.`);
        }
    });
};
