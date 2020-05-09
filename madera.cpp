#include "madera.h"

void Madera::add(Inventory *inv) const{
    (*inv).add(this);
}
