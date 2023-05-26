#include "PlayerChar.h"
#include "Entity.h"
//#include "levelUp.h"
#include <iostream>
#include <string.h>


//player char constructors
PlayerChar::PlayerChar() : Entity()
{
    gold = 0;
    level = 1;
    isDead = false;


}
PlayerChar::PlayerChar(int health, int str, int def, int exp, int level, int xCoord, int yCoord, int gold) : Entity(health, str, def, level, xCoord, yCoord)
{
    isDead = false;
    this->exp = exp;
    this->gold = gold;
    
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

void PlayerChar::modifyGold(int goldMod)
{
    gold += goldMod;
}


/*void PlayerChar::modifyExp(int expMod)
{
    this->exp += expMod;
    while(exp >= levelExp)
    {
        exp -= levelExp;
        level++;
        modifyHealth(5);
        modifyStrength(1);
        modifyDefense(1);
        levelExp = level*10;
    }
        
}*/
