#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>

class TooManyParents: public std::exception {
  public:
    TooManyParents() {}
    ~TooManyParents() throw() {}
    const char *what() const throw() {
        return "Trop de parenthèses fermantes";
    }
};

class UnterminatedList: public std::exception {
public:
    UnterminatedList() {}
    ~UnterminatedList() throw() {}
    const char *what() const throw() {
        return "Liste inachevée";
    }
};

class LackingCdr: public std::exception {
public:
    LackingCdr() {}
    ~LackingCdr() throw() {}
    const char *what() const throw() {
        return "Cdr manquant (après un point)";
    }
};

class TooMuchInCdr: public std::exception {
public:
    TooMuchInCdr() {}
    ~TooMuchInCdr() throw() {}
    const char *what() const throw() {
        return "Trop d'éléments dans le cdr (après un point)";
    }
};

class UnterminatedCons: public std::exception {
public:
    UnterminatedCons() {}
    ~UnterminatedCons() throw() {}
    const char *what() const throw() {
        return "Cons inachevé (après un point)";
    }
};

#endif // EXCEPTIONS_H
