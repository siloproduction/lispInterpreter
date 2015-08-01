#include "object.h"
#include "number.h"

#include <iostream>

using namespace std;

Number::Number(double numberValue) {
    value = numberValue;
    objectType = NUMBER;
}

Number::~Number() {}

ObjectType Number::getObjectType() const {
    return objectType;
}

double Number::getValue() {
    return value;
}
