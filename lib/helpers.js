module.exports = function(lib, xelib) {
    let helpers = {};

    // LOGGER SETUP
    xelib.verbose = false;
    xelib.logger = console;
    xelib.printStack = true;

    // HELPER FUNCTIONS
    helpers.readCardinalArray = function(buf, len) {
        let a = [];
        for (let i = 0; i < 4 * len; i += 4)
            a.push(buf.readUInt32LE(i));
        return a;
    };

    helpers.readImageData = function(buf, width, height) {
        let a = new Uint8ClampedArray(buf);
        return new ImageData(a, width, height);
    };

    helpers.wcb = function(value) {
        let buf = Buffer.alloc((value.length + 1) * 2, 0);
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
        let _len = Buffer.alloc(4, 0);
        callback(_len);
        let len = _len.readInt32LE(0);
        if (len < 1) return '';
        let str = Buffer.alloc(2 * len, 0);
        if (xelib.verbose) xelib.logger.info(`GetString(len: ${len})`);
        if (!lib[method](str, len))
            helpers.Fail(`${method} failed.`);
        return str.toString('utf16le');
    };

    helpers.GetHandle = function(callback) {
        let _res = Buffer.alloc(4, 0);
        callback(_res);
        let handle = _res.readUInt32LE(0);
        if (xelib.HandleGroup) xelib.HandleGroup.push(handle);
        return handle;
    };

    helpers.GetInteger = function(callback) {
        let _res = Buffer.alloc(4, 0);
        callback(_res);
        return _res.readInt32LE(0);
    };

    helpers.GetBool = function(callback) {
        let _bool = Buffer.alloc(2, 0);
        callback(_bool);
        return _bool.readUInt16LE(0) > 0;
    };

    helpers.GetByte = function(callback) {
        let _res = Buffer.alloc(1, 0);
        callback(_res);
        return _res.readUInt8(0);
    };

    helpers.GetArray = function(callback) {
        let _len = Buffer.alloc(4, 0);
        callback(_len);
        let len = _len.readInt32LE(0);
        if (len < 1) return [];
        let buf = Buffer.alloc(4 * len, 0);
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

    helpers.GetImageData = function(callback) {
        let _width = Buffer.alloc(4, 0),
            _height = Buffer.alloc(4, 0);
        callback(_width, _height);
        let width = _width.readInt32LE(0),
            height = _height.readInt32LE(0);
        if (width < 1 || height < 1)
            throw new Error(`Invalid ImageData dimensions: ${width} x ${height}`);
        let len = width * height,
            buf = Buffer.alloc(len, 0);
        if (xelib.verbose) xelib.logger.info(`GetResultBytes(len: ${len})`);
        if (!lib.GetResultBytes(buf, len))
            helpers.Fail('GetResultBytes failed');
        return helpers.readImageData(buf, width, height);
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
                helpers.Fail(`Failed to call ${method} on ${helpers.elementContext(_id)}`);
        });
    };

    helpers.GetStringValue = function(_id, method) {
        return helpers.GetString(function(_len) {
            if (!lib[method](_id, _len))
                helpers.Fail(`${method} failed on ${helpers.elementContext(_id)}`);
        });
    };

    helpers.GetEnumValue = function(_id, method) {
        return helpers.GetByte(function(_byte) {
            if (!lib[method](_id, _byte))
                helpers.Fail(`${method} failed on ${helpers.elementContext(_id)}`);
        });
    };

    helpers.GetNativeValue = function(_id, path, method, len) {
        let buf = Buffer.alloc(len, 0);
        lib[method](_id, helpers.wcb(path), buf);
        return buf;
    };

    helpers.GetNativeValueEx = function(_id, path, method, len) {
        let buf = Buffer.alloc(len, 0);
        if (!lib[method](_id, helpers.wcb(path), buf))
            helpers.Fail(`Failed to ${method} for ${helpers.elementContext(_id, path)}`);
        return buf;
    };

    helpers.SetNativeValue = function(_id, path, method, value) {
        if (value === undefined) {
            value = path;
            path = '';
        }
        if (!lib[method](_id, helpers.wcb(path), value))
            helpers.Fail(`Failed to ${method} to ${value} at: ${helpers.elementContext(_id, path)}`);
    };

    helpers.applyEnums = function(context, enums, label) {
        enums.forEach((value, ord) => context[value] = ord);
        context[label] = enums;
    };

    helpers.buildFlags = function(opts, flags) {
        return Object.keys(opts).reduce((sum, key) => {
            return sum + (flags[key] || 0);
        }, 0);
    };

    return helpers;
};
