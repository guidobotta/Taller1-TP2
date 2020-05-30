#include "main_controller.h"
#include <iostream>
#include <fstream>

#define SUCCESS 0
#define ERROR 1

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        std::cout << "Error en la cantidad de parámetros.\n";
        return ERROR;
    }

    std::ifstream workersFile(argv[1]);
    if (!workersFile.is_open()) return ERROR/*throw excepcion*/;
    std::ifstream mapFile(argv[2]);
    if (!mapFile.is_open()) return ERROR/*throw excepcion*/;

    MainController mainController(workersFile, mapFile);
    mainController.run();

    return SUCCESS;
}
