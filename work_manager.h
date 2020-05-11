#ifndef __WORK_MANAGER_H__
#define __WORK_MANAGER_H__

#include <string>
#include <list>
#include <thread>

#include "inventory.h"
#include "score.h"

class WorkManager {
    private:
        std::list <std::thread> workerList;

    public:
        WorkManager(const std::string &strConfig, Inventory &inventory, 
                    Score &score);
};

#endif
