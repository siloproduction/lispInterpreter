#ifndef SYMBOL_H
#define SYMBOL_H

#include "object.h"

#include <iostream>
#include <vector>

using namespace std;

class Symbol: public Object {
    public:
        Symbol(string nameValue, Object objectValue);
        ~Symbol();

        string name;
        Object object;
};
#endif // SYMBOL_H
