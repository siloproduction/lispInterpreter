#ifndef OBJECT_H
#define OBJECT_H

class Object {
    public:
        Object();
        virtual ~Object();

        virtual void print() const;
};

#endif //OBJECT_H
