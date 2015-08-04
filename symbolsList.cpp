#include "symbolsList.h"

SymbolsList::SymbolsList() {}

SymbolsList::~SymbolsList() {
    for(unsigned int i(0); i < symbols.size(); ++i) {
        delete symbols[i];
        symbols[i] = 0;
    }
}

void SymbolsList::push(Symbol * symbol) {
    symbols.push_back(symbol);
}

Symbol * SymbolsList::findSymbol(std::string symbolName) {
    for(std::vector<int>::size_type i = 0; i != symbols.size(); i++) {
        if (symbolName.compare(symbols[i]->name))
            return symbols[i] ;
    }
    return NULL;
}
