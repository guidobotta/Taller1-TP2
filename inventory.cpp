#include "inventory.h"

void Inventory::add(const Resource *item) {
    std::unique_lock<std::mutex> lk(mux);
    (*item).add(this);
}

void Inventory::add(const Trigo *item) {
    triList.push_back(item);
}

void Inventory::add(const Madera *item) {
    madList.push_back(item);
}

void Inventory::add(const Carbon *item) {
    carList.push_back(item);
}

void Inventory::add(const Hierro *item) {
    hieList.push_back(item);
}
