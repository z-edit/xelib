const xelib = require('../');
const assert = require('assert');

let GetString = function(callback) {
  let _len = new Buffer(4);
  callback(_len);
  let len = _len.readInt32LE();
  if (len < 1) return '';
  let str = new Buffer(2 * len);
  if (!xelib.GetResultString(str, len))
    throw new Error('GetResultString failed');
  return str.toString('utf16le');
};

let wcb = function(value) {
    let buf = new Buffer((value.length + 1) * 2);
    buf.write(value, 0, 'utf16le');
    return buf;
};

describe('xelib', function() {
  it('should be able to initialize', function() {
    xelib.InitXEdit();
  });

  describe('meta functions', function() {
    describe('GetGlobal', function() {
      it('should get a global', function() {
        let version = GetString(function(_len) {
            if (!xelib.GetGlobal(wcb('Version'), _len))
              throw new Error('GetGlobal fialed');
        });
        assert.equal(version, '0.2.0.51');
      });
    });

    describe('GetGlobals', function() {

    });
  });

  it('should be able to finalize', function() {
      xelib.CloseXEdit();
  });
});
