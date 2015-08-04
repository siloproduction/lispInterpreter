#include "read.h"
#include "object.h"
#include "exceptions.h"
#include "nil.h"
#include "doublet.h"
#include "symbolsList.h"
#include "number.h"
#include "lispString.h"

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>

SymbolsList symbolsList;

Read::Read(std::istream& input): stream(input) { }

Read::~Read() {}

Object * Read::read() {
    int rawChar = this->stream.peek();
    char peekChar = static_cast<char>(rawChar);
    if (peekChar == ')') {
        throw TooManyParents();
    }
    if (peekChar == '(') {
        this->stream.get();
        return readList(this->stream) ;
    }
    return readAtom(this->stream);
}

Object * Read::readList(std::istream& stream, bool firstTime) {
     Object * first;

    int rawChar = stream.peek();
    char peekChar = static_cast<char>(rawChar);

    cout << peekChar;

    if (peekChar == EOF) throw UnterminatedList();

    if (peekChar == ')') {
        stream.get(peekChar);
        return new Nil();
    }

    if ((not firstTime) and (peekChar == '.')) {
        stream.get(peekChar);

        peekChar = stream.peek();

        if (peekChar == EOF)
            throw LackingCdr();

        Read * toRead = new Read(stream);
        first =  toRead->read();

        peekChar = stream.peek();

        if (peekChar == EOF)
            throw UnterminatedCons();
        if (not (peekChar == ')'))
            throw TooMuchInCdr() ;

        stream.get(peekChar);
        return first;
    }
    Read * toRead = new Read(stream);
    first =  toRead->read();
    Doublet * doublet = new Doublet(first, readList(stream, false));
    return doublet;
}

Object * Read::readAtom(std::istream& stream) {
    std::string stringFromStream(std::istreambuf_iterator<char>(stream), {});;
    std::string read = getWord(stringFromStream);
    if (isNumber(read)) {
        Number * number = new Number(std::stoi(read));
        return number;
    }
    if (isString(read)) {
        String * string = new String(read.substr(1, read.size() - 2));
        return string;
    }

    Symbol * symbol = symbolsList.findSymbol(read);

    if (symbol)
        return symbol;

    Symbol * newSymbol = new Symbol(read, NULL);

    return newSymbol;
}

std::string Read::getWord(std::string string) {
    int i = 0;
    char character;
    std::string word;

    while((character = string[i++])) {
        if ((isspace(character) || character == '(' || character == ')')  && not word.empty())
            return word;
        else
          word += character;
    }
    if (not word.empty())
        return word;
    else
        return "";
}

bool Read::isNumber(const std::string& string) {
    return(strspn(string.c_str(), "0123456789") == string.size());
}

bool Read::isString(const std::string& string) {
    if (string.c_str()[0] != '"' or string[strlen(string.c_str()) - 1] != '"')
        return false;
    return true;
}
