#include "work_manager.h"
#include "worker.h"
#include <string>

WorkManager::WorkManager(Inventory &anInventory, Score &aScore) : 
                                    inventory(anInventory), score(aScore) {}

void WorkManager::addWorker(std::string &type, int amount) {
    WorkType workType;
    
    if (type == "Cocineros") {
        workType = COCINERO;
    } else if (type == "Carpinteros") {
        workType = CARPINTERO;
    } else if (type == "Armeros") {
        workType = ARMERO;
    }

    for (int i = 0; i < amount; i++) {
        this->workerList.push_back(Worker(this->inventory, this->score, 
                                          workType));
    }
}

void WorkManager::run() {
    for (std::size_t i = 0; i < this->workerList.size(); i++) {
        this->workerList[i].start();
    }
}

void WorkManager::join() {
    for (std::size_t i = 0; i < this->workerList.size(); i++) {
        this->workerList[i].join();
    }
}
