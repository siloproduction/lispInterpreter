#include "object.h"
#include "lispString.h"

#include <iostream>

String::String(std::string value) {
    this->value = value;
    this->objectType = STRING;
}

String::~String() {}

ObjectType String::getObjectType() const {
    return objectType;
}

const string String::getValue() {
    return value;
}
