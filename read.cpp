#include "read.h"

#include <iostream>

Read::Read(std::string input) {
    this->input = input;
}

Read::~Read() {}

Object * Read::readListOrAtom(std::istream& input) {
    int rawChar = input.peek();
    char peekChar = static_cast<char>(rawChar);
    if (peekChar == ')') {
        std::cout << ") found";
        throw "Parenthèse fermante inattendue";
    }
    if (peekChar == '(') {
        std::cout << "( found";
        input.get();
        return NULL;//read_list(input) ;
    }
    return NULL;//read_atom(input) ;
}
