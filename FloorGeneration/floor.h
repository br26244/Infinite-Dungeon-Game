#ifndef FLOOR
#define FLOOR
#include <iostream>
#include <vector>
#include "../Entities/PlayerChar.h"
#include "../Enemy/Enemy.h"
#include "../Entities/Entity.h"

using namespace std;

class Floor{
    public:
        Floor();

        void loadFloor(string file);
        void clearFloor();
        void printFloor();

        void moveCharacter(char input, PlayerChar& player);
        bool boundaryCheck(int xCoord, int yCoord);
        int getPlayerX();
        int getPlayerY();
        char getSym(int x, int y);
        void setSym(int x, int y, char tile);
        // void processEnemyMove(Entity &player, int enemyIndex, int targetX, int targetY);
        // void updateEnemies(Entity &player);
        

    private:
        vector <string> floorData;
        vector <Enemy> enemies;

};

#endif