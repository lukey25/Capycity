#ifndef BUILDING
#define BUILDING
#include "Material.h"
#include <iostream>
#include <map>

using std::map;

class Building {
    protected:
        float price;
        int label;
        int width;
        int length;
        int* coord;
        map<Material*, int> matList;
        //Material* matList;
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
        virtual map<Material*, int> createMatList() = 0;
        map<Material*, int> getMatList();
        void setLength(int _length);
        void setWidth(int _width);
        void setPos(int x, int y);
        void setPrice(float _price);
        virtual float calcPrice() = 0; //Aufruf der Funktion für Building Objekt, ich will aber den Memberaufruf
};

#endif