#ifndef SYMBOL_H
#define SYMBOL_H

#include "object.h"

#include <iostream>
#include <vector>

using namespace std;

class Symbol: public Object {
    public:
        Symbol(string nameValue, Object * objectValue);
        ~Symbol();

        virtual ObjectType getObjectType() const;
        string name;
        Object * object;
    private:
        ObjectType objectType;
};
#endif // SYMBOL_H
