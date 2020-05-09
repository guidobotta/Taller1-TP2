#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <list>
#include <mutex>
#include "resource.h"
#include "trigo.h"
#include "madera.h"
#include "carbon.h"
#include "hierro.h"

class Inventory {
    private:
        std::list <const Trigo*> triList;
        std::list <const Madera*> madList;
        std::list <const Carbon*> carList;
        std::list <const Hierro*> hieList;
        std::mutex mux;

    public:
        void add(const Resource *item);
        void add(const Trigo *item);
        void add(const Madera *item);
        void add(const Carbon *item);
        void add(const Hierro *item);
};

#endif
