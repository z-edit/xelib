module.exports = function(lib, xelib, types) {
    let helpers = {},
        {PWChar, PCardinal, PInteger, PWordBool, PByte} = types;

    // LOGGER SETUP
    xelib.verbose = false;
    xelib.logger = console;
    xelib.printStack = true;

    // HELPER FUNCTIONS
    let createTypedBuffer = function(size, type) {
        let buf = Buffer.alloc(size, 0);
        buf.type = type;
        return buf;
    };

    helpers.readCardinalArray = function(buf, len) {
        let a = [];
        for (let i = 0; i < 4 * len; i += 4)
            a.push(buf.readUInt32LE(i));
        return a;
    };

    helpers.wcb = function(value) {
        let buf = createTypedBuffer(value.length * 2 + 1, PWChar);
        buf.write(value, 0, 'ucs2');
        return buf;
    };

    let safePath = function(_id) {
        try {
            return xelib.Path(_id);
        } catch (x) {
            return _id;
        }
    };

    helpers.elementContext = function(_id, path) {
        if (!path) return safePath(_id);
        return `${safePath(_id)}, "${path}"`;
    };

    helpers.arrayItemContext = function(_id, path, subpath, value) {
        return `${safePath(_id)}: ${path}, ${subpath}, ${value}`;
    };

    helpers.flagContext = function(_id, path, name) {
        return `${safePath(_id)}, "${path}\\${name}"`;
    };

    let resolveMessage = function(msg) {
        return msg.constructor === Function ? msg() : msg;
    };

    helpers.Fail = function(message = '') {
        try {
            message = [
                xelib.printStack && xelib.GetExceptionStack(),
                xelib.GetExceptionMessage(),
                resolveMessage(message)
            ].reverse().filter(i => i).join('\r\n');
        } catch (e) {
            xelib.logger.error('Unknown critical exception!');
        }
        throw new Error(resolveMessage(message));
    };

    helpers.GetString = function(callback, method = 'GetResultString') {
        let _len = createTypedBuffer(4, PInteger);
        callback(_len);
        let len = _len.readInt32LE(0);
        if (len < 1) return '';
        let str = createTypedBuffer(2 * len, PWChar);
        if (xelib.verbose) xelib.logger.info(`GetString(len: ${len})`);
        if (!lib[method](str, len))
            helpers.Fail(`${method} failed.`);
        return str.toString('utf16le');
    };

    helpers.GetHandle = function(callback) {
        let _res = createTypedBuffer(4, PCardinal);
        callback(_res);
        let handle = _res.readUInt32LE(0);
        if (xelib.HandleGroup) xelib.HandleGroup.push(handle);
        return handle;
    };

    helpers.GetInteger = function(callback) {
        let _res = createTypedBuffer(4, PInteger);
        callback(_res);
        return _res.readInt32LE(0);
    };

    helpers.GetBool = function(callback) {
        let _bool = createTypedBuffer(2, PWordBool);
        callback(_bool);
        return _bool.readUInt16LE(0) > 0;
    };

    helpers.GetByte = function(callback) {
        let _res = createTypedBuffer(1, PByte);
        callback(_res);
        return _res.readUInt8(0);
    };

    helpers.GetArray = function(callback) {
        let _len = createTypedBuffer(4, PInteger);
        callback(_len);
        let len = _len.readInt32LE(0);
        if (len < 1) return [];
        let buf = createTypedBuffer(4 * len, PCardinal);
        if (xelib.verbose) xelib.logger.info(`GetArray(len: ${len})`);
        if (!lib.GetResultArray(buf, len))
            helpers.Fail('GetResultArray failed');
        let a = helpers.readCardinalArray(buf, len);
        if (xelib.HandleGroup) a.forEach((h) => xelib.HandleGroup.push(h));
        return a;
    };

    helpers.GetStringArray = function(callback, method = 'GetResultString') {
        let str = helpers.GetString(callback, method);
        return str !== '' ? str.split('\r\n') : [];
    };

    helpers.GetDictionary = function(callback, method = 'GetResultString') {
        let pairs = helpers.GetStringArray(callback, method),
            dictionary = {};
        pairs.forEach(function(pair) {
            let n = pair.indexOf('=');
            dictionary[pair.substr(0, n)] = pair.substr(n + 1, pair.length);
        });
        return dictionary;
    };

    helpers.GetBoolValue = function(_id, method) {
        return helpers.GetBool(function(_bool) {
            if (!lib[method](_id, _bool))
                helpers.Fail(() => `Failed to call ${method} on ${helpers.elementContext(_id)}`);
        });
    };

    helpers.GetStringValue = function(_id, method) {
        return helpers.GetString(function(_len) {
            if (!lib[method](_id, _len))
                helpers.Fail(() => `${method} failed on ${helpers.elementContext(_id)}`);
        });
    };

    helpers.GetEnumValue = function(_id, method) {
        return helpers.GetByte(function(_byte) {
            if (!lib[method](_id, _byte))
                helpers.Fail(() => `${method} failed on ${helpers.elementContext(_id)}`);
        });
    };

    helpers.GetNativeValue = function(_id, path, method, len, type) {
        let buf = createTypedBuffer(len, type);
        lib[method](_id, helpers.wcb(path), buf);
        return buf;
    };

    helpers.GetNativeValueEx = function(_id, path, method, len, type) {
        let buf = createTypedBuffer(len, type);
        if (!lib[method](_id, helpers.wcb(path), buf))
            helpers.Fail(() => `Failed to ${method} for ${helpers.elementContext(_id, path)}`);
        return buf;
    };

    helpers.SetNativeValue = function(_id, path, method, value) {
        if (value === undefined) {
            value = path;
            path = '';
        }
        if (!lib[method](_id, helpers.wcb(path), value))
            helpers.Fail(() => `Failed to ${method} to ${value} at: ${helpers.elementContext(_id, path)}`);
    };

    helpers.applyEnums = function(context, enums, label) {
        enums.forEach((value, ord) => context[value] = ord);
        context[label] = enums;
    };

    return helpers;
};
