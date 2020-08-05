#include <windows.h>
#include <iostream>
#include <string>
#include <direct.h>
#include "lib.h"

functions_union xelib;
HINSTANCE XEditLib;

void log(std::string message) {
    std::cout << message << std::endl;
}

int load(std::string dllPath) {
    LPSTR libPath = (LPSTR) strdup(dllPath.c_str());

    try {
        XEditLib = LoadLibrary(libPath);

        if (!XEditLib) {
            log("Failed to to load " + dllPath);
            return EXIT_FAILURE;
        }

        for (int i = 0; i < NUM_FUNCTIONS; i++) {
            xelib.function_pointers[i] = GetProcAddress(XEditLib, FUNCTION_NAMES[i]);

            if (xelib.function_pointers[i] == NULL) {
                log("Failed to to bind XEditLib.dll:" + std::string(FUNCTION_NAMES[i]));
                return EXIT_FAILURE;
            }
        }
        return EXIT_SUCCESS;
    } catch(...) {
        free(libPath);
        return EXIT_FAILURE;
    }
}