const wchar_t = require('ref-wchar');
const ref = require('ref');

module.exports = {
    Void: 'void',
    WString: wchar_t.string,
    Cardinal: ref.types.uint32,
    WordBool: ref.types.uint16,
    Integer: ref.types.int32,
    Double: ref.types.double,
    Byte: ref.types.byte,
    PWChar: ref.refType(wchar_t.string),
    PCardinal: ref.refType(ref.types.uint32),
    PInteger: ref.refType(ref.types.int32),
    PWordBool: ref.refType(ref.types.uint16),
    PDouble: ref.refType(ref.types.double),
    PByte: ref.refType(ref.types.byte)
};
