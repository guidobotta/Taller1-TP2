#include "carbon.h"

Carbon::Carbon() : Resource(CARBON) {}

ResIndex Carbon::getResourceType() {
    return this->resourceType;
}
