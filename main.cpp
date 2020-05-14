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

int work(char const *argv[], ResBlockingQueue &trigoQueue, 
        ResBlockingQueue &maderaQueue, ResBlockingQueue &carHieQueue,
        Inventory &inventory, Score &finalScore) {
    FileReader fileWorkers(argv[1]);
    std::string completeStr;
    fileWorkers.getCompleteFile(completeStr);

    WorkManager workManager(completeStr, inventory, finalScore); 

    CollectorManager collectorManager(completeStr, trigoQueue, maderaQueue, 
                                    carHieQueue, inventory);

    FileReader fileMap(argv[2]);
    std::thread map {MapReader(fileMap, trigoQueue, maderaQueue, carHieQueue)};

    map.join();

    trigoQueue.close();
    maderaQueue.close();
    carHieQueue.close();

    collectorManager.join();

    inventory.close();

    workManager.join();

    return SUCCESS;
}

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        std::cout << "Error en la cantidad de parámetros.\n";
        return ERROR;
    }

    ResBlockingQueue trigoQueue;
    ResBlockingQueue maderaQueue;
    ResBlockingQueue carHieQueue;

    Inventory inventory;

    Score finalScore(inventory);

    if (work(argv, trigoQueue, maderaQueue, carHieQueue, inventory, finalScore)
        == ERROR) {
        return ERROR;
    }

    finalScore.printScore();

    return SUCCESS;
}
