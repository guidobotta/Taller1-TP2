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

    public:
        void add(const Resource *item);
};

#endif
