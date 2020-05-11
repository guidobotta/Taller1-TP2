#ifndef __WORK_MANAGER_H__
#define __WORK_MANAGER_H__

#include <string>
#include <vector>
#include <thread>

#include "inventory.h"
#include "score.h"

class WorkManager {
    private:
        std::vector <std::thread> workerList;
        static void findStartWorker(const std::string &strConfig, 
                                Inventory &inventory, Score &score,
                                const std::string &tipo, WorkManager *wM);

    public:
        WorkManager(const std::string &strConfig, Inventory &inventory, 
                    Score &score);
        void join();
};

#endif
