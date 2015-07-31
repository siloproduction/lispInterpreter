#include "object.h"
#include "string.h"
#include "number.h"

#include <iostream>
#include <vector>

using namespace std;

void printObject(Object const& object) {
    object.print();
}

int main()
{
    cout << "Hello World!" << endl;

    vector<Object*> symbolList;

    symbolList.push_back(new Number(5));
    symbolList.push_back(new String("five"));

    symbolList[0]->print();

//    for(int i(0); i<listeVehicules.size(); ++i) {
//        delete listeVehicules[i]; //On libère la i-ème case mémoire allouée
//        listeVehicules[i] = 0; //On met le pointeur à 0 pour éviter les soucis
//    }

    return 0;
}

