#include "Building.h"
#include "Building.cpp"

class Empty : public Building {
    private:
        static float basic_price;
    public:
        Empty(int _posX, int _posY); 
};