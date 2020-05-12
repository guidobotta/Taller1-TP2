#include "work_manager.h"
#include "worker.h"

void WorkManager::findStartWorker(const std::string &strConfig, 
                                Inventory &inventory, Score &score,
                                const std::string &tipo, WorkManager *wM,
                                const WorkType &aWorkType) {
    std::string::size_type wordIndex;
    int nWorkers;
    wordIndex = strConfig.find(tipo);
    nWorkers = std::stoi(strConfig.substr(wordIndex + tipo.length() + 1));
    for (int i = 0; i < nWorkers; i++) {
        wM->workerList.push_back(std::thread { Worker(inventory, score, 
                                                aWorkType) } );
    }
}

WorkManager::WorkManager(const std::string &strConfig, Inventory &inventory, 
                        Score &score) {
    findStartWorker(strConfig, inventory, score, "Cocineros", this, COCINERO);
    findStartWorker(strConfig, inventory, score, "Carpinteros", this, 
                    CARPINTERO);
    findStartWorker(strConfig, inventory, score, "Armeros", this, ARMERO);
}

void WorkManager::join() {
    for (int i = 0; i < this->workerList.size(); i++) {
        this->workerList[i].join();
    }
}
