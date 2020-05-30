#include "collector_manager.h"
#include "collector.h"
#include <string>

CollectorManager::CollectorManager(ResBlockingQueue &aWheatQueue, 
                                   ResBlockingQueue &aWoodQueue, 
                                   ResBlockingQueue &aCoalIronQueue, 
                                   Inventory &anInventory) : 
                                   wheatQueue(aWheatQueue),
                                   woodQueue(aWoodQueue),
                                   coalIronQueue(aCoalIronQueue),
                                   inventory(anInventory) {}

void CollectorManager::addCollector(const std::string &type, int amount) {
    ResBlockingQueue *queue = nullptr;

    if (type == "Agricultores") {
        queue = &this->wheatQueue;
    } else if (type == "Leniadores") {
        queue = &this->woodQueue;
    } else if (type == "Mineros") {
        queue = &this->coalIronQueue;
    }

    for (int i = 0; i < amount; i++) {
        this->collectorList.push_back(Collector(*queue, this->inventory));
    }
}

void CollectorManager::run() {
    for (std::size_t i = 0; i < this->collectorList.size(); i++) {
        this->collectorList[i].start();
    }
}

void CollectorManager::join() {
    for (std::size_t i = 0; i < this->collectorList.size(); i++) {
        this->collectorList[i].join();
    }
}
