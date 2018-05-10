module.exports = function(lib, xelib, helpers) {
    let { GetString, Fail, elementContext } = helpers;

    // PLUGIN ERROR METHODS
    Object.assign(xelib, {
        CheckForErrors: function(id) {
            if (!lib.CheckForErrors(id))
                Fail(() => `Failed to check ${elementContext(id)} for errors.`);
        },
        GetErrorThreadDone: function() {
            return lib.GetErrorThreadDone();
        },
        GetErrors: function() {
            let str = GetString(function(_len) {
                if (!lib.GetErrors(_len))
                    Fail('Failed to get errors');
            });
            return JSON.parse(str).errors;
        },
        RemoveIdenticalRecords: function(id, removeITMs = true, removeITPOs = true) {
            if (!lib.RemoveIdenticalRecords(id, removeITMs, removeITPOs))
                Fail(() => `Failed to remove identical errors from ${elementContext(id)}`);
        }
    });
};