#ifndef __REAL_COLLECTOR_H__
#define __REAL_COLLECTOR_H__

#include "res_blocking_queue.h"
#include "inventory.h"
#include "thread.h"

/*
 * Clase Collector relacionada con
 * la salida de la ColaBloqueante y
 * con la entrada del Inventario
*/
class RealCollector : public Thread {
    private:
        ResBlockingQueue &resQueue;
        Inventory &inventory;

    public:
        RealCollector(ResBlockingQueue &aResQueue, Inventory &anInventory);
        void run();
};

#endif
