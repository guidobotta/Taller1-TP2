#include "work_manager.h"

WorkManager::WorkManager(const std::string &strConfig) {
    //BUSCAR CADA TRABAJADOR Y CREAR SU RESPECTIVO HILO

    std::string::size_type wordIndex;
    int nWorkers;

    wordIndex = strConfig.find("Agricultores");
    nWorkers = std::stoi(strConfig.substr(wordIndex + 13, 1));
    for (int i = 0; i < nWorkers; i++) {
        std::thread tWorker(/*algo*/); //problema poniendo los ()
        this->workerList.push_back(tWorker);
    }
    wordIndex = strConfig.find("Leniadores");
    nWorkers = std::stoi(strConfig.substr(wordIndex + 11, 1));
    for (int i = 0; i < nWorkers; i++) {
        std::thread tWorker(/*algo*/);
        this->workerList.push_back(tWorker);
    }
    wordIndex = strConfig.find("Mineros");
    nWorkers = std::stoi(strConfig.substr(wordIndex + 8, 1));
    for (int i = 0; i < nWorkers; i++) {
        std::thread tWorker(/*algo*/);
        this->workerList.push_back(tWorker);
    }
    wordIndex = strConfig.find("Cocineros");
    nWorkers = std::stoi(strConfig.substr(wordIndex + 10, 1));
    for (int i = 0; i < nWorkers; i++) {
        std::thread tWorker(/*algo*/);
        this->workerList.push_back(tWorker);
    }
    wordIndex = strConfig.find("Carpinteros");
    nWorkers = std::stoi(strConfig.substr(wordIndex + 12, 1));
    for (int i = 0; i < nWorkers; i++) {
        std::thread tWorker(/*algo*/);
        this->workerList.push_back(tWorker);
    }
    wordIndex = strConfig.find("Armeros");
    nWorkers = std::stoi(strConfig.substr(wordIndex + 8, 1));
    for (int i = 0; i < nWorkers; i++) {
        std::thread tWorker(/*algo*/);
        this->workerList.push_back(tWorker);
    }
}