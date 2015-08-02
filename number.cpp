#include "object.h"
#include "number.h"

#include <iostream>

Number::Number(double number) {
    this->value = number;
    this->objectType = NUMBER;
}

Number::~Number() {}

ObjectType Number::getObjectType() const {
    return objectType;
}

double Number::getValue() {
    return value;
}
