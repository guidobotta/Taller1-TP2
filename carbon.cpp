#include "carbon.h"

Carbon::Carbon() : Resource(CARBON) {}

ResIndex Carbon::getResourceType() const {
    return this->resourceType;
}
