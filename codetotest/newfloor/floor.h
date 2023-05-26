#ifndef FLOOR
#define FLOOR
#include <iostream>
#include <vector>
#include "../Entities/Entity.h" //uses ahsu's entity class
#include "../Enemy/Enemy.h"

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
        char getSym(int x, int y);
        void setSym(int x, int y, char tile);
        void processEnemyMove(Entity &player, int enemyIndex, int targetX, int targetY);
        void updateEnemies(Entity &player);
        //void battleMonster(Entity &player, int targetX, int targetY);

    private:
        vector <string> floorData;
        vector <Enemy> enemies;
        

};

#endif