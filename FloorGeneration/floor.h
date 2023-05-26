#ifndef FLOOR
#define FLOOR
#include <iostream>
#include <vector>
#include "../Entities/entity.h"

using namespace std;

class Floor{
    public:
        Floor();

        void loadFloor(string file);
        void clearFloor();
        void printFloor();

        void moveCharacter(char input, Entity& player);
        bool boundaryCheck(int xCoord, int yCoord);
        int getPlayerX();
        int getPlayerY();
        

    private:
        vector <string> floorData;

};

#endif