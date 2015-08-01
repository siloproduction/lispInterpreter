#include "symbol.h"
#include "object.h"

Symbol::Symbol(string nameValue, Object objectValue) {
    name = nameValue;
    object = objectValue;
}

Symbol::~Symbol(){}
