#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include "GroundManagement.h"
#include "Solarpower.h"
#include "Building.cpp"
#include "Solarpower.cpp"
#include "Windpower.h"
#include "Windpower.cpp"
#include "Waterpower.h"
#include "Waterpower.cpp"
#include "Material.h"
#include "Material.cpp"
#include "Wood.h"
#include "Wood.cpp"
#include "Metal.h"
#include "Metal.cpp"
#include "Plastic.h"
#include "Plastic.cpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::vector; 




int main(int argc, char** argv) {
    GroundManagement gm = GroundManagement();
    string len = string(argv[1]);
    string wid = string(argv[2]);
    stringstream ss;
    ss << len;
    ss >> gm.length;
    ss.clear();
    ss << wid;
    ss >> gm.width;
    gm.map = gm.createMap(gm.length, gm.width); //e
    gm.mainMenu();
    return 0;
};

GroundManagement::GroundManagement() {
    length = 0;
    width = 0;
    buildingsList = vector<Building*>(); //Vector, um Gebäude zu speichern
}

void GroundManagement::updateBuildingsList(Building *building) { 
    buildingsList.push_back(building);
}


int** GroundManagement::createMap(int length, int width) { //für die gegebene Anwendung wären die Funktionsparameter nicht notwendig
    int **arr = new int*[length];
    for(int i = 0; i < length; i++) {
        arr[i] = new int[width];
    }
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < width; j++) {
            arr[i][j] = 0;
        }
    }
    return arr;
}

void GroundManagement::mainMenu() {
    while(true) {
        cout << "Hauptmenue:" << endl;
        cout << "Um Gebaeude zu setzen, tippe: build" << endl;
        cout << "Um Bereich zu loeschen, tippe: reduce" << endl;
        cout << "Um den aktuellen Bauplan anzuzeigen, tippe: blueprint" << endl;
        cout << "Um das Programm zu beenden, tippe: quit" << endl << endl;
        string input;
        cin >> input;
        if(input.compare("build") == 0) {
            buildMenu();
        }
        else if(input.compare("reduce") == 0) {
            reduceMenu();
        }
        else if(input.compare("blueprint") == 0) {
            bluePrint();
        }
        else if(input.compare("quit") == 0) {
            return;
        }
        else {
            cout << endl << "Bitte ueberpruefen sie, ob ihre Eingabe mit einer der Eingabemoeglichkeiten (build, reduce, blueprint, quit) uebereinstimmt" << endl;
        }
        cout << endl << endl;
    }
}

void GroundManagement::buildMenu() {
    string input;
    int positionX;
    int positionY;
    int buildingLength;
    int buildingWidth;
    int label;
    cout << "Bitte geben sie folgende Informationen in die Konsole ein:" << endl;
    cout << "1. Welche Art von Gebaeude soll gebaut werden (waterpower, windpower, solarpower):" << endl;
    cin >> input;
    if(input.compare("waterpower") == 0 || input.compare("Waterpower") == 0) {
        label = 2;
    }
    else if(input.compare("windpower") == 0) {
        label = 1;
    }
    else if(input.compare("solarpower") == 0) {
        label = 3;
    }
    else {
        cout << "Bitte ueberpruefen sie, ob ihre Eingabe mit einer der Eingabemoeglichkeiten (waterpower, windpower, solarpower) uebereinstimmt" << endl;
        return;
    }
    cout << "2. Laenge des Gebaeudes" << endl;
    cin >> buildingLength;
    cout << "3. Breite des Gebaeudes" << endl;
    cin >> buildingWidth;
    if(buildingLength < 1 || buildingWidth < 1) {
        cout << "Laenge bzw. Breite muss groesser als 0 sein!" << endl;
        return;
    }
    cout << "4. x-Position, an dem das Gebaeude gebaut werden soll. Genau gesagt die x-Postition der linkeren oberen Ecke" << endl;
    cin >> positionX;
    cout << "5. y-Position, an dem das Gebaeude gebaut werden soll. Genau gesagt die y-Postition der linkeren oberen Ecke" << endl;
    cin >> positionY;
    if(checkGround(buildingLength, buildingWidth, positionX, positionY)) {
        build(label, buildingLength, buildingWidth, positionX, positionY);
    } else {
        cout << "Bitte pruefen Sie ihre Eingabe. Das Gebaeude muss innerhalb des Baugrunds liegen und darf sich mit keinem anderen Gebaeude ueberschneiden" << endl;
        return;
    }
    return;
}

void GroundManagement::reduceMenu() {
    string input;
    int positionX;
    int positionY;
    cout << "Bitte geben sie die x-Position des zu verkleinernden Gebaeudes ein, genau gesagt die x-Postition der linkeren oberen Ecke:" << endl;
    cin >> positionX;
    cout << "Bitte geben sie die y-Position des zu verkleinernden Gebaeudes ein, genau gesagt die y-Postition der linkeren oberen Ecke:" << endl;
    cin >> positionY;  
    Building* b = findBuilding(positionX, positionY); 
    if(b == nullptr) {
        cout << "Bitte pruefen sie ihre Eingabe. Die eigegebenen Koordinaten muessen mit einem bestehenden Gebaeude uebereinstimmen." << endl;
        return;    
    }
    reduce(b);
    return;
}

void GroundManagement::bluePrint() { //seperate print out function for the blueprint
    float sum = 0;
    cout << endl << endl;
    for(int i = 0; i < width; i++) { 
        for(int j = 0; j < length; j++) {
            cout << map[j][i] << " "; 
        }
        cout << endl;
    }
    for(int i = 0; i < buildingsList.size(); i++) { //print out all Buildings with certain information.
        sum += buildingsList[i]->getTotalPrice();
        cout << *buildingsList[i]; //<< Operator overloading in class Building
    }
    cout << "Gesamtpreis aller Gebaeude: " << sum << endl;
    return;
}

bool GroundManagement::checkGround(int buildingLength, int buildingWidth, int positionX, int positionY) {
    //Prüfe, ob Gebäude innerhalb der Baugrenzen
    if(buildingLength + positionX > length || buildingWidth + positionY > width) {
        return false; 
    }
    ////Prüfe, ob Gebäude sich mit einem anderen überschneidet
    for(int i = positionX; i < positionX + buildingLength; i++) {
        for(int j = positionY; j < positionY + buildingWidth; j++) {
            if(map[i][j] != 0) {
                return false;
            } 
        }
    }
    return true;
}

void GroundManagement::build(int label, int buildingLength, int buildingWidth, int positionX, int positionY) {
    Building *b;
    switch(label) {
        case 2:
            b = new Waterpower(buildingLength, buildingWidth, positionX, positionY);
            break;
        case 1:
            b = new Windpower(buildingLength, buildingWidth, positionX, positionY);
            break;
        case 3:
            b = new Solarpower(buildingLength, buildingWidth, positionX, positionY);
        default:
            ;
    }
    updateBuildingsList(b);
    for(int i = positionX; i < positionX + buildingLength; i++) {   //update map
        for(int j = positionY; j < positionY + buildingWidth; j++) {
            map[i][j] = b->getLabel();
        }
    }
    cout << "Der Bau wurde erfolgreich abgeschlossen!" << endl;
}

void GroundManagement::reduce(Building *b) { 
    for(int i = b->getPosX(); i < b->getPosX() + b->getLength(); i++) { //update map
        map[i][b->getPosY()] = 0;
    }
    for(int i = b->getPosX(); i < b->getPosX() + b->getLength(); i++) {
        map[i][b->getPosY() + b->getWidth() - 1] = 0;
    }
    for(int i = b->getPosY(); i < b->getPosY() + b->getWidth(); i++) {
        map[b->getPosX()][i] = 0;
    }
    for(int i = b->getPosY(); i < b->getPosY() + b->getWidth(); i++) {
        map[b->getPosX() + b->getLength() - 1][i] = 0;
    }
    if(b->getLength() - 2 <=0 || b->getWidth() - 2 <= 0) {
        buildingsList.erase(buildingsList.begin() + findIdx(b)); //löscht das Objekt aus der BuildingsList
        delete b; //Destruktoraufruf des jeweiligen Gebäude Objekts
    } //(falls Länge und Breite = 0, wird es nicht mehr in der Liste gespeichert sondern gelöscht, wenn der Gültigkeitsbereich der Erstellung verlassen wird)
    else {
        b->setLength(b->getLength() - 2); //update Object-attributes
        b->setWidth(b->getWidth() - 2);
        b->setPos(b->getPosX() + 1, b->getPosY() + 1);
        b->updateMatList(); //Neukalkulierung der Materialliste, falls das Objekt nicht zerstört wurde
        b->setTotalPrice(b->calcPrice()); //Neukalkulierung des Preises nach dem reducen, falls das Objekt nicht schon zerstört wurde
    }
    cout << "Das Verkleinern war erfolgreich!" << endl;
}

Building* GroundManagement::findBuilding(int posX, int posY) {
    for(int i = 0; i < buildingsList.size(); i++) {
        if(buildingsList[i]->getPosX() == posX && buildingsList[i]->getPosY() == posY) {
            return buildingsList[i];
        }
    }
    return nullptr;
}

int GroundManagement::findIdx(Building *b) {
    for(int i = 0; i < buildingsList.size(); i++) {
        if(buildingsList[i]->getPosX() == b->getPosX() && buildingsList[i]->getPosY() == b->getPosY()) {
            return i;
        }
    }
    return 0;
}
