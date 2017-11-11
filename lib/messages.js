module.exports = function(lib, xelib, helpers) {
    let { GetString } = helpers;

    // MESSAGE METHODS
    Object.assign(xelib, {
        GetMessages: function() {
            return GetString(function(_len) {
                lib.GetMessagesLength(_len);
            }, 'GetMessages');
        },
        ClearMessages: function() {
            lib.ClearMessages();
        },
        GetExceptionMessage: function() {
            return GetString(function(_len) {
                lib.GetExceptionMessageLength(_len);
            }, 'GetExceptionMessage');
        }
    });
};
