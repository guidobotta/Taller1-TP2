#ifndef __WORKER_H__
#define __WORKER_H__

#include "real_worker.h"

class Worker {
    private:
        RealWorker *worker;

    public:
        Worker(Inventory &anInventory, Score &anScore, 
                const WorkType &aWorkType);
        Worker(Worker&& other);
        ~Worker();
        Worker& operator=(Worker&& other);
        bool operator==(const Worker &other);
        void start();
        void join();
};

#endif
