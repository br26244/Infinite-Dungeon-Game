#ifndef FLOOR
#define FLOOR
#include <iostream>
#include <vector>
#include "../Entities/Entity.h"
#include "../Entities/PlayerChar.h"
#include "../Entities/DamageInteraction.cpp"
#include "../Enemy/Enemy.cpp"
#include "../Item/Items.cpp"


using namespace std;

class Floor{
    public:
        Floor();

        void loadFloor(string file);
        void clearFloor();
        void printFloor();

        void moveCharacter(char input, PlayerChar& player);
        bool boundaryCheck(int xCoord, int yCoord, PlayerChar& player);
        int getPlayerX();
        int getPlayerY();
        int getFloorNumber();
        char getSym(int x, int y);
        void setSym(int x, int y, char tile);
        void processEnemyMove(Entity &player, int enemyIndex, int targetX, int targetY);
        void updateEnemies(Entity &player);
        void spawnMonsters();
        void spawnItems();
        void identifyItem(Entity& player,int x,int y);
        void itemPickUp(Entity& player, int xPoint, int yPoint, char itemType);
        bool enemyAttacking(int enemyPosX, int enemyPosY, PlayerChar &targetChar);

    private:
        vector <string> floorData;
        vector <Enemy> enemies;
        vector <Item> items;
        int floor;

};

#endif