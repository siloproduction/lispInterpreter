#ifndef STRING_H
#define STRING_H

#include "object.h"

#include <iostream>

class String: public Object {
    public:
        std::string value;

        String(std::string stringValue);
        virtual ~String();

        virtual void print() const;
};

#endif // STRING_H
