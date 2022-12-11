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
