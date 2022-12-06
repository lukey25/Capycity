#include "Solarpower.h"
#include "Material.cpp"
#include "Metal.cpp"

float Solarpower::basic_price = 3.3f;

Solarpower::Solarpower(int _length, int _width) { 
    Building(_length, _width); //initialisieren von length, width und price im Superkonstruktor 
    label = 3;
    matList = createMatList();
}