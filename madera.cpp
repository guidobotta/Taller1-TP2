#include "madera.h"

Madera::Madera() : Resource(MADERA) {}

ResIndex Madera::getResourceType() {
    return this->resourceType;
}
