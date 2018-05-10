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
    PWChar: ref.refType(WString),
    PCardinal: ref.refType(Cardinal),
    PInteger: ref.refType(Integer),
    PWordBool: ref.refType(WordBool),
    PDouble: ref.refType(Double),
    PByte: ref.refType(Byte)
};
