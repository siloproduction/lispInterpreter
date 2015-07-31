#include "symbolsList.h"

SymbolsList::SymbolsList() {}

SymbolsList::~SymbolsList() {
    for(unsigned int i(0); i < symbols.size(); ++i) {
        delete symbols[i];
        symbols[i] = 0;
    }
}

void SymbolsList::push(Object * object) {
    symbols.push_back(object);
}
