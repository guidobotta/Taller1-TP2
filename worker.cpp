#include "worker.h"
#include <unistd.h>

Worker::Worker(Inventory &anInventory, Score &anScore, 
                const WorkType &aWorkType) : inventory(anInventory), 
                                        score(anScore), workType(aWorkType) {}

void Worker::operator()() {
    bool invActive = true;
    while (invActive) {
        switch (this->workType) {
        case COCINERO:
            if ((invActive = this->inventory.take(2, 0, 1, 0))) {
                this->score.addToScore(5);
            }
            break;
        case CARPINTERO:
            if ((invActive = this->inventory.take(0, 3, 0, 1))) {
                this->score.addToScore(2);
            }
            break;
        case ARMERO:
            if ((invActive = this->inventory.take(0, 0, 2, 2))) {
                this->score.addToScore(3);
            }
            break;
        }
        usleep(60000);
    }
}
