#ifndef __COLLECTOR_H__
#define __COLLECTOR_H__

#include "res_blocking_queue.h"
#include "inventory.h"

/*
 * Clase Recolector relacionada con
 * la salida de la ColaBloqueante y
 * con la entrada del Inventario
*/
class Collector {
    private:
        ResBlockingQueue &resQueue;
        Inventory &inventory;

    public:
        Collector(ResBlockingQueue &aResQueue, Inventory &anInventory);
        void operator()();
};

#endif
