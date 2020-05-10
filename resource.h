#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#define TRIGO 0
#define MADERA 1
#define CARBON 2
#define HIERRO 3

typedef const int ResIndex;

class Resource {
    protected:
        const ResIndex resourceType;

    public:
        Resource(const ResIndex &aResourceType) : resourceType(aResourceType) {}
        virtual ResIndex getResourceType() const = 0;
};

#endif
