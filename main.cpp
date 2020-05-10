#include "resource.h"
#include "trigo.h"
#include "madera.h"
#include "carbon.h"
#include "hierro.h"
#include "res_blocking_queue.h"
#include "reading_file.h"
#include "work_manager.h"
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

    //inicializar workers
    ReadingFile fileWorkers(argv[1]);
    
    std::string completeStr;
    fileWorkers.getCompleteFile(completeStr);

    WorkManager workManager(completeStr);
    
    //leer mapa y empezar a enviar datos a las colas
    ReadingFile fileMap(argv[2]);

    //iniciarlizar la salida out

    //join threads
    //join map, colas, inv, recolec, trabaj

    return 0;
}