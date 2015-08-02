#include "object.h"
#include "doublet.h"
#include "symbolsList.h"
#include "nil.h"

#include <iostream>
#include <vector>


//Nil nil;

Object * quote(Object * object) {
    if (object->getObjectType() == DOUBLET) {
        Doublet * doublet = dynamic_cast<Doublet *>(object);
        return doublet->getCar();
    }
    return new Nil;
}

Object * cons(Object * object) {
    if (object->getObjectType() == NIL) {
        Doublet doublet(new Nil, new Nil);
        Object * res = &doublet;
        return res;
    }
    if (object->getObjectType() != DOUBLET) {
        return new Nil;
    }

    Doublet * doubletInput = dynamic_cast<Doublet *>(object);
    if (doubletInput->getCdr()->getObjectType() == NIL) {
        Doublet doubletOutput(doubletInput->getCar(), new Nil);
        Object * res = &doubletOutput;
        return res;
    }

    Doublet doubletOutput(doubletInput->getCar(), doubletInput->getCdr());
    Object * res = &doubletOutput;
    return res;
}


Object * set(Object * object) {
    if (object->getObjectType() != DOUBLET) {
        return new Nil;
    }

    Doublet * doubletInput = dynamic_cast<Doublet *>(object);
    if (doubletInput->getCar()->getObjectType() != DOUBLET) {
        return new Nil;
    }

    Object * value = new Nil;
    if (doubletInput->getCdr()->getObjectType() != NIL) {
        Doublet * doubletCdr = dynamic_cast<Doublet *>(doubletInput->getCdr());
        value = doubletCdr->getCar();
    }

    Object * car = doubletInput->getCar();
    return &(*car = *value);
}

Object * car(Object * object) {
    if (object->getObjectType() != DOUBLET) {
        return new Nil;
    }

    Doublet * doubletInput = dynamic_cast<Doublet *>(object);
    if (doubletInput->getCar()->getObjectType() != DOUBLET) {
        return new Nil;
    }

    Doublet doubletCar = Doublet(((*doubletInput).getCar()), new Nil);
    return doubletCar.getCar();
}

Object * cdr(Object * object) {
    if (object->getObjectType() != DOUBLET) {
        return new Nil;
    }

    Doublet * doubletInput = dynamic_cast<Doublet *>(object);
    if (doubletInput->getCar()->getObjectType() != DOUBLET) {
        return new Nil;
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
