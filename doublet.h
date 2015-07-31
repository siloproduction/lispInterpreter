#ifndef DOUBLET_H
#define DOUBLET_H

#include "object.h"

class Doublet: public Object {
    public:
        Doublet(Object car, Doublet * cdr);
        ~Doublet();

    private:
        Object car;
        Doublet * cdr;
        ObjectType objectType;
};

#endif // DOUBLET_H
