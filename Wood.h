#ifndef WOOD
#define WOOD
#include "Material.h"
class Wood : public Material {
    private:
        enum Type {MAHAGHONI, OAK, PINE}; //spezielle Typen von Holz, die einen unterschiedlichen Preis haben (nur eine Idee, wurde dann verworfen)
        static float price;
    public:
        Wood();
        float getPrice();
};
#endif