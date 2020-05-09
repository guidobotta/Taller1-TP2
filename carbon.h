#ifndef __CARBON_H__
#define __CARBON_H__

#include "resource.h"

class Carbon : public Resource {
    private:

    public:
        Carbon();
        virtual void add(Inventory *inv) const;
};

#endif
