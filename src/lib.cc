#include <windows.h>
#include <iostream>
#include <string>
#include <direct.h>
#include "lib.h"

functions_union xelib;
HINSTANCE XEditLib;

std::string getProgramPath() {
  char* cwd = _getcwd(0, 0);
  std::string working_dir(cwd);
  std::free(cwd);
  return working_dir;
}

std::string extractDirectory(std::string path) {
    return path.substr(0, path.find_last_of("\\"));
}

void log(std::string message) {
    std::cout << message << std::endl;
}

int load(std::string dllPath) {
    log("Loading " + dllPath);
    LPSTR libPath = (LPSTR) strdup(dllPath.c_str());

    try {
        XEditLib = LoadLibrary(libPath);

        if (!XEditLib) {
            log("Failed to to load " + dllPath);
            return EXIT_FAILURE;
        }

        for (int i = 0; i < NUM_FUNCTIONS; i++) {
            printf("Loading [%d] %s\n", i, FUNCTION_NAMES[i]);
            xelib.function_pointers[i] = GetProcAddress(XEditLib, FUNCTION_NAMES[i]);
            printf("-> Address: %p\n", xelib.function_pointers[i]);

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

void unload() {
    FreeLibrary(XEditLib);
}