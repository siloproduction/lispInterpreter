#include "main.h"
#include "object.h"
#include "lispString.h"
#include "number.h"
#include "symbolsList.h"
#include "nil.h"
#include "doublet.h"
#include "lispFunctions.h"
#include "read.h"

#include <iostream>
#include <vector>
#include <sstream>


int main(int argc, char * argv[]) {
    if (argc == 1)
        return readEvalPrintLoop();
    if (argc == 2)
        return execute(argv[1]);
     else {
        cout << "L'intepréteur doit être lancé soit sans argument pour démarrer l'interpréteur soit avec un seul argument qui sera le fichier à exécuter" << endl;
        return 0;
    }
}

int readEvalPrintLoop() {
    bool finished = false;

    while (not finished) {
        std::string input;

        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "exit")
            finished = true;
        else if (input != "") {
            try {
                std::stringstream stream(input);
                Read * toRead = new Read(stream);
                toRead->read();

                std::cout << input << endl;
            } catch (exception& e) {
              std::cout << e.what() << endl;
            }
        }
    }

    return 0;
}

int execute(string fileName) {

    return 0;
}



