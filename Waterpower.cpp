#include "Waterpower.h"
#include "Material.cpp"
#include "Metal.cpp"

float Waterpower::basic_price = 3.3f;

Waterpower::Waterpower(int _length, int _width) { 
    Building(_length, _width);
    label = 1;
    matList = createMatList();
}

Material** Building::createMatList() {
    Material** matList = new Material*[5];
    Material *mat = new Metal();
    *matList = new Metal();
}

Material** Building::createMatList(int wood, int metal, int plastic) {

}
