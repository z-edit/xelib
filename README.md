# xelib
Native node addon which wraps around XEditLib.dll.  Provides an API for interfacing with Bethesda Plugin files.

## status
The C++ wrapper is complete.  I will probably be moving the JavaScript wrapper over from zedit soon.  Could also use some unit tests, but I'm not sure when I'll get around to those.

## installation
Install using npm.  Will be published to npm soon.

`npm i matortheeternal/xelib`

## usage
Usage will be a lot cleaner once I have the JavaScript wrapper included with the module.  Until then, you can use like so:

```js
const xelib = require('xelib');

// UTILITY FUNCTIONS
// wcb: Converts a string to a wide character buffer
let wcb = function(value) {
    let buf = Buffer.alloc((value.length + 1) * 2, 0);
    buf.write(value, 0, 'utf16le');
    return buf;
};

// GetString: Gets a string result
let GetString = function(callback) {
    let _len = Buffer.alloc(4, 0);
    callback(_len);
    let len = _len.readInt32LE();
    if (len === 0) return '';
    let buf = Buffer.alloc(len * 2, 0);
    xelib.GetResultString(buf, len);
    return buf.toString('utf16le');
};

// GetHandle: Gets a handle result
let GetHandle = function(callback) {
    let _handle = Buffer.alloc(4, 0);
    callback(_handle);
    return _handle.readUInt32LE();
};

// INITIALIZATION / SETUP
const libPath = 'A:\\path\\to\\XEditLib.dll';
xelib.InitXEdit(libPath);
// sets the library to the Skyrim game mode
xelib.SetGameMode(3);
// all strings passed should be null-terminated buffers encoded with the utf16le encoding
xelib.LoadPlugins(wcb('Skyrim.esm\nUpdate.esm'), false);
// wait until the loader finishes
let status = Buffer.alloc(1, 0);
while (status.readInt8(0) < 2) {
    xelib.GetLoaderStatus(status);
}

// GETTING AN ELEMENT;
let armorIronGauntlets = GetHandle(function(_handle) {
    xelib.GetElement(0, wcb('Skyrim.esm\\00012E46'), _handle);
});

// GETTING A VALUE
let fullName = GetString(function(_len) {
    xelib.GetValue(armorIronGauntlets, wcb('FULL'), _len);
});
```