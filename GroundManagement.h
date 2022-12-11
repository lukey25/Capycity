#include "Building.h"
#include "Building.cpp"

class GroundManagement {
    public:
        int** createMap(int length, int width);
        void updateBuildingsList(Building &building);
        //void createBuildingsList(Building* arr, Building &building);
        void mainMenu();
        void buildMenu();
        void bluePrint();
        void reduceMenu();
        bool checkGround(int length, int width, int positionX, int positionY);
        void checkIfOutOfBounds(int inputLength, int inputWidth, int posX, int posY);
        void build(int label, int buildingLength, int buildingWidth, int positionX, int positionY);
        void reduce(Building &b);
        Building& findBuilding(int posX, int posY);
};