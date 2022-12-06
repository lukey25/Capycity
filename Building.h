#include "Material.cpp"

class Building {
    protected:
        float price;
        int label;
        int width;
        int length;
        Material** matList;
        Material** createMatList();
        Material** createMatList(int wood, int metal, int plastic);
        int schießen();

    public:
        Building(int _lenght, int _width);
        Building();
};