#include "hierro.h"

void Hierro::add(Inventory *inv) const {
    (*inv).add(this);
}
