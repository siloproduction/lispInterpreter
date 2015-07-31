#ifndef SYMBOLSLIST_H
#define SYMBOLSLIST_H

#include "object.h"

#include <vector>

using namespace std;

class SymbolsList {
    public:
        vector<Object*> symbols;

        SymbolsList();
        ~SymbolsList();

        void push(Object * object);
};

extern SymbolsList symbolsList;

#endif // SYMBOLSLIST_H
