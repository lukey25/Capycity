#include "Material.cpp"

class Building {
    protected:
        float price;
        int label;
        int width;
        int length;
        int* coord;
        Material* matList;
        Material* createMatList();
        Material* createMatList(int wood, int metal, int plastic);

    public:
        Building(int _lenght, int _width, int _posX, int _posY);
        Building(int _posX, int _posY);
        Building();
};