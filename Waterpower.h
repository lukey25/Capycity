#ifndef WATERPOWER
#define WATERPOWER
#include "Building.h"
#include "Material.h"

class Waterpower : public Building {

    public:
        Waterpower(int _length, int _width, int _posX, int _posY);
        //map<Material*, int> createMatList();
        //float calcPrice();
        //toString Methode
};
#endif