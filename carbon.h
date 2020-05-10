#ifndef __CARBON_H__
#define __CARBON_H__

#include "inventory.h"
#include "resource.h"

class Carbon : public Resource {
    private:

    public:
        Carbon();
        virtual ResIndex getResourceType() const;
};

#endif
