#include "work_manager.h"
#include "worker.h"

void WorkManager::findStartWorker(const std::string &strConfig, 
                                Inventory &inventory, Score &score,
                                const std::string &tipo, WorkManager *wM) {
    std::string::size_type wordIndex;
    int nWorkers;
    wordIndex = strConfig.find(tipo);
    nWorkers = std::stoi(strConfig.substr(wordIndex + tipo.length()));
    for (int i = 0; i < nWorkers; i++) {
        std::thread tWorker { Worker(inventory, score) };
        wM->workerList.push_back(tWorker);
    }
}

WorkManager::WorkManager(const std::string &strConfig, Inventory &inventory, 
                        Score &score) {
    findStartWorker(strConfig, inventory, score, "Cocineros", this);
    findStartWorker(strConfig, inventory, score, "Carpinteros", this);
    findStartWorker(strConfig, inventory, score, "Armeros", this);
}

void WorkManager::join() {
    for (int i = 0; i < this->workerList.size(); i++) {
        this->workerList[i].join();
    }
}
