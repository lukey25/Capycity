#include "Building.h"

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
