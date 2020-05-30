#include "worker.h"
#include "empty_exception.h"
#include <exception>
#include <unistd.h>
#include <iostream>

Worker::Worker(Inventory &anInventory, Score &anScore, 
                const WorkType &aWorkType) {
    this->worker = new RealWorker(anInventory, anScore, aWorkType);
}

Worker::Worker(Worker&& other) {
    this->worker = other.worker;
    other.worker = nullptr;
}

Worker::~Worker() {
    delete(this->worker);
}

Worker& Worker::operator=(Worker&& other) {
    if (this == &other) {
        return *this;
    }

    if ((this->worker != other.worker) && (this->worker)) {
        delete(this->worker);
    }

    this->worker = other.worker;
    other.worker = nullptr;

    return *this;
}

bool Worker::operator==(const Worker &other) {
    return this->worker == other.worker;
}

void Worker::start() {
    this->worker->start();
}

void Worker::join() {
    this->worker->join();
}
