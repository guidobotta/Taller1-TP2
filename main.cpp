#include "main_controller.h"
#include "os_error.h"
#include <iostream>
#include <fstream>

#define SUCCESS 0
#define ERROR 1

int main(int argc, char const *argv[]) {
    try {
        if (argc != 3) {
            throw OSError("Error: cantidad de parámetros incorrecta");
        }

        std::ifstream workersFile(argv[1]);
        if (!workersFile.is_open()) {
            throw OSError("Error: no pudo abrirse archivo de trabajadores");
        }

        std::ifstream mapFile(argv[2]);
        if (!mapFile.is_open()) {
            throw OSError("Error: no pudo abrirse archivo de mapa");
        }

        MainController mainController(workersFile, mapFile);
        mainController.run();
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return ERROR;
    } catch(...) {
        std::cerr << "Error: unknown" << std::endl;
        return ERROR;
    }

    return SUCCESS;
}
