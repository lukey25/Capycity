#include "Solarpower.h"
#include "Metal.h"
#include "Wood.h"
#include "Plastic.h"

float Solarpower::basic_price = 3.3f; //Jedes Gebäude desselben Typs hat denselben Grundpreis

Solarpower::Solarpower(int _length, int _width, int _posX, int _posY) { 
    //Building(_length, _width, _posX, _posY); //initialisieren von length, width und price im Superkonstruktor 
    length = _length;                           //coord lässt sich komischerweise nicht im Superkonstruktor initialisieren bzw. gibt
    width = _width;                             //es Probleme bei späteren Zugriffen über das Memberobjekt
    coord = new int[2];
    coord[0] = _posX;
    coord[1] = _posY;
    label = 3;
    price = calcPrice();
    matList = createMatList();
}

Material* Solarpower::createMatList() { //warum die Funktioni über Building aufgerufen werden muss ist mir schleierhaft. Und ob es überhaupt Sinn macht, die zu vererben...
    Material* matList = new Material[5];
    matList[0] = Wood();
    matList[1] = Metal();
    matList[2] = Metal();
    matList[3] = Metal();
    matList[4] = Plastic();
    return matList;
}

float Solarpower::calcPrice() { //muss ich hier jetzt Building oder Solarpower mit Bereichsoperator verwenden? Wenn ich die Funktion von Building überschreiben will
    float result = 0.0f;
    int matListLength = sizeof(matList)/sizeof(matList[0]);
    for(int i = 0; i < matListLength; i++) {
        result += matList[i].getPrice();
    }
    result += length * width * Solarpower:basic_price; //wieso kann ich auf basic_price nicht zugreifen?
}