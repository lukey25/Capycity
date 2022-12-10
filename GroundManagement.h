#include "Building.h"
#include "Building.cpp"

Building** createBuildingArea(int length, int width);
void mainMenu();
void buildMenu();
void bluePrint();
void reduceMenu();
bool checkGround(int length, int width, int positionX, int positionY);
void checkIfOutOfBounds(int inputLength, int inputWidth, int posX, int posY);
void build(Building type, int buildingLength, int buildingWidth, int positionX, int positionY);
void reduce(int buildingLenght, int buildingWidth, int positionX, int positionY, Building type);