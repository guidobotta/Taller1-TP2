#ifndef __WORKER_H__
#define __WORKER_H__

#include "inventory.h"
#include "score.h"

/*
 * Clase Trabajadora relacionada con
 * la salida del Inventario y con la
 * puntuación final.
*/
class Worker {
    private:
        Inventory &inventory;
        Score &score;

    public:
        Worker(Inventory &anInventory, Score &anScore);
        void operator()();
};

#endif
