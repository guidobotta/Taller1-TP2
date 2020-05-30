#include "main_controller.h"
#include <string>
#include <sstream>

MainController::MainController(std::ifstream &workersFile, 
                                std::ifstream &mapFile) :
                            workManager(inventory, finalScore),
                            collectorManager(wheatQueue, woodQueue,
                                             coalIronQueue, inventory),
                            map(mapFile, wheatQueue, woodQueue, coalIronQueue) {
    std::string line;
    while (std::getline(workersFile, line)) {
        std::istringstream iss(line);
        std::string type;
        int amount;
        std::getline(iss, type, '=');
        iss >> amount;
        if (type == "Cocineros" || type == "Carpinteros" || type == "Armeros") {
            this->workManager.addWorker(type, amount);
        } else if (type == "Agricultores" || type == "Leniadores" || 
                   type == "Mineros") {
            this->collectorManager.addCollector(type, amount);
        }
    }
}

void MainController::run() {
    this->workManager.run();
    this->collectorManager.run();
    this->map.run();
}

MainController::~MainController() {
    this->wheatQueue.close();
    this->woodQueue.close();
    this->coalIronQueue.close();

    this->collectorManager.join();

    this->inventory.close();

    this->workManager.join();

    this->inventory.printResources();
    this->finalScore.printScore();
}
