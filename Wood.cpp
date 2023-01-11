#include "Wood.h"

float Wood::price = 5.5f;

Wood::Wood() : Material() {
    name = "Wood";
}

float Wood::getPrice() { //Methode müsste eigentlich auch static sein, aber dann macht das Vererben über Material auch wieder keinen Sinn
    return price;
}