const xelib = {};

const types = require('./src/types');
const lib = require('./src/lib')(xelib, types);
const helpers = require('./src/helpers')(lib, xelib, types);

require('./src/meta')(lib, xelib, helpers);
require('./src/messages')(lib, xelib, helpers);
require('./src/setup')(lib, xelib, helpers);
require('./src/archives')(lib, xelib, helpers);
require('./src/files')(lib, xelib, helpers);
require('./src/masters')(lib, xelib, helpers);
require('./src/elements')(lib, xelib, helpers);
require('./src/errors')(lib, xelib, helpers);
require('./src/elementValues')(lib, xelib, helpers, types);
require('./src/serialization')(lib, xelib, helpers);
require('./src/records')(lib, xelib, helpers);
require('./src/groups')(lib, xelib, helpers);
require('./src/filter')(lib, xelib, helpers);
require('./src/fileValues')(lib, xelib, helpers);
require('./src/recordValues')(lib, xelib, helpers);
require('./src/common')(lib, xelib, helpers);
require('./src/utils')(lib, xelib, helpers);

module.exports = {
    helpers: helpers,
    lib: lib,
    wrapper: xelib
};
