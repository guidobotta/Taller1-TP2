#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#define TRIGO 0
#define MADERA 1
#define CARBON 2
#define HIERRO 3

typedef const int ResIndex;

class Resource {
    protected:
        ResIndex resourceType;

    public:
        Resource(ResIndex aResourceType) : resourceType(aResourceType) {}
        virtual ResIndex getResourceType() = 0;
};

#endif
