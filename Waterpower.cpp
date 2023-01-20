#include "Waterpower.h"
#include "Metal.h"
#include "Wood.h"
#include "Plastic.h"


Waterpower::Waterpower(int _length, int _width, int _posX, int _posY) : Building(_length, _width, _posX, _posY) { 
    basicPrice = 3.7f;
    woodPerUnit = 3;
    metalPerUnit = 5;
    plasticPerUnit = 2;
    label = 2;
    type = "Waterpower";
    matList = createMatList(); 
    totalPrice = calcPrice(); //benötigte Materialien pro Feld
}



