module.exports = function(lib, xelib, helpers) {
    let { Fail, GetStringArray, wcb } = helpers;

    // FILE HANDLING METHODS
    Object.assign(xelib, {
        ExtractContainer: function(name, dst, replace) {
            return lib.ExtractContainer(wcb(name), wcb(dst), replace);
        },
        ExtractFile: function(name, src, dst) {
            return lib.ExtractFile(wcb(name), wcb(src), wcb(dst));
        },
        GetContainerFiles: function(name) {
            return GetStringArray(function(_len) {
                if (!lib.GetContainerFiles(name, _len))
                    Fail(`Failed to get files in container ${name}`)
            });
        },
        GetLoadedContainers: function() {
            return GetStringArray(function(_len) {
                if (!lib.GetLoadedContainers(_len))
                    Fail(`Failed to get loaded containers`)
            });
        },
        LoadContainer: function(filePath) {
            return lib.LoadContainer(wcb(filePath));
        }
    });
};