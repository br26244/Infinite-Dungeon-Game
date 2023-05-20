#ifndef __PLAYERCHAR_H__
#define __PLAYERCHAR_H__
#include "Entity.h"
//#include "floor.h"
//#include "floor.cpp"

class PlayerChar: public Entity
{
    private:

        //Array of items in inventory to use
        //Item **inventory;
        //const int invSize = 10;
        int health;
        int str;
        int def;
        int level;
        int exp;
        int xCoord;
        int yCoord;

        int levelExp = 10;
        int gold;

    public:
    
        //PlayerChar default/initial constructor and 
        PlayerChar();
        PlayerChar(int health, int str, int def, int exp, int level, int xCoord, int yCoord, int gold);

        //Necessary Deconstructor
        ~PlayerChar();

        //Character movement checks 
        //void moveChar(char moveInput)

        int accessGold();

        void modifyExp(int expMod);
        void modifyGold(int goldMod);

    private:
        //Using items from inventory
        //void getItem(Item newItem)
        //void useItem(Item newItem)
        
        

        
};

#endif
