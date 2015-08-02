#include "object.h"
#include "lispString.h"

#include <iostream>

using namespace std;

String::String(string value) {
    this->value = value;
    objectType = STRING;
}

String::~String() {}

ObjectType String::getObjectType() const {
    return objectType;
}

const string String::getValue() {
    return value;
}
