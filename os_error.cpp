#include "os_error.h"
#include <errno.h>
#include <string.h>

OSError::OSError(const char *msg) noexcept {
    char* _errno = strerror(errno);
    
    int i = 0;

    for (; (i < 255) && (msg[i] != '\0'); i++) {
        this->msg_error[i] = msg[i];
    }

    if (i < 254) {
        this->msg_error[i] = '\n';
        i++;
    }

    for (int j = 0; (i < 255) && (_errno[j] != '\0'); i++, j++) {
        this->msg_error[i] = _errno[j];
    }

    this->msg_error[i] = '\0';
}

OSError::~OSError() noexcept {}

const char* OSError::what() const noexcept {
    return msg_error;
}
