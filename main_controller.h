#ifndef __MAIN_CONTROLLER_H__
#define __MAIN_CONTROLLER_H__

#include "res_blocking_queue.h"
#include "inventory.h"
#include "score.h"
#include "work_manager.h"
#include "collector_manager.h"
#include "map_reader.h"
#include <fstream>

class MainController {
    private:
        ResBlockingQueue wheatQueue;
        ResBlockingQueue woodQueue;
        ResBlockingQueue carHieQueue;
        Inventory inventory;
        Score finalScore;
        WorkManager workManager;
        CollectorManager collectorManager;
        MapReader map;

    public:
        MainController(std::ifstream &aWorkersFile, std::ifstream &aMapFile);
        ~MainController();
        void run();
};

#endif