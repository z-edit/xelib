#include <windows.h>
#include <iostream>
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
    std::string dir = extractDirectory(program_path);
    HINSTANCE hGetProcIDDLL = LoadLibrary(dir + "XEditLib.dll");
    
    if (!hGetProcIDDLL) {
        log("Failed to to load " + dir + "XEditLib.dll")
        return EXIT_FAILURE;
    }

    for (int i = 0; i< NUM_FUNCTIONS; i++) {
        func_ptr[i] = GetProcAddress(hinst_mydll, FUNCTION_NAMES[i]);
    
        if (func_ptr[i] == NULL) {
            log("Failed to to bind XEditLib.dll:" + FUNCTION_NAMES[i]);
            return EXIT_FAILURE;
        }
    }
}