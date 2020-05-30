#ifndef __COLLECTOR_MANAGER_H__
#define __COLLECTOR_MANAGER_H__

#include <string>
#include <vector>
#include <thread>
#include <fstream>

#include "res_blocking_queue.h"
#include "inventory.h"
#include "collector.h"

class CollectorManager {
    private:
        std::vector <Collector> collectorList;
        ResBlockingQueue &wheatQueue;
        ResBlockingQueue &woodQueue;
        ResBlockingQueue &coalIronQueue;
        Inventory &inventory;

    public:
        CollectorManager(ResBlockingQueue &aWheatQueue, 
                         ResBlockingQueue &aWoodQueue, 
                         ResBlockingQueue &aCoalIronQueue, 
                         Inventory &anInventory);
        void addCollector(const std::string &type, int amount);
        void run();
        void join();
};

#endif
