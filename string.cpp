#include "object.h"
#include "string.h"

#include <iostream>

using namespace std;

String::String(std::string stringValue) {
    value = stringValue;
    objectType = STRING;
}

String::~String() {}

void String::print() const {
    cout << "value = " << value << endl;
}

