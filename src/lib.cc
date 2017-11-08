#include <windows.h>
#include <iostream>
#include <string>
#include "lib.h"

std::string getProgramPath() {
  char result[MAX_PATH];
  return std::string(result, GetModuleFileName(NULL, result, MAX_PATH));
}

std::string extractDirectory(std::string path) {
    return path.substr(0, path.find_last_of("\\"));
}

void log(std::string message) {
    std::cout << message << std::endl;
}

int main() {
    std::string program_path = getProgramPath();
    std::string dllPath = extractDirectory(program_path) + "XEditLib.dll";
    LPSTR libPath = strdup(dllPath.c_str());

    try {
        HINSTANCE hGetProcIDDLL = LoadLibrary(libPath);

        if (!hGetProcIDDLL) {
            log("Failed to to load " + dllPath);
            return EXIT_FAILURE;
        }

        for (int i = 0; i < NUM_FUNCTIONS; i++) {
            function_pointers[i] = (func_ptr_t) GetProcAddress(hGetProcIDDLL, FUNCTION_NAMES[i]);

            if (function_pointers[i] == NULL) {
                log("Failed to to bind XEditLib.dll:" + std::string(FUNCTION_NAMES[i]));
                return EXIT_FAILURE;
            }
        }
    } catch(...) {
        free(libPath);
    }
}