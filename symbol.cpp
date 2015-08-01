#include "symbol.h"
#include "object.h"

Symbol::Symbol(string nameValue, Object * objectValue) {
    name = nameValue;
    object = objectValue;
    objectType = SYMBOL;
}

Symbol::~Symbol(){}

ObjectType Symbol::getObjectType() const {
    return objectType;
}
