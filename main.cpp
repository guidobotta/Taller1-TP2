#include "resource.h"
#include "res_blocking_queue.h"
#include "file_reader.h"
#include "work_manager.h"
#include "score.h"
#include "collector_manager.h"
#include "map_reader.h"
#include <iostream>
#include <thread>
#include <string>

#define SUCCESS 0
#define ERROR 1

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        std::cout << "Error en la cantidad de parámetros.\n";
        return ERROR;
    }

    //inicializar colas
    ResBlockingQueue trigoQueue;
    ResBlockingQueue maderaQueue;
    ResBlockingQueue carHieQueue;

    //inicializar inventario
    Inventory inventory;

    //inicializar salida
    Score finalScore(inventory);

    //leo archivo de recolectores y trabajadores
    FileReader fileWorkers(argv[1]);    
    std::string completeStr;
    fileWorkers.getCompleteFile(completeStr);

    //inicializo trabajadores
    WorkManager workManager(completeStr, inventory, finalScore); 

    //incializo recolectores
    CollectorManager collectorManager(completeStr, trigoQueue, maderaQueue, 
                                    carHieQueue, inventory);

    //inicializar thread mapeo
    FileReader fileMap(argv[2]);
    std::thread map {MapReader(fileMap, trigoQueue, maderaQueue, carHieQueue)};

    //join thread del mapeo

    map.join();

    //cierro colas

    trigoQueue.close();
    maderaQueue.close();
    carHieQueue.close();

    //join thread recolectores

    collectorManager.join();

    //cierro inventario

    inventory.close();

    //join thread de trabajadores

    workManager.join();

    //imprimo salida

    finalScore.printScore();

    return SUCCESS;
}
