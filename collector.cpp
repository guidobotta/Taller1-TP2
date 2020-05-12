#include "collector.h"
#include <unistd.h>

#include <iostream>

Collector::Collector(ResBlockingQueue &aResQueue, Inventory &anInventory) : 
    inventory(anInventory), resQueue(aResQueue) {}

void Collector::operator()() {
    const Resource *resource = this->resQueue.pop();
    while(resource != NULL) {
        usleep(60000);
        inventory.add(resource);
        resource = this->resQueue.pop();
    }
}
