# xelib
Native node addon which wraps around XEditLib.dll.  Provides an API for interfacing with Bethesda Plugin files.

## status
The C++ wrapper and the JavaScript wrapper are both complete.  Could use some unit tests, but I'm not sure when I'll get around to those.

## installation
Install using npm.  Will be published to npm soon.

```
npm i z-edit/xelib
```

## usage
```js
const xelib = require('xelib').wrapper;

// INITIALIZATION / SETUP
xelib.Initialize('A:\\path\\to\\XEditLib.dll');
// sets the library to the Skyrim game mode
xelib.SetGameMode(xelib.gmTES5);
// list plugins separated by newlines
xelib.LoadPlugins('Skyrim.esm\nUpdate.esm');
// wait until the loader finishes
let status = 0;
while (status < 2) {
    status = xelib.GetLoaderStatus();
}

// GETTING AN ELEMENT
let armorIronGauntlets = xelib.GetElement(0, 'Skyrim.esm\\00012E46');

// GETTING A VALUE
let fullName = xelib.GetValue(armorIronGauntlets, 'FULL');
```

## additional ressources
More information about the JavaScript wrapper can be found on the [zEdit Docs](https://z-edit.github.io/#/docs?t=Development%2FAPIs%2Fxelib).
