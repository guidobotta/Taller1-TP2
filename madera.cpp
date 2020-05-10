#include "madera.h"

Madera::Madera() : Resource(MADERA) {}

ResIndex Madera::getResourceType() const {
    return this->resourceType;
}
