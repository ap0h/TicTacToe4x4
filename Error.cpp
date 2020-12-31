#include "Error.h"

Error::Error() {
this->message = nullptr;
}

Error::Error(char *message) {
    this->message = message;
}
Error::~Error() {
    if(this->message != nullptr)
        delete message;
}
