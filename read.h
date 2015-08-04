#ifndef READ_H
#define READ_H

#include "object.h"

#include <iostream>

class Read {
    public:
        Read(std::istream& input);
        ~Read();

        Object * read();
        Object * readList(std::istream& stream, bool firstTime = true);
        Object * readAtom(std::istream& stream);
        static bool isNumber(const std::string&);
        static bool isString(const std::string& string);
        static std::string getWord(std::string string);

    private:
        std::istream& stream;
};

#endif // READ_H
