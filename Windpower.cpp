#include "Windpower.h"
#include "Metal.h"
#include "Wood.h"
#include "Plastic.h"

float Windpower::basic_price = 3.3f;

Windpower::Windpower(int _length, int _width, int _posX, int _posY) { 
    length = _length;                           //coord lässt sich komischerweise nicht im Superkonstruktor initialisieren bzw. gibt
    width = _width;                             //es Probleme bei späteren Zugriffen über das Memberobjekt
    coord = new int[2];
    coord[0] = _posX;
    coord[1] = _posY;
    label = 2;
    matList = createMatList(); //weiß nicht, ob das so gut ist hier zwei Funktionen die voneinander abhängig sind nacheinander aufzurufen. Reihenfolge des Aufrufs entscheidend!
    price = calcPrice(); 
}

map<Material, int> Windpower::createMatList() { //warum die Funktioni über Building aufgerufen werden muss ist mir schleierhaft. Und ob es überhaupt Sinn macht, die zu vererben...
    matList = map<Material, int>(); //sicherstellen, dass die Matlist wieder zerstört wird, da dynamischer Speicher (Destructor von Material im Destructor von Building aufrufen)
    matList.insert(pair<Material, int>(Wood(), 8));
    matList.insert(pair<Material, int>(Metal(), 3));
    matList.insert(pair<Material, int>(Plastic(), 1));
    return matList;
}


float Windpower::calcPrice() { //muss ich hier jetzt Building oder Solarpower mit Bereichsoperator verwenden? Wenn ich die Funktion von Building überschreiben will
    float result = 0.0f; //Methode sollte bestenfalls vererbt werden um Redundanz zu vermeiden, jedoch schwierig wenn statische Variablen der Memberklasse verwendet werden
    float matPrice = 0.0f;
    int matListLength = matList.size(); // Zeile redundant
    map<Material, int>::iterator it;
    for(it = matList.begin(); it != matList.end(); it++) {
        Material temp = it->first; //Kopierkonstruktor Aufruf? -> implementieren?
        matPrice += temp.getPrice() * it->second;
    }
    result += length * width * (basic_price + matPrice); //wieso kann ich auf basic_price nicht zugreifen?
    return result;
}
//float Windpower::calcPrice() { //muss ich hier jetzt Building oder Solarpower mit Bereichsoperator verwenden? Wenn ich die Funktion von Building überschreiben will
  //  float result = 0.0f;    //Hier z.B. wöllte ich eigentlich die Methode in der Baseclass implementieren, ist aber schwer möglich, wenn ich dabei auf die static_variable 
  //  float matPrice = 0.0f;  //der Memberclasse zugreifen will
  //  int matListLength = sizeof(matList)/sizeof(matList[0]);
  //  for(int i = 0; i < matListLength; i++) {
  //      matPrice += matList[i].getPrice();
  //  }
  //  result += length * width * (basic_price + matPrice); //wieso kann ich auf basic_price nicht zugreifen?
  //  return result;
//}