#include "Metal.h"

float Metal::price = 7.8f; //Bereichsoperator hier nicht zwingend notwendig

Metal::Metal() {
    Material();
}
                            //geht auch nicht static Methode mit static Variablen?
float Metal::getPrice() { //Methode müsste eigentlich auch static sein, aber dann macht das Vererben über Material auch wieder keinen Sinn 
    return price;
}