#include "real_worker.h"
#include "empty_exception.h"
#include <exception>
#include <unistd.h>
#include <iostream>

RealWorker::RealWorker(Inventory &anInventory, Score &anScore, 
                const WorkType &aWorkType) : inventory(anInventory), 
                                        score(anScore), workType(aWorkType) {}

void RealWorker::run() {
    try {
        bool invActive = true;
        while (invActive) {
            switch (this->workType) {
            case COCINERO:
                if ((invActive = this->inventory.take(2, 0, 1, 0))) {
                    usleep(60000);
                    this->score.addToScore(5);
                }
                break;
            case CARPINTERO:
                if ((invActive = this->inventory.take(0, 3, 0, 1))) {
                    usleep(60000);
                    this->score.addToScore(2);
                }
                break;
            case ARMERO:
                if ((invActive = this->inventory.take(0, 0, 2, 2))) {
                    usleep(60000);
                    this->score.addToScore(3);
                }
                break;
            }
        }
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    } catch(...) {
        std::cerr << "Error: unknown" << std::endl;
    }
}
