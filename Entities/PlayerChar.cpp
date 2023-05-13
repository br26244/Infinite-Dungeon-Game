#include "PlayerChar.h"
#include "Entity.h"
//#include "floor.h"
//#include "floor.cpp"
#include <iostream>
#include <string.h>


//player char constructors
PlayerChar::PlayerChar() : Entity()
{
    gold = 0;
    /*invSize = 10;
    inventory = new Item*[invSize];
    */
}
PlayerChar::PlayerChar(int health, int str, int def, int exp, int level, int xCoord, int yCoord, int gold) : Entity(health, str, def, level, xCoord, yCoord)
{
    this->exp = exp;
    this->gold = gold;
    //this->inventory = inventory;
    
}

PlayerChar::~PlayerChar()
{
    /*
    for(int i = 0; i < invSize; i++)
    {
        delete inventory[i];
    }
    delete inventory;
    */
}


int PlayerChar::accessGold()
{
    return gold;
}

void PlayerChar::modifyExp(int expMod)
{
    exp += expMod;
    while(exp >= levelExp)
    {
        exp -= levelExp;
        this->level++;
        modifyHealth(5);
        modifyStrength(1);
        modifyDefense(1);
        levelExp = level*10;
    }
        
}

void PlayerChar::modifyGold(int goldMod)
{
    gold += goldMod;
}