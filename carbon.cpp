#include "carbon.h"

void Carbon::add(Inventory *inv) const{
    (*inv).add(this);
}
