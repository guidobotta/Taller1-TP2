#include "hierro.h"

Hierro::Hierro() : Resource(HIERRO) {}

ResIndex Hierro::getResourceType() const {
    return this->resourceType;
}
