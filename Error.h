#ifndef   ERROR_H
#define   ERROR_H

class Error {
     char *message;
public:
    Error(char * message);
    Error();
    inline char * getMessage() { return message;}
   ~Error();
};

#endif
