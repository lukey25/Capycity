#include "Plastic.h"

float Plastic::price = 2.5f;

Plastic::Plastic() : Material() {
    //Material();
}

float Plastic::getPrice() { //Methode müsste eigentlich auch static sein, aber dann macht das Vererben über Material auch wieder keinen Sinn
    return price;
}
