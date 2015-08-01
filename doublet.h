#ifndef DOUBLET_H
#define DOUBLET_H

#include "object.h"

class Doublet: public Object {
    public:
        Doublet(Object * car, Object * cdr);
        ~Doublet();

        Object * getCar();
        Object * getCdr();
        virtual ObjectType getObjectType() const;

    private:
        Object * car;
        Object * cdr;
        ObjectType objectType;
};

#endif // DOUBLET_H
