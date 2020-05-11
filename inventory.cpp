#include "inventory.h"

void Inventory::add(const Resource *item) {
    std::unique_lock<std::mutex> lk(mux);
    ResIndex type = (*item).getResourceType();

    switch (type) {
    case TRIGO:
        this->triList.push_back(item);
        break;
    case MADERA:
        this->madList.push_back(item);
        break;
    case CARBON:
        this->carList.push_back(item);
        break; 
    case HIERRO:
        this->hieList.push_back(item);
        break;
    }
}

int Inventory::getTrigoAmount() {
    return this->triList.size();
}

int Inventory::getMaderaAmount() {
    return this->madList.size();
}

int Inventory::getCarbonAmount() {
    return this->carList.size();
}

int Inventory::getHierroAmount() {
    return this->hieList.size();
}