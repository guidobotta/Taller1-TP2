#include "empty_exception.h"

EmptyException::EmptyException() noexcept {}

EmptyException::~EmptyException() noexcept {}

const char* EmptyException::what() const noexcept {
    return "Container empty";
}
