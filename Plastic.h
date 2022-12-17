#ifndef PLASTIC
#define PLASTIC
#include "Material.h"

class Plastic : public Material {
    private:
        static float price;
    public:
        Plastic();
        static float getPrice();
};
#endif