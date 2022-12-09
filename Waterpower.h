#include "Building.h"

class Waterpower : public Building {
    private:
        static float basic_price;
    public:
        Waterpower(int _length, int _width, int _posX, int _posY);
        //toString Methode
};