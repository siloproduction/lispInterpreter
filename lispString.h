#ifndef STRING_H
#define STRING_H

#include "object.h"

#include <iostream>

using namespace std;


class String: public Object {
    public:
        String(string stringValue);
        virtual ~String();

        virtual ObjectType getObjectType() const;
        const string getValue();

    private:
        string value;
        ObjectType objectType;
};

#endif // STRING_H
