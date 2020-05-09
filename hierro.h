#ifndef __HIERRO_H__
#define __HIERRO_H__

#include "resource.h"

class Hierro : public Resource {
    private:

    public:
        virtual void add(Inventory *inv) const;
};

#endif
