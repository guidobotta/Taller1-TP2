#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <list>
#include <mutex>
#include <condition_variable>
#include "resource.h"

class Inventory {
    private:
        std::list <const Resource*> triList;
        std::list <const Resource*> madList;
        std::list <const Resource*> carList;
        std::list <const Resource*> hieList;
        std::mutex mux;
        std::condition_variable condVar;
        bool isClosed;
        bool enoughMaterials(int trigo, int madera, int carbon, int hierro);
        void getDelete(int trigo, int madera, int carbon, int hierro);

    public:
        Inventory();
        void add(const Resource *item);
        bool take(int trigo, int madera, int carbon, int hierro);
        int getTrigoAmount();
        int getMaderaAmount();
        int getCarbonAmount();
        int getHierroAmount();
        void close();
        void clean();
};

#endif
