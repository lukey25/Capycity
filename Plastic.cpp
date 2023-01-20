#include "Plastic.h"

float Plastic::price = 2.5f;

Plastic::Plastic() : Material() {
    name = "Plastic";
}

float Plastic::getPrice() { 
    return price;
}
