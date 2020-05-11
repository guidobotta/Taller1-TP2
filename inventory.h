#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <list>
#include <mutex>
#include "resource.h"

class Inventory {
    private:
        std::list <const Resource*> triList;
        std::list <const Resource*> madList;
        std::list <const Resource*> carList;
        std::list <const Resource*> hieList;
        std::mutex mux;
        bool isClosed;

    public:
        Inventory();
        void add(const Resource *item);
        int getTrigoAmount();
        int getMaderaAmount();
        int getCarbonAmount();
        int getHierroAmount();
        void close();
};

#endif
