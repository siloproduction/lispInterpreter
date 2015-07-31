#ifndef NUMBER_H
#define NUMBER_H

#include "object.h"

class Number: public Object {
    public:
        double value;

        Number(double numberValue);
        virtual ~Number();

        virtual void print() const;
};

#endif // NUMBER_H
