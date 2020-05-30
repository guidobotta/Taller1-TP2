#ifndef __MAP_READER_H__
#define __MAP_READER_H__

#include "res_blocking_queue.h"
#include <fstream>

class MapReader {
    private: 
        std::ifstream &mapFile;
        ResBlockingQueue &wheatQueue;
        ResBlockingQueue &woodQueue;
        ResBlockingQueue &coalIronQueue;

    public:
        MapReader(std::ifstream &mapFile, ResBlockingQueue &aWheatQueue,
                ResBlockingQueue &aWoodQueue, ResBlockingQueue &aCoalIronQueue);
        void run();
};

#endif
