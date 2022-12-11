#include "Waterpower.h"
#include "Metal.h"
#include "Wood.h"
#include "Plastic.h"

float Waterpower::basic_price = 3.3f;

Waterpower::Waterpower(int _length, int _width, int _posX, int _posY) { 
    Building(_length, _width, _posX, _posY); //initialisieren von length, width und price im Superkonstruktor 
    label = 1;
    matList = createMatList(); //benötigte Materialien pro Feld
}

Material* Building::createMatList() { //warum die Funktioni über Building aufgerufen werden muss ist mir schleierhaft. Und ob es überhaupt Sinn macht, die zu vererben...
    Material* matList = new Material[5];
    matList[0] = Wood();
    matList[1] = Wood();
    matList[2] = Metal();
    matList[3] = Metal();
    matList[4] = Plastic();
    return matList;
}

Material* Building::createMatList(int wood, int metal, int plastic) {

}
