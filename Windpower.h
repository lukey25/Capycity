#ifndef WINDPOWER
#define WINDPOWER
#include "Building.h"
#include "Material.h"

class Windpower : public Building {
    private:
        static float basic_price;
    public:
        Windpower(int _length, int _width, int _posX, int _posY);    
        //map<Material*, int> createMatList();
        //float calcPrice();
};
#endif