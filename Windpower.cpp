#include "Windpower.h"
#include "Metal.h"
#include "Wood.h"
#include "Plastic.h"

float Windpower::basic_price = 3.3f;

Windpower::Windpower(int _length, int _width, int _posX, int _posY) { 
    Building(_length, _width, _posX, _posY); //initialisieren von length, width und price im Superkonstruktor 
    label = 2;
    matList = createMatList();
}

Material* Building::createMatList() { //warum die Funktioni über Building aufgerufen werden muss ist mir schleierhaft. Und ob es überhaupt Sinn macht, die zu vererben...
    Material* matList = new Material[5];
    matList[0] = Metal();
    matList[1] = Metal();
    matList[2] = Metal();
    matList[3] = Plastic();
    matList[4] = Plastic();
    return matList;
}