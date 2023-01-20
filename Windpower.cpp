#include "Windpower.h"
#include "Metal.h"
#include "Wood.h"
#include "Plastic.h"


Windpower::Windpower(int _length, int _width, int _posX, int _posY) : Building(_length, _width, _posX, _posY) { 
    basicPrice = 2.6f;
    woodPerUnit = 8;
    metalPerUnit = 3;
    plasticPerUnit = 1;
    label = 1;
    type = "Windpower";
    matList = createMatList();
    totalPrice = calcPrice(); 
}
