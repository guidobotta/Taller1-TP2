#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <list>
#include <mutex>
#include <condition_variable>
#include "resource.h"

class Inventory {
    private:
        int wheatAmount;
        int woodAmount;
        int coalAmount;
        int ironAmount;
        std::mutex mux;
        std::condition_variable condVar;
        bool closed;
        bool enoughMaterials(int wheat, int wood, int coal, int iron);
        void decreaseAmount(int wheat, int wood, int coal, int iron);

    public:
        Inventory();
        void add(const Resource &item);
        bool take(int wheat, int wood, int coal, int iron);
        int getWheatAmount();
        int getWoodAmount();
        int getCoalAmount();
        int getIronAmount();
        void printResources();
        void close();
        ~Inventory();
};

#endif
