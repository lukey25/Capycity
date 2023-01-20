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
        ~Building(); //musste ich virtual machen, damit Zeiger vom Typ Building, die auf Objekte von Memberklassen zeigen, trotzdem den Memberdestruktor aufrufen
        int getLabel();
        string getType();
        int getLength();
        int getWidth();
        int getPosX();
        int getPosY();
        float getTotalPrice();
        virtual map<Material*, int> createMatList();
        void updateMatList();
        map<Material*, int>& getMatList();
        void setLength(int _length);
        void setWidth(int _width);
        void setPos(int x, int y);
        void setBasicPrice(float _price);
        void setTotalPrice(float _price);
        float calcPrice(); 
        friend ostream& operator<<(ostream& os, const Building& b);
        string printMatList(Building &b, string s);
};

#endif