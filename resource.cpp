#include "resource.h"

Resource::Resource(const ResType &aResourceType) : resourceType(aResourceType)
    {}

ResType Resource::getResourceType() const {
    return this->resourceType;
}