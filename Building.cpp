#include "Building.h"
#include "Wood.h"
#include "Metal.h"
#include "Plastic.h"
#include <sstream>

using std::stringstream;

Building::Building(int _length, int _width, int _posX, int _posY) : length(_length), width(_width) {
    coord = new int[2];
    coord[0] = _posX;
    coord[1] = _posY;
    price = 0.0f;
}

Building::Building(int _posX, int _posY) {
    coord = new int[2];
    coord[0] = _posX;
    coord[1] = _posY;
    price = 0.0f;
}

int Building::getLabel() {
    return label;
}

string Building::getType() {
    return type;
}

void Building::setLength(int _length) {
    length = _length;
}

void Building::setWidth(int _width) {
    width = _width;
}

void Building::setPos(int x, int y) {
    coord[0] = x;
    coord[1] = y;
}

int Building::getPosX() {
    return *coord; //bekomme hier Fehler, wenn ich das Array über den Superkonstruktor initialisiere und dann später über diese Funktion darauf zugreifen will
}

int Building::getPosY() {
    return *(coord+1);
}

int Building::getLength() {
    return length;
}

int Building::getWidth() {
    return width;
}

Building::~Building() { //Destruktor wird ja scheinbar nicht vererbt?

}

//calcPrice //muss jede Subklasse selbst implementieren, da statische basic-price-variable.


float Building::getPrice() {
    return price;
}

void Building::setPrice(float _price) {
    price = _price;
}

map<Material*, int> Building::getMatList() {
    return matList; //wenn ich sie nicht im Header initialisiere, existiert sie in Building nicht
    //mal schauen, ob initialisieren in MemberKonstruktor sinnvoll ist oder ob man das auch außerhalb machen kann und dann nur zuweisen im Konstrukor bzw. füllen
}

string printMap(Building& b, string str) { //Stringbuffer benötigt
    stringstream ss;
    int counter = 0;
    string temp;
    for (int i = 1; i < str.length(); i++) {temp += " ";};
    for (auto &pair: b.getMatList()) {
        string s = counter > 0 ? temp : "";
        ss << s <<"{" << (pair.first)->getName() << ": " << pair.second << "}\n";
        counter++;
    }
    return ss.str();
}

ostream& operator<<(ostream& os, Building& b)
{
    stringstream ss;
    ss << "Position: " << b.getPosX() << "," << b.getPosY() << " Type: " << b.getLabel() << "(" << b.getType() << ")" << " Price: " << b.getPrice() << " Materials: " << endl;
    string s = ss.str();
    os << "Position: " << b.getPosX() << "," << b.getPosY() << " Type: " << b.getLabel() << "(" << b.getType() << ")" << " Price: " << b.getPrice() << " Materials: " << printMap(b, s) << endl;
    return os;
}

map<Material*, int> Building::createMatList() { //warum die Funktioni über Building aufgerufen werden muss ist mir schleierhaft. Und ob es überhaupt Sinn macht, die zu vererben...
    matList = map<Material*, int>(); //sicherstellen, dass die Matlist wieder zerstört wird, da dynamischer Speicher (Destructor von Material im Destructor von Building aufrufen)
    matList.insert({new Wood(), woodPerUnit * length * width});
    matList.insert(pair<Material*, int>(new Metal(), metalPerUnit * length * width));
    matList.insert(pair<Material*, int>(new Plastic(), plasticPerUnit * length * width));
    return matList;
}


