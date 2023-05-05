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
        void moveChar(Floor *floorData)
        bool boundaryCheck(Floor *floorData, int xCoord, int yCoord)

    private:
        

        
};

#endif