#include "worker.h"

Worker::Worker(Inventory &anInventory, Score &anScore) : 
    inventory(anInventory), score(anScore) {}

void Worker::operator()() {
    
}