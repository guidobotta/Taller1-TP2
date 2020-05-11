#ifndef __MAP_READER_H__
#define __MAP_READER_H__

#include "res_blocking_queue.h"
#include "file_reader.h"

class MapReader {
    private: 
        FileReader &fileReader;
        ResBlockingQueue &triQueue;
        ResBlockingQueue &madQueue;
        ResBlockingQueue &carHieQueue;

    public:
        MapReader(FileReader &aFileReader, ResBlockingQueue &aTriQueue,
                ResBlockingQueue &aMadQueue, ResBlockingQueue &aCarHieQueue);
        void operator()();
};

#endif
