#ifndef __WORK_MANAGER_H__
#define __WORK_MANAGER_H__

#include <string>
#include <vector>
#include <fstream>

#include "inventory.h"
#include "score.h"
#include "worker.h"

class WorkManager {
    private:
        std::vector <Worker> workerList;
        Inventory &inventory;
        Score &score;

    public:
        WorkManager(Inventory &anInventory, Score &aScore);
        void addWorker(std::string &type, int amount);
        void run();
        void join();
};

#endif
