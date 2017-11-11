const lib = require('bindings')('xelib');
const xelib = {};
const helpers = require('./lib/helpers')(lib, xelib);

require('./lib/meta')(lib, xelib, helpers);
require('./lib/messages')(lib, xelib, helpers);
require('./lib/setup')(lib, xelib, helpers);
require('./lib/files')(lib, xelib, helpers);
require('./lib/masters')(lib, xelib, helpers);
require('./lib/elements')(lib, xelib, helpers);
require('./lib/errors')(lib, xelib, helpers);
require('./lib/elementValues')(lib, xelib, helpers);
require('./lib/serialization')(lib, xelib, helpers);
require('./lib/records')(lib, xelib, helpers);
require('./lib/groups')(lib, xelib, helpers);
require('./lib/filter')(lib, xelib, helpers);
require('./lib/fileValues')(lib, xelib, helpers);
require('./lib/recordValues')(lib, xelib, helpers);
require('./lib/common')(lib, xelib, helpers);
require('./lib/utils')(lib, xelib, helpers);

module.exports = {
    helpers: helpers,
    lib: lib,
    wrapper: xelib
};
