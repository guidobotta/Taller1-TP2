#include "real_collector.h"
#include "empty_exception.h"
#include <exception>
#include <unistd.h>
#include <iostream>

RealCollector::RealCollector(ResBlockingQueue &aResQueue, 
                             Inventory &anInventory) : resQueue(aResQueue), 
                                                       inventory(anInventory) {}

void RealCollector::run() {
    try {
        while (true) {
            const Resource resource = this->resQueue.pop();
            usleep(60000);
            inventory.add(resource);
        }
    } catch(const EmptyException& e) {
        // do nothing
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    } catch(...) {
        std::cerr << "Error: unknown" << std::endl;
    }
}
