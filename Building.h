#ifndef BUILDING
#define BUILDING
#include "Material.h"

class Building {
    protected:
        float price;
        int label;
        int width;
        int length;
        int* coord;
        Material* matList;
        //Material* createMatList(int wood, int metal, int plastic);

    public:
        Building(int _lenght, int _width, int _posX, int _posY);
        Building(int _posX, int _posY);
        Building() = default;
        ~Building();
        int getLabel();
        int getLength();
        int getWidth();
        int getPosX();
        int getPosY();
        float getPrice();
        Material* createMatList();
        Material* getMatList();
        void setLength(int _length);
        void setWidth(int _width);
        void setPos(int x, int y);
        void setPrice(float _price);
        virtual float calcPrice() {return 5.0f;}; 
};

#endif