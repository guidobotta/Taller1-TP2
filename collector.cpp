#include "collector.h"

Collector::Collector(ResBlockingQueue &aResQueue, Inventory &anInventory) {
    this->collector = new RealCollector(aResQueue, anInventory);
}

Collector::Collector(Collector&& other) {
    this->collector = other.collector;
    other.collector = nullptr;
}

Collector::~Collector() {
    delete(this->collector);
}

Collector& Collector::operator=(Collector&& other) {
    if (this == &other) {
        return *this;
    }

    if ((this->collector != other.collector) && (this->collector)) {
        delete(this->collector);
    }

    this->collector = other.collector;
    other.collector = nullptr;

    return *this;
}

bool Collector::operator==(const Collector &other) {
    return this->collector == other.collector;
}

void Collector::start() {
    this->collector->start();
}

void Collector::join() {
    this->collector->join();
}
