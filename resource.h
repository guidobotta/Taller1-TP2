#ifndef __RESOURCE_H__
#define __RESOURCE_H__

enum ResType {TRIGO, MADERA, CARBON, HIERRO};

class Resource {
    protected:
        const ResType resourceType;

    public:
        explicit Resource(const ResType &aResourceType);
        virtual ResType getResourceType() const;
};

#endif
