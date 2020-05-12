#include "collector_manager.h"
#include "collector.h"

void CollectorManager::findStartCollector(const std::string &strConfig, 
                            ResBlockingQueue &queue, Inventory &inventory,
                            const std::string &tipo, CollectorManager *cM) {
    std::string::size_type wordIndex;
    int nCollectors;
    wordIndex = strConfig.find(tipo);
    nCollectors = std::stoi(strConfig.substr(wordIndex + tipo.length() + 1));
    for (int i = 0; i < nCollectors; i++) {
        cM->collectorList.push_back(std::thread {Collector(queue, inventory)});
    }
}

CollectorManager::CollectorManager(const std::string &strConfig, 
                ResBlockingQueue &trigoQueue, ResBlockingQueue &maderaQueue, 
                ResBlockingQueue &carHieQueue, Inventory &inventory) {
    findStartCollector(strConfig, trigoQueue, inventory, "Agricultores", this);
    findStartCollector(strConfig, maderaQueue, inventory, "Leniadores", this);
    findStartCollector(strConfig, carHieQueue, inventory, "Mineros", this);
}

void CollectorManager::join() {
    for (int i = 0; i < this->collectorList.size(); i++) {
        this->collectorList[i].join();
    }
}
