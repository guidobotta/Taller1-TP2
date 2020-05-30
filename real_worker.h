#ifndef __REAL_WORKER_H__
#define __REAL_WORKER_H__

#include "inventory.h"
#include "score.h"
#include "thread.h"

enum WorkType {COCINERO, CARPINTERO, ARMERO};

/*
 * Clase Trabajadora relacionada con
 * la salida del Inventario y con la
 * puntuación final.
*/
class RealWorker : public Thread {
    private:
        Inventory &inventory;
        Score &score;
        const WorkType workType;

    public:
        RealWorker(Inventory &anInventory, Score &anScore, 
                const WorkType &aWorkType);
        void run();
};

#endif
