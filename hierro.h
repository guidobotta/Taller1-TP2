#ifndef __HIERRO_H__
#define __HIERRO_H__

#include "inventory.h"
#include "resource.h"

class Hierro : public Resource {
    private:

    public:
        Hierro();
        virtual ResIndex getResourceType() const;
};

#endif
