#ifndef __COLLECTOR_MANAGER_H__
#define __COLLECTOR_MANAGER_H__

#include <string>
#include <vector>
#include <thread>

#include "res_blocking_queue.h"
#include "inventory.h"

class CollectorManager {
    private:
        std::vector <std::thread> collectorList;
        static void findStartCollector(const std::string &strConfig, 
                                ResBlockingQueue &queue, Inventory &inventory, 
                                const std::string &tipo, CollectorManager *cM);

    public:
        CollectorManager(const std::string &strConfig, 
                ResBlockingQueue &trigoQueue, ResBlockingQueue &maderaQueue, 
                ResBlockingQueue &carHieQueue, Inventory &inventory);
        void join();
};

#endif
