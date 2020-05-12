#ifndef __WORKER_H__
#define __WORKER_H__

#include "inventory.h"
#include "score.h"

enum WorkType {COCINERO, CARPINTERO, ARMERO};

/*
 * Clase Trabajadora relacionada con
 * la salida del Inventario y con la
 * puntuación final.
*/
class Worker {
    private:
        Inventory &inventory;
        Score &score;
        const WorkType workType;

    public:
        Worker(Inventory &anInventory, Score &anScore, 
                const WorkType &aWorkType);
        void operator()();
};

#endif
