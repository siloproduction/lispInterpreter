#ifndef NIL_H
#define NIL_H

#include "object.h"

class Nil: public Object {
    public:
        Nil() {
            this->value = 0;
            this->objectType = NIL;
        }
        virtual ~Nil() {}

        virtual ObjectType getObjectType() const {
            return objectType;
        }
        int getValue() {
            return value;
        }

    private:
        int value;
        ObjectType objectType;
};

#endif // NIL_H
