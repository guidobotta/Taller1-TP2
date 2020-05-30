#include "resource.h"

Resource::Resource(const ResType &aResourceType) : resourceType(aResourceType)
    {}

Resource::Resource(const Resource&& other) : resourceType(other.resourceType) {}

Resource& Resource::operator=(Resource&& other) {
    this->resourceType = other.resourceType;
    return *this;
}

ResType Resource::getResourceType() const {
    return this->resourceType;
}
