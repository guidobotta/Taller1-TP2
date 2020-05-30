#ifndef __MAP_READER_H__
#define __MAP_READER_H__

#include "res_blocking_queue.h"
#include <fstream>

class MapReader {
    private: 
        std::ifstream &mapFile;
        ResBlockingQueue &triQueue;
        ResBlockingQueue &madQueue;
        ResBlockingQueue &carHieQueue;

    public:
        MapReader(std::ifstream &mapFile, ResBlockingQueue &aTriQueue,
                ResBlockingQueue &aMadQueue, ResBlockingQueue &aCarHieQueue);
        void run();
};

#endif
