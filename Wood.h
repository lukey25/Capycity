#include "Material.cpp"
class Wood : public Material {
    private:
        enum Type {MAHAGHONI, OAK, PINE}; //spezielle Typen von Holz, die einen unterschiedlichen Preis haben
        static float price;
    public:
        Wood();
};