#ifndef __TRIGO_H__
#define __TRIGO_H__

#include "inventory.h"
#include "resource.h"

class Trigo : public Resource {
    private:

    public:
        Trigo();
        virtual ResIndex getResourceType() const;
};

#endif