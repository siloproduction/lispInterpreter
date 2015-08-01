#include "doublet.h"

Doublet::Doublet(Object * carValue, Object * cdrValue) {
    car = carValue;
    cdr = cdrValue;
    objectType = DOUBLET;
}

Doublet::~Doublet() {}

Object * Doublet::getCar() {
    return car;
}

Object * Doublet::getCdr() {
    return cdr;
}

ObjectType Doublet::getObjectType() const {
    return objectType;
}
