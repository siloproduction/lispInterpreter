#include "symbol.h"
#include "object.h"

Symbol::Symbol(string name, Object * object) {
    this->name = name;
    this->object = object;
    this->objectType = SYMBOL;
}

Symbol::~Symbol(){}

ObjectType Symbol::getObjectType() const {
    return objectType;
}
