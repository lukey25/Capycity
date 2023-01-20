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
    totalPrice = 0.0f;
}

Building::Building(int _posX, int _posY) { //Konstruktor eigentlich nicht in Verwendung
    coord = new int[2];
    coord[0] = _posX;
    coord[1] = _posY;
    totalPrice = 0.0f;
}

Building::~Building() {
    map<Material*, int>::iterator it;
    for(it = matList.begin(); it != matList.end(); it++) {
        delete it->first;
    }
}

int Building::getLabel() {
    return label;
}

string Building::getType() {
    return type;
}

int Building::getPosX() {
    return *coord; 
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

float Building::getTotalPrice() {
    return totalPrice;
}

map<Material*, int>& Building::getMatList() {
    return matList; 
}

void Building::setPos(int x, int y) {
    coord[0] = x;
    coord[1] = y;
}

void Building::setTotalPrice(float _price) {
    totalPrice = _price;
}

void Building::setLength(int _length) {
    length = _length;
}

void Building::setWidth(int _width) {
    width = _width;
}

void Building::setBasicPrice(float _price) {
    basicPrice = _price;
}

string printMatList(Building& b, string str) { //Da bin ich nicht stolz drauf, aber ne schöne Ausgabe hinzubekommen ist so ne Sache die man nicht so einfach nachschlagen kann
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

ostream& operator<<(ostream& os, Building& b) {
    stringstream ss;
    ss << "Position: " << b.getPosX() << "," << b.getPosY() << " Type: " << b.getLabel() << "(" << b.getType() << ")" << " totalPrice: " << b.getTotalPrice() << " Materials: " << endl;
    string s = ss.str();
    os << "Position: " << b.getPosX() << "," << b.getPosY() << " Type: " << b.getLabel() << "(" << b.getType() << ")" << " totalPrice: " << b.getTotalPrice() << " Materials: " << printMatList(b, s) << endl;
    return os;
}

map<Material*, int> Building::createMatList() { 
    matList = map<Material*, int>(); //sicherstellen, dass die Matlist wieder zerstört wird, da dynamischer Speicher (Destructor von Material im Destructor von Building aufrufen)
    matList.insert(pair<Material*, int>(new Wood(), woodPerUnit * length * width)); //Required wood for whole building
    matList.insert(pair<Material*, int>(new Metal(), metalPerUnit * length * width)); //Required metal for whole building
    matList.insert(pair<Material*, int>(new Plastic(), plasticPerUnit * length * width)); //Required plastic for whole building
    return matList;
}

void Building::updateMatList() { //wohl auch nicht die generischste Lösung
    map<Material*, int>::iterator it;
    it = matList.begin();
    it++->second = woodPerUnit * length * width; //aber doch zugegebenermaßen kreativ mit dem postinkrement^^
    it++->second = metalPerUnit * length * width;
    it->second = plasticPerUnit * length * width;
}

float Building::calcPrice() { 
    float result = 0.0f; 
    float matPrice = 0.0f;
    map<Material*, int>::iterator it; //nicht unbedingt notwendig, kann man auch mit auto direkt in der loop definieren + initialisieren
    for(it = matList.begin(); it != matList.end(); it++) { //calculate mat price for whole building
        Material* temp = it->first; 
        matPrice += temp->getPrice() * it->second; 
    }
    result += length * width * basicPrice + matPrice; 
    return result;
}


