#ifndef STRING_H
#define STRING_H

#include "object.h"

#include <iostream>

class String: public Object {
    public:
        String(std::string stringValue);
        virtual ~String();

        virtual void print() const;

    private:
        std::string value;
        ObjectType objectType;
};

#endif // STRING_H
