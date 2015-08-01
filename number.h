#ifndef NUMBER_H
#define NUMBER_H

#include "object.h"

class Number: public Object {
    public:
        Number(double numberValue);
        virtual ~Number();

        virtual ObjectType getObjectType() const;
        double getValue();

    private:
        double value;
        ObjectType objectType;
};

#endif // NUMBER_H
