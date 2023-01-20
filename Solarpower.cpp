#include "Solarpower.h"
#include "Metal.h"
#include "Wood.h"
#include "Plastic.h"
#include <map>

using std::pair;
using std::map;




Solarpower::Solarpower(int _length, int _width, int _posX, int _posY) : Building(_length, _width, _posX, _posY) { 
    basicPrice = 3.3f;
    woodPerUnit = 3;
    metalPerUnit = 3;
    plasticPerUnit = 1;
    label = 3;
    type = "Solarpower";
    matList = createMatList(); 
    totalPrice = calcPrice();
}

