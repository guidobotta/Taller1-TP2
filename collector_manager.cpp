#include "collector_manager.h"

CollectorManager::CollectorManager(const std::string &strConfig, 
                ResBlockingQueue &trigoQueue, ResBlockingQueue &maderaQueue, 
                ResBlockingQueue &carHieQueue, Inventory &inventory) {
    //BUSCAR CADA TRABAJADOR Y CREAR SU RESPECTIVO HILO

    std::string::size_type wordIndex;
    int nWorkers;

    wordIndex = strConfig.find("Agricultores");
    nWorkers = std::stoi(strConfig.substr(wordIndex + 13, 1));
    for (int i = 0; i < nWorkers; i++) {
        std::thread tWorker;
        this->collectorList.push_back(tWorker);
        tWorker();
    }
}