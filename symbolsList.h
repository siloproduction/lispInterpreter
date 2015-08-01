#ifndef SYMBOLSLIST_H
#define SYMBOLSLIST_H

#include "object.h"

#include <vector>

using namespace std;


class SymbolsList {
    public:
        SymbolsList();
        ~SymbolsList();

        void push(Object * object);

    private:
        vector<Object*> symbols;
};

extern SymbolsList symbolsList;

#endif // SYMBOLSLIST_H
