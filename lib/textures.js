module.exports = function(lib, xelib, helpers) {
    let { Fail, GetImageData, wcb } = helpers;

    // FILE HANDLING METHODS
    Object.assign(xelib, {
        GetBitmapResource: function(resourceName) {
            return GetImageData(function(_width, _height) {
                if (!lib.GetBitmapResource(wcb(resourceName), _width, _height))
                    Fail(`Failed to get bitmap resource for ${resourceName}`);
            });
        }
    });
};