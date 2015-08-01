#ifndef NIL_H
#define NIL_H

#include "object.h"

class Nil: public Object {
    public:
        Nil();
        virtual ~Nil();

        virtual ObjectType getObjectType() const;
        int getValue();

    private:
        int value;
        ObjectType objectType;
};

Nil::Nil() {
    value = 0;
    objectType = NIL;
}

Nil::~Nil() {}

ObjectType Nil::getObjectType() const {
    return objectType;
}

int Nil::getValue() {
    return value;
}

extern Nil nil;

#endif // NIL_H
