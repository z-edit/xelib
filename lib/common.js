module.exports = function(lib, xelib) {
    // COMMON ARRAY FUNCTIONS
    let buildArrayValueFunctions = function(label, path, subpath = '', extraArgs) {
        xelib[`Has${label}`] = function(element, value) {
            return xelib.HasArrayItem(element, path, subpath, value);
        };

        if (subpath !== '') {
            xelib[`Get${label}`] = function(element, value) {
                return xelib.GetArrayItem(element, path, subpath, value);
            };
        }

        if (!extraArgs) {
            xelib[`Add${label}`] = function(element, value) {
                return xelib.AddArrayItem(element, path, subpath, value);
            };
        } else {
            xelib[`Add${label}`] = function(element, value, ...args) {
                let newItem = xelib.AddArrayItem(element, path, subpath, value);
                args.slice(0, extraArgs.length).forEach(function(arg, i) {
                    xelib.SetValue(newItem, extraArgs[i], arg);
                });
                return newItem;
            };
        }

        xelib[`Remove${label}`] = function(element, value) {
            return xelib.RemoveArrayItem(element, path, subpath, value);
        };
    };

    buildArrayValueFunctions('Keyword', 'KWDA');
    buildArrayValueFunctions('FormID', 'FormIDs');
    buildArrayValueFunctions('MusicTrack', 'Music Tracks');
    buildArrayValueFunctions('Footstep', 'Footstep Sets');
    buildArrayValueFunctions('AdditionalRace', 'Additional Races');
    buildArrayValueFunctions('Effect', 'Effects', 'EFID - Base Effect',
        ['EFIT\\Magnitude', 'EFIT\\Area', 'EFIT\\Duration']);
    buildArrayValueFunctions('Item', 'Items', 'CNTO\\Item', ['CNTO\\Count']);
    buildArrayValueFunctions('LeveledEntry', 'Leveled List Entries',
        'LVLO\\Reference', ['LVLO\\Level', 'LVLO\\Count']);
    buildArrayValueFunctions('Script', 'VMAD\\Scripts', 'scriptName', ['Flags']);
    buildArrayValueFunctions('ScriptProperty', 'Properties', 'propertyName',
        ['Type', 'Flags']);
    buildArrayValueFunctions('Condition', 'Conditions', 'CTDA\\Function',
        ['CTDA\\Type', 'CTDA\\Comparison Value', 'CTDA\\Parameter #1']);

    // COMMON VALUE GETTERS AND SETTERS
    let buildValueFunctions = function(label, path) {
        xelib[`Get${label}`] = function(record) {
            return parseFloat(xelib.GetValue(record, path));
        };

        xelib[`Set${label}`] = function(record, value) {
            xelib.SetValue(record, path, value.toString());
        };
    };

    buildValueFunctions('GoldValue', 'DATA\\Value');
    buildValueFunctions('Weight', 'DATA\\Weight');
    buildValueFunctions('Damage', 'DATA\\Damage');
    buildValueFunctions('ArmorRating', 'DNAM');

    xelib.GetArmorType = function(record) {
        return xelib.GetValue(record, '[BODT|BOD2]\\Armor Type');
    };

    xelib.SetArmorType = function(record, armorType) {
        xelib.SetValue(record, '[BODT|BOD2]\\Armor Type', armorType);
    };

    // COMMON FLAG GETTERS AND SETTERS
    let buildFlagFunctions = function(label, path, flagName) {
        xelib[`Get${label}`] = function(record) {
            return xelib.GetFlag(record, path, flagName);
        };

        xelib[`Set${label}`] = function(record, state) {
            return xelib.SetFlag(record, path, flagName, state);
        };
    };

    buildFlagFunctions('IsFemale', 'ACBS\\Flags', 'Female');
    buildFlagFunctions('IsEssential', 'ACBS\\Flags', 'Essential');
    buildFlagFunctions('IsUnique', 'ACBS\\Flags', 'Unique');
};