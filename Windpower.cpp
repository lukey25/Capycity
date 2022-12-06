#include "Windpower.h"
#include "Material.cpp"
#include "Metal.cpp"

float Windpower::basic_price = 3.3f;

Windpower::Windpower(int _length, int _width) { 
    Building(_length, _width); //initialisieren von length, width und price im Superkonstruktor 
    label = 2;
    matList = createMatList();
}