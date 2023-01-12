#include "Solarpower.h"
#include "Metal.h"
#include "Wood.h"
#include "Plastic.h"
#include <map>

using std::pair;
using std::map;


float Solarpower::basic_price = 3.3f; //Jedes Gebäude desselben Typs hat denselben Grundpreis

Solarpower::Solarpower(int _length, int _width, int _posX, int _posY) : Building(_length, _width, _posX, _posY) { 
    woodPerUnit = 3;
    metalPerUnit = 3;
    plasticPerUnit = 1;
    label = 3;
    type = "Solarpower";
    matList = createMatList(); //weiß nicht, ob das so gut ist hier zwei Funktionen die voneinander abhängig sind nacheinander aufzurufen. Reihenfolge des Aufrufs entscheidend!
    price = calcPrice();
}

map<Material*, int> Solarpower::createMatList() { //warum die Funktioni über Building aufgerufen werden muss ist mir schleierhaft. Und ob es überhaupt Sinn macht, die zu vererben...
    matList = map<Material*, int>(); //sicherstellen, dass die Matlist wieder zerstört wird, da dynamischer Speicher (Destructor von Material im Destructor von Building aufrufen)
    matList.insert({new Wood(), woodPerUnit * length * width});
    matList.insert(pair<Material*, int>(new Metal(), metalPerUnit * length * width));
    matList.insert(pair<Material*, int>(new Plastic(), plasticPerUnit * length * width));
    return matList;
}

float Solarpower::calcPrice() { //muss ich hier jetzt Building oder Solarpower mit Bereichsoperator verwenden? Wenn ich die Funktion von Building überschreiben will
    float result = 0.0f; //Methode sollte bestenfalls vererbt werden um Redundanz zu vermeiden, jedoch schwierig wenn statische Variablen der Memberklasse verwendet werden
    float matPrice = 0.0f;
    map<Material*, int>::iterator it; //nicht unbedingt notwendig, kann man auch mit auto direkt in der loop definieren + initialisieren
    for(it = matList.begin(); it != matList.end(); it++) {
        Material* temp = it->first; //Kopierkonstruktor Aufruf? -> implementieren?
        matPrice += temp->getPrice() * it->second;
    }
    result += length * width * (basic_price + matPrice); //wieso kann ich auf basic_price nicht zugreifen?
    return result;
}