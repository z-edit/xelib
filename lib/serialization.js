module.exports = function(lib, xelib, helpers) {
    let { GetString, Fail, wcb, elementContext } = helpers;

    // SERIALIZATION METHODS
    Object.assign(xelib, {
        ElementToJSON: function(id) {
            return GetString(function(_len) {
                if (!lib.ElementToJson(id, _len))
                    Fail(() => `Failed to serialize element to JSON: ${elementContext(id)}`);
            });
        },
        ElementToObject: function(id) {
            return JSON.parse(this.ElementToJSON(id));
        },
        ElementFromJSON: function(id, path, json) {
            if (!lib.ElementFromJSON(id, wcb(path), wcb(json)))
                Fail(() => `Failed to deserialize element from JSON: ${elementContext(id, path)}`);
        },
        ElementFromObject: function(id, path, obj) {
            this.ElementFromJSON(id, path, JSON.stringify(obj));
        }
    });
};
