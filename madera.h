#ifndef __MADERA_H__
#define __MADERA_H__

#include "inventory.h"
#include "resource.h"

class Madera : public Resource {
    private:

    public:
        Madera();
        virtual ResIndex getResourceType() const;
};

#endif
