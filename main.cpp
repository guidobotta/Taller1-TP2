#include "resource.h"
#include "trigo.h"
#include "madera.h"
#include "carbon.h"
#include "hierro.h"
#include "res_blocking_queue.h"
#include "reading_file.h"
#include "work_manager.h"
#include "score.h"
#include "collector_manager.h"
#include <iostream>
#include <thread>

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
    ReadingFile fileWorkers(argv[1]);
    
    std::string completeStr;
    fileWorkers.getCompleteFile(completeStr);

    //incializo recolectores
    CollectorManager collectorManager(completeStr, trigoQueue, maderaQueue, 
                                    carHieQueue, inventory);

    //inicializo trabajadores
    WorkManager workManager(completeStr, inventory, finalScore);
    /* FALTA COMPLETAR FUNCIONALIDAD DE LOS TRABAJADORES Y DEL INVENTARIO */

    //inicializar thread mapeo
    ReadingFile fileMap(argv[2]);





    //join thread del mapeo

    

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
