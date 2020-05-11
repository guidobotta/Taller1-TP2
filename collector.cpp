#include "collector.h"

Collector::Collector(ResBlockingQueue &aResQueue, Inventory &anInventory) : 
    inventory(anInventory), resQueue(aResQueue) {}

void Collector::operator()() {
    const Resource *resource = this->resQueue.pop();
    while(resource != NULL)
        inventory.add(resource);
        const Resource *resource = this->resQueue.pop();
}
