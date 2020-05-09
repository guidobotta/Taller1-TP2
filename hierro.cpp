#include "hierro.h"

Hierro::Hierro() : Resource(HIERRO) {}

ResIndex Hierro::getResourceType() {
    return this->resourceType;
}
