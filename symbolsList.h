#ifndef SYMBOLSLIST_H
#define SYMBOLSLIST_H

#include "object.h"
#include "symbol.h"

#include <iostream>
#include <vector>

class SymbolsList {
    public:
        SymbolsList();
        ~SymbolsList();

        void push(Symbol * symbol);
        Symbol * findSymbol(std::string symbolName);

    private:
        std::vector<Symbol *> symbols;
};

extern SymbolsList symbolsList;

#endif // SYMBOLSLIST_H
