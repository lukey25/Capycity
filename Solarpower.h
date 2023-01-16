#ifndef SOLARPOWER
#define SOLARPOWER
#include "Building.h"
#include "Material.h"

class Solarpower : public Building {
    private:
        static float basic_price;  
    public:
        Solarpower(int _length, int _width, int _posX, int _posY); 
        Solarpower() = default; 
        //map<Material*, int> createMatList();
        float calcPrice();
};
#endif