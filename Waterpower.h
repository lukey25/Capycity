#ifndef WATERPOWER
#define WATERPOWER
#include "Building.h"
#include "Material.h"

class Waterpower : public Building {
    private:
        static float basic_price;
    public:
        Waterpower(int _length, int _width, int _posX, int _posY);
        Material* createMatList();
        //toString Methode
};
#endif