#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#include "inventory.h"

class Resource {
    public:
        virtual void add(Inventory *inv) const = 0;
};

#endif
