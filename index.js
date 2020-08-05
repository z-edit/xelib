const xelib = {};

const lib = require('bindings')('xelib');
const helpers = require('./src/js/helpers')(lib, xelib);

require('./src/js/meta')(lib, xelib, helpers);
require('./src/js/messages')(lib, xelib, helpers);
require('./src/js/setup')(lib, xelib, helpers);
require('./src/js/resources')(lib, xelib, helpers);
require('./src/js/files')(lib, xelib, helpers);
require('./src/js/masters')(lib, xelib, helpers);
require('./src/js/elements')(lib, xelib, helpers);
require('./src/js/errors')(lib, xelib, helpers);
require('./src/js/elementValues')(lib, xelib, helpers);
require('./src/js/serialization')(lib, xelib, helpers);
require('./src/js/records')(lib, xelib, helpers);
require('./src/js/groups')(lib, xelib, helpers);
require('./src/js/filter')(lib, xelib, helpers);
require('./src/js/fileValues')(lib, xelib, helpers);
require('./src/js/recordValues')(lib, xelib, helpers);
require('./src/js/common')(lib, xelib, helpers);
require('./src/js/utils')(lib, xelib, helpers);

module.exports = {
    helpers: helpers,
    lib: lib,
    wrapper: xelib
};
