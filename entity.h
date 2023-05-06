#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "floor.h"
#include "floor.cpp"

class Entity{
    private:

        //Character Stats
        int health;
        int str;
        int def;

        //X,Y coords(?)
        int xCoord
        int yCoord

    public:
        //Entity default/initial constructor and 
        Entity()
        Entity(int health, int str, int def, int xCoord, int yCoord)

        //Necessary Deconstructor
        ~Entity()

        //Entity movement checks 
        void moveChar(Floor &floorData)
        bool boundaryCheck(Floor &floorData, int xCoord, int yCoord)

        //entity stat modification/use/setters/getters
        int hpAccess()
        int strAccess()
        int defAccess()

        void modifyHealth(int hpMod)
        void modifyStrength(int strMod)
        void modifyDefense(int defMod)

        //interactions with other objects/items
        void attack(Entity oppTarget, int damage)

    private:
        

        
};

#endif