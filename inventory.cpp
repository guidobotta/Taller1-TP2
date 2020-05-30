#include "inventory.h"
#include <iostream>

Inventory::Inventory() : wheatAmount(0), woodAmount(0), coalAmount(0),
                         ironAmount(0), closed(false) {}

void Inventory::add(const Resource &item) {
    std::unique_lock<std::mutex> lk(mux);
    ResType type = item.getResourceType();

    switch (type) {
    case WHEAT:
        wheatAmount++;
        break;
    case WOOD:
        woodAmount++;
        break;
    case COAL:
        coalAmount++;
        break; 
    case IRON:
        ironAmount++;
        break;
    }

    this->condVar.notify_all();
}

bool Inventory::enoughMaterials(int wheat, int wood, int coal, int iron) {
    bool isEnough = true;
    isEnough = isEnough && (this->wheatAmount >= wheat);
    isEnough = isEnough && (this->woodAmount >= wood);
    isEnough = isEnough && (this->coalAmount >= coal);
    isEnough = isEnough && (this->ironAmount >= iron);
    return isEnough;
}

void Inventory::decreaseAmount(int wheat, int wood, int coal, int iron) {
    this->wheatAmount -= wheat;
    this->woodAmount -= wood;
    this->coalAmount -= coal;
    this->ironAmount -= iron;
}

bool Inventory::take(int wheat, int wood, int coal, int iron) {
    std::unique_lock<std::mutex> lk(mux);

    while (!this->enoughMaterials(wheat, wood, coal, iron)) {
        if (this->closed) {
            return false; /*throw EmptyException();*/
        }
        condVar.wait(lk);
    }

    this->decreaseAmount(wheat, wood, coal, iron);
    return true;
}

void Inventory::printResources() {
    std::cout << "Recursos restantes:" << std::endl;
    std::cout << "  - Trigo: " << this->wheatAmount  << std::endl;
    std::cout << "  - Madera: " << this->woodAmount << std::endl;
    std::cout << "  - Carbon: " << this->coalAmount << std::endl;
    std::cout << "  - Hierro: " << this->ironAmount << std::endl;
    std::cout << std::endl;
}

void Inventory::close() {
    std::unique_lock<std::mutex> lk(mux);
    this->closed = true;
    this->condVar.notify_all();
}

Inventory::~Inventory() {}