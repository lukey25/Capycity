#ifndef BUILDING
#define BUILDING
#include "Material.h"
#include <iostream>
#include <map>

using std::map;
using namespace std;

class Building {
    protected:
        int woodPerUnit;
        int plasticPerUnit;
        int metalPerUnit;
        float totalPrice;
        float basicPrice;
        int label;
        string type;
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
        string getType();
        int getLength();
        int getWidth();
        int getPosX();
        int getPosY();
        float getTotalPrice();
        virtual map<Material*, int> createMatList();
        map<Material*, int> getMatList();
        void setLength(int _length);
        void setWidth(int _width);
        void setPos(int x, int y);
        void setBasicPrice(float _price);
        void setTotalPrice(float _price);
        virtual float calcPrice(); //Aufruf der Funktion für Building Objekt, ich will aber den Memberaufruf
        friend ostream& operator<<(ostream& os, const Building& b);
        string printMap(Building &b, string s);
};

#endif