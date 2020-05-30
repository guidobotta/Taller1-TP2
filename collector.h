#ifndef __COLLECTOR_H__
#define __COLLECTOR_H__

#include "real_collector.h"

class Collector {
    private:
        RealCollector* collector;

    public:
        Collector(ResBlockingQueue &aResQueue, Inventory &anInventory);
        Collector(Collector&& other);
        ~Collector();
        Collector& operator=(Collector&& other);
        bool operator==(const Collector &other);
        void start();
        void join();
};

#endif
