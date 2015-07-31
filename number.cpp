#include "object.h"
#include "number.h"

#include <iostream>

using namespace std;

Number::Number(double numberValue) {
    value = numberValue;
    objectType = NUMBER;
}

Number::~Number() {}

void Number::print() const {
    cout << "value = " << value << endl;
}

