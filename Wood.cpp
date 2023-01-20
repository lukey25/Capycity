#include "Wood.h"

float Wood::price = 5.5f;

Wood::Wood() : Material() {
    name = "Wood";
}

float Wood::getPrice() { 
    return price;
}