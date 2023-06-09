#ifndef __ENTITY_H__
#define __ENTITY_H__
//#include "floor.h"
//#include "floor.cpp"
//#include "levelUp.h"

class Entity{
    private:

        //Character Stats
        int health;
        int str;
        int def;
        int level;
        int exp;

        bool isDead;

        //X,Y coords(?)
        

    public:
        //Entity default/initial constructor and 
        int x;
        int y;

        Entity();
        Entity(int health, int str, int def, int level, int xCoord, int yCoord);

        //Necessary Deconstructor
        ~Entity();

        //Entity movement checks 
        /*void moveChar(Floor &floorData)
        bool boundaryCheck(Floor &floorData, int xCoord, int yCoord)
        */

        //entity stat modification/use/setters/getters
        int hpAccess();
        int strAccess();
        int defAccess();
        int expAccess();
        int levelAccess();
        int xAccess();
        int yAccess();
        bool isEntityDead();
        

        void modifyHealth(int hpMod);
        void modifyStrength(int strMod);
        void modifyDefense(int defMod);
        void modifyDeathState(bool deathState);
        void modifyExp(int expMod);
        void modifyLevel();

        //interactions with other objects/items
        //void attack(Entity &oppTarget);

    private:
        

        
};

#endif