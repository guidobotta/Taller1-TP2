#include "trigo.h"

Trigo::Trigo() : Resource(TRIGO) {}

ResIndex Trigo::getResourceType() const {
    return this->resourceType;
}
