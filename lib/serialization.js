module.exports = function(lib, xelib, helpers) {
    let { GetString, Fail } = helpers;

    // SERIALIZATION METHODS
    Object.assign(xelib, {
        ElementToJSON: function(id) {
            return GetString(function(_len) {
                if (!lib.ElementToJson(id, _len))
                    Fail(`Failed to serialize element to JSON: ${id}`);
            });
        },
        ElementToObject: function(id) {
            return JSON.parse(this.ElementToJSON(id));
        }
    });
}
