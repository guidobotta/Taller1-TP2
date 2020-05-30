#ifndef __OS_ERROR_H__
#define __OS_ERROR_H__

#include <exception>
#define BUFF_LEN 256

class OSError : public std::exception {
    private:
        char msg_error[BUFF_LEN];

    public:
        explicit OSError(const char *msg) noexcept;
        virtual const char* what() const noexcept;
        virtual ~OSError() noexcept;
};

#endif
