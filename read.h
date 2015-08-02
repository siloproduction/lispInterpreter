#ifndef READ_H
#define READ_H

#include "object.h"

#include <iostream>

class Read {
    public:
        Read(std::string input);
        ~Read();

        Object * readListOrAtom(std::istream& input);

    private:
        std::string input;
};

#endif // READ_H
