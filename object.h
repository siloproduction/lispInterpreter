#ifndef OBJECT_H
#define OBJECT_H

enum ObjectType {
    DOUBLET,
    NIL,
    NUMBER,
    STRING
};

class Object {
    public:
        Object();
        virtual ~Object();

        virtual void print() const;
};

#endif //OBJECT_H
