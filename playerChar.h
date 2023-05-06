#ifndef __PLAYERCHAR_H__
#define __PLAYERCHAR_H__
#include "entity.h"
#include "floor.h"
#include "floor.cpp"

class PlayerChar: public Entity
{
    private:

        //Array of items in inventory to use
        Item **inventory;
        const int invSize = 10;

    public:
    
        //PlayerChar default/initial constructor and 
        PlayerChar()
        PlayerChar(int health, int str, int def, Item **inventory, int xCoord, int yCoord)

        //Necessary Deconstructor
        ~PlayerChar()

        //Character movement checks 
        void moveChar(char moveInput)

    private:
        //Using items from inventory
        void getItem(Item newItem)
        void useItem(Item newItem)
        
        

        
};

#endif
