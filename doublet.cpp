#include "doublet.h"

Doublet::Doublet(Object carValue, Doublet * cdrValue) {
    car = carValue;
    cdr = cdrValue;
    objectType = DOUBLET;
}

Doublet::~Doublet() {}
