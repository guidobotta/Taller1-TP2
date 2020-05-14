#include "inventory.h"

Inventory::Inventory() : isClosed(false) {}

void Inventory::add(const Resource *item) {
    std::unique_lock<std::mutex> lk(mux);
    ResType type = (*item).getResourceType();

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

    this->condVar.notify_all();
}

bool Inventory::enoughMaterials(int trigo, int madera, int carbon, int hierro) {
    bool isEnough = true;
    isEnough = isEnough && (this->getTrigoAmount() >= trigo);
    isEnough = isEnough && (this->getMaderaAmount() >= madera);
    isEnough = isEnough && (this->getCarbonAmount() >= carbon);
    isEnough = isEnough && (this->getHierroAmount() >= hierro);
    return isEnough;
}

void Inventory::getDelete(int trigo, int madera, int carbon, int hierro) {
    for (int i = 0; i < trigo; i++) {
        delete(triList.back());
        triList.pop_back();
    }

    for (int i = 0; i < madera; i++) {
        delete(madList.back());
        madList.pop_back();
    }

    for (int i = 0; i < carbon; i++) {
        delete(carList.back());
        carList.pop_back();
    }

    for (int i = 0; i < hierro; i++) {
        delete(hieList.back());
        hieList.pop_back();
    }
}

bool Inventory::take(int trigo, int madera, int carbon, int hierro) {
    std::unique_lock<std::mutex> lk(mux);

    while (!this->enoughMaterials(trigo, madera, carbon, hierro)) {
        if (this->isClosed) {
            return false;
        }
        condVar.wait(lk);
    }

    this->getDelete(trigo, madera, carbon, hierro);
    return true;
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

void Inventory::close() {
    this->isClosed = true;
    this->condVar.notify_all();
}

Inventory::~Inventory() {
    while (!this->triList.empty()) {
        delete(triList.back());
        triList.pop_back();
    }
    while (!this->madList.empty()) {
        delete(madList.back());
        madList.pop_back();
    }
    while (!this->carList.empty()) {
        delete(carList.back());
        carList.pop_back();
    }
    while (!this->hieList.empty()) {
        delete(hieList.back());
        hieList.pop_back();
    }
}
