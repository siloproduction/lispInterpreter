#include "object.h"
#include "doublet.h"
#include "string.h"
#include "number.h"
#include "symbolsList.h"
#include "nil.h"
#include "main.cpp"

#include <iostream>
#include <vector>

using namespace std;


Object * quote(Object * object) {
    if (object->getObjectType() == DOUBLET) {
        Doublet * doublet = dynamic_cast<Doublet *>(object);
        return doublet->getCar();
    }
    return &nil;
}

Object * cons(Object * object) {
    if (object->getObjectType() == NIL) {
        Doublet doublet(&nil, &nil);
        Object * res = &doublet;
        return res;
    }
    if (object->getObjectType() != DOUBLET) {
        return &nil;
    }

    Doublet * doubletInput = dynamic_cast<Doublet *>(object);
    if (doubletInput->getCdr()->getObjectType() == NIL) {
        Doublet doubletOutput(doubletInput->getCar(), &nil);
        Object * res = &doubletOutput;
        return res;
    }

    Doublet doubletOutput(doubletInput->getCar(), doubletInput->getCdr());
    Object * res = &doubletOutput;
    return res;
}


Object * set(Object * object) {
    if (object->getObjectType() != DOUBLET) {
        return &nil;
    }

    Doublet * doubletInput = dynamic_cast<Doublet *>(object);
    if (doubletInput->getCar()->getObjectType() != DOUBLET) {
        return &nil;
    }

    Object * value = &nil;
    if (doubletInput->getCdr()->getObjectType() != NIL) {
        Doublet * doubletCdr = dynamic_cast<Doublet *>(doubletInput->getCdr());
        value = doubletCdr->getCar();
    }

    Object * car = doubletInput->getCar();
    return &(*car = *value);
}

Object * car(Object * object) {
    if (object->getObjectType() != DOUBLET) {
        return &nil;
    }

    Doublet * doubletInput = dynamic_cast<Doublet *>(object);
    if (doubletInput->getCar()->getObjectType() != DOUBLET) {
        return &nil;
    }

    Doublet doubletCar = Doublet(((*doubletInput).getCar()), &nil);
    return doubletCar.getCar();
}

Object * cdr(Object * object) {
    if (object->getObjectType() != DOUBLET) {
        return &nil;
    }

    Doublet * doubletInput = dynamic_cast<Doublet *>(object);
    if (doubletInput->getCar()->getObjectType() != DOUBLET) {
        return &nil;
    }

    return doubletInput->getCdr();
}

int length(Doublet doublet) {
    if (doublet.getCar()->getObjectType() == NIL) {
        return 0;
    }

    Object * cdr = doublet.getCdr();

    if (cdr->getObjectType() != DOUBLET) {
        return 1;
    }

    Doublet * doubletCdr = dynamic_cast<Doublet *>(cdr);

    return 1 + length(*doubletCdr);
}
