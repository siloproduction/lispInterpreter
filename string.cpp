#include "object.h"
#include "string.h"

#include <iostream>

using namespace std;

String::String(string stringValue) {
    value = stringValue;
    objectType = STRING;
}

String::~String() {}

ObjectType String::getObjectType() const {
    return objectType;
}

const string String::getValue() {
    return value;
}
