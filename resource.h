#ifndef __RESOURCE_H__
#define __RESOURCE_H__

enum ResType {WHEAT, WOOD, COAL, IRON};

class Resource {
    protected:
        ResType resourceType;

    public:
        explicit Resource(const ResType &aResourceType);
        Resource(const Resource& other) = delete;
        Resource(const Resource&& other);
        Resource& operator=(Resource&& other);
        ResType getResourceType() const;
};

#endif
