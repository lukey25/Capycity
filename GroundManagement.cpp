#include <iostream>
#include <sstream>
#include <cmath>
#include "GroundManagement.h"
#include "Empty.h"
#include "Solarpower.h"
#include "Windpower.h"
#include "Waterpower.h"



using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;


int length = 0;
int width = 0;
Building* buildingsList = nullptr; //Liste der bestehenden Gebäude
int** map; //2-dimensionales Array für den blueprint zur Ausgabe

int main(int argc, char** argv) {
    string len = string(argv[1]);
    string wid = string(argv[2]);
    stringstream ss;
    ss << len;
    ss >> length;
    ss.clear();
    ss << wid;
    ss >> width;
    cout << length << " " << width << endl;
    map = createMap(length, width); //e
    mainMenu();
    return 0;
};


void createBuildingsList(Building* arr, Building &building) { //für die gegebene Anwendung wären die Funktionsparameter nicht notwendig
    Building* newArr = new Building[sizeof(arr) + 1];
    for(int i = 0; i < sizeof(arr) - 1; i++) {
        newArr[i] = arr[i];
    }
    newArr[sizeof(arr) + 1] = building;
    delete [] buildingsList;
    buildingsList = newArr;
}

void createBuildingsList(Building &building) {
    buildingsList = new Building[1];
    buildingsList[0] = building;
}

int** createMap(int length, int width) { //für die gegebene Anwendung wären die Funktionsparameter nicht notwendig
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

void mainMenu() {
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
            cout << endl << "Bitte ueberpruefen sie, ob ihre Eingabe mit einer der Eingabemoeglichkeiten (build, delete, blueprint, quit) uebereinstimmt" << endl;
        }
        cout << endl << endl;
    }
}

void buildMenu() {
    string input;
    int positionX;
    int positionY;
    int buildingLength;
    int buildingWidth;
    Building type;
    cout << "Bitte geben sie folgende Informationen in die Konsole ein:" << endl;
    cout << "1. Welche Art von Gebaeude soll gebaut werden (waterpower, windpower, solarpower):" << endl;
    cin >> input;
    if(input.compare("waterpower") == 0 || input.compare("Waterpower") == 0) {
        type = Waterpower;
    }
    else if(input.compare("windpower") == 0) {
        type = Windpower;
    }
    else if(input.compare("solarpower") == 0) {
        type = Solarpower;
    }
    else {
        cout << "Bitte ueberpruefen sie, ob ihre Eingabe mit einer der Eingabemoeglichkeiten (waterpower, windpower, solarpower) uebereinstimmt" << endl;
        return;
    }
    cout << "2. Laenge des Gebaeudes" << endl;
    cin >> buildingLength;
    //vielleicht hier irgendwo auch den aktuellen Bauplan mal anzeigen, ganz am Anfang des buildMenu Aufrufs
    cout << "3. Breite des Gebaeudes" << endl;
    cin >> buildingWidth;
    cout << "4. x-Position, an dem das Gebaeude gebaut werden soll. Genau gesagt die x-Postition der linkeren oberen Ecke" << endl;
    cin >> positionX;
    cout << "5. y-Position, an dem das Gebaeude gebaut werden soll. Genau gesagt die y-Postition der linkeren oberen Ecke" << endl;
    cin >> positionY;
    //cout << "z.B.: waterpower 20 25 3/3" << endl;
    //cout << "           1.     2. 3. 4." << endl;
    //cin >> input;
    if(checkGround(buildingLength, buildingWidth, positionX, positionY)) {
        build(type, buildingLength, buildingWidth, positionX, positionY);
    } else {
        cout << "Bitte pruefen Sie ihre Eingabe. Das Gebaeude muss innerhalb des Baugrunds liegen und darf sich mit keinem anderen Gebaeude ueberschneiden" << endl;
        return;
    }
    return;
}

void reduceMenu() {
    string input;
    int positionX;
    int positionY;
    int buildingLength;
    int buildingWidth;
    Building type = Empty;
    cout << "Bitte geben sie folgende Informationen in die Konsole ein:" << endl;
    cout << "1. Welche Art von Gebaeude soll verkleinert werden (waterpower, windpower, solarpower):" << endl;
    cin >> input;
    if(input.compare("waterpower") == 0 || input.compare("Waterpower") == 0) {
        type = Waterpower;
    }
    else if(input.compare("windpower") == 0) {
        type = Windpower;
    }
    else if(input.compare("solarpower") == 0) {
        type = Solarpower;
    }
    else {
        cout << "Bitte ueberpruefen sie, ob ihre Eingabe mit einer der Eingabemoeglichkeiten (waterpower, windpower, solarpower) uebereinstimmt" << endl;
        return;
    }
    cout << "2. Laenge des Gebaeudes" << endl;
    cin >> buildingLength;
    //vielleicht hier irgendwo auch den aktuellen Bauplan mal anzeigen, ganz am Anfang des buildMenu Aufrufs
    cout << "3. Breite des Gebaeudes" << endl;
    cin >> buildingWidth;
    cout << "4. x-Position, des zu verkleinernden Gebaeudes. Genau gesagt die x-Postition der linkeren oberen Ecke" << endl;
    cin >> positionX;
    cout << "5. y-Position, des zu verkleinernden Gebaeudes. Genau gesagt die y-Postition der linkeren oberen Ecke" << endl;
    cin >> positionY;   
    reduce(buildingLength, buildingWidth, positionX, positionY, type);
    return;
}

void bluePrint() {
    cout << endl << endl;
    for(int i = 0; i < width; i++) { 
        for(int j = 0; j < length; j++) {
            cout << buildingArea[j][i] << " "; 
        }
        cout << endl;
    }
    return;
}

bool checkGround(int buildingLength, int buildingWidth, int positionX, int positionY) {
    checkIfOutOfBounds(buildingLength, buildingWidth, positionX, positionY);
    for(int i = positionX; i < positionX + buildingLength; i++) {
        for(int j = positionY; j < positionY + buildingWidth; j++) {
            if(buildingArea[i][j] != Empty) {
                return false;
            } 
        }
    }
    return true;
}

void build(Building type, int buildingLength, int buildingWidth, int positionX, int positionY) {
    for(int i = positionX; i < positionX + buildingLength; i++) {
        for(int j = positionY; j < positionY + buildingWidth; j++) {
            buildingArea[i][j] = type;
        }
    }
    cout << "Der Bau wurde erfolgreich abgeschlossen!" << endl;
}

void reduce(int buildingLength, int buildingWidth, int positionX, int positionY, Building type) { //nicht ganz Fehlerproof, für den Fall das Gebäude gleicher Art direkt aneinander stehen
    checkIfOutOfBounds(buildingLength, buildingWidth, positionX, positionY);
    //if(buildingArea[positionX + buildingLength][positionY] == type || buildingArea[positionX][positionY + buildingWidth] == type) {
        //cout << "Bitte pruefen Sie ihre Eingabe. Es muss die exakte Laenge sowie Breite des zu verkleinernden Gebaeudes angegeben werden" << endl;
        //return;
    //} //check if input area is smaller than the size of a given building
    for(int i = positionX; i < positionX + buildingLength; i++) {
        for(int j = positionY; j < positionY + buildingWidth; j++) {
            if(buildingArea[i][j] != type) {    //check if input area corresponds with a given building (same building type?, input area bigger than a given building size?)
                cout << "Bitte pruefen sie ihre Eingabe. Gebaeudetyp stimmt nicht mit den anderen Eingaben ueberein oder die Koordinaten sind keinem Gebaeude zuzuordnen" << endl;
                return;
            }
        }
    }
    for(int i = positionX; i < positionX + buildingLength; i++) {
        buildingArea[i][positionY] = Empty;
    }
    for(int i = positionX; i < positionX + buildingLength; i++) {
        buildingArea[i][positionY + buildingWidth - 1] = Empty;
    }
    for(int i = positionY; i < positionY + buildingWidth; i++) {
        buildingArea[positionX][i] = Empty;
    }
    for(int i = positionY; i < positionY + buildingWidth; i++) {
        buildingArea[positionX + buildingLength - 1][i] = Empty;
    }
    cout << "Das Verkleinern war erfolgreich!" << endl;
}

void checkIfOutOfBounds(int inputLength, int inputWidth, int posX, int posY) {
    if(inputLength + posX > length || inputWidth + posY > width) {
        cout << "Bitte ueberpruefen Sie ihre Eingabe. Die Eingaben duerfen nicht ueber die Baugrundgrenze hinaus gehen!" << endl;
        mainMenu();
    }
}