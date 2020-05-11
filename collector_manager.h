#ifndef __COLLECTOR_MANAGER_H__
#define __COLLECTOR_MANAGER_H__

#include <string>
#include <list>
#include <thread>

#include "res_blocking_queue.h"
#include "inventory.h"

class CollectorManager {
    private:
        std::list <std::thread> collectorList;

    public:
        CollectorManager(const std::string &strConfig, 
                ResBlockingQueue &trigoQueue, ResBlockingQueue &maderaQueue, 
                ResBlockingQueue &carHieQueue, Inventory &inventory);
};

#endif
