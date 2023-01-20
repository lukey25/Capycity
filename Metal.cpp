#include "Metal.h"

float Metal::price = 7.8f; //Bereichsoperator hier nicht zwingend notwendig

Metal::Metal() : Material() { 
    name = "Metal";
}

float Metal::getPrice() {  
    return price;
}