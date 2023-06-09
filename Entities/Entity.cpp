#include "Entity.h"
//#include "levelUp.h"
//#include "floor.h"
//#include "floor.cpp"
#include <iostream>
#include <string.h>


//player char constructors
Entity::Entity()
{
    health = 0;
    str = 0;
    def = 0;
    exp = 0;
    level = 1;
    isDead = false;
    x = 0;
    y = 0;
}
Entity::Entity(int health, int str, int def, int level, int xCoord, int yCoord)
{
    this->health = health;
    this->str = str;
    this->def = def;
    exp = 0;
    isDead = false;
    this->level = level;
    x = xCoord;
    y = yCoord;
}

Entity::~Entity()
{

}

//setters and getters
int Entity::hpAccess()
{
    return health;
}
int Entity::strAccess()
{
    return str;
}
int Entity::defAccess()
{
    return def;
}
int Entity::expAccess()
{
    return exp;
}
bool Entity::isEntityDead()
{
    return isDead;
}
int Entity::levelAccess()
{
    return level;
}
int Entity::xAccess()
{
    return x;
}
int Entity::yAccess()
{
    return y;
}


void Entity::modifyHealth(int hpMod)
{
    health += hpMod;
}
void Entity::modifyStrength(int strMod)
{
    str += strMod;
}
void Entity::modifyDefense(int defMod)
{
    def += defMod;
}
void Entity::modifyExp(int expMod)
{
    exp += expMod;
}
void Entity::modifyDeathState(bool deathState)
{
    isDead = deathState;
}
void Entity::modifyLevel()
{
    level++;
}



/*void Entity::attack(Entity &oppTarget)
{
    oppTarget.modifyHealth(-str);
}


*/

//Character/entity movement and boundary checks
/*Entity::moveChar(Floor &floorData)
{
    int inputEnum = 0;
    char movement = '';
    if(movement == 'w' || movement == 'W')
    {
        inputEnum = 1;
    }
    else if(movement == 'a' || movement == 'A')
    {
        inputEnum = 2;
    }
    else if(movement == 's' || movement == 'S')
    {
        inputEnum = 3;
    }
    else if(movement == 'd' || movement == 'D')
    {
        inputEnum = 4;
    }

    switch(inputEnum)
    {
        case 1:
            if(boundaryCheck(floorData, xCoord, yCoord+1))
            {
                floorData[xCoord][yCoord] = "_";
                floorData[xCoord][yCoord+1] = "@";
                yCoord += 1;
            }
            break;
        case 2:
            if(boundaryCheck(floorData, xCoord-1, yCoord))
            {
                floorData[xCoord][yCoord] = "_";
                floorData[xCoord-1][yCoord] = "@";
                xCoord -= 1;
            }
            break;
        case 3:
            if(boundaryCheck(floorData, xCoord, yCoord-1))
            {
                floorData[xCoord][yCoord] = "_";
                floorData[xCoord][yCoord-1] = "@";
                yCoord -= 1;
            }
            break;
        case 1:
            if(boundaryCheck(floorData, xCoord+1, yCoord))
            {
                floorData[xCoord][yCoord] = "_";
                floorData[xCoord+1][yCoord] = "@";
                xCoord += 1;
            }
            break;
    }
}

bool Entity::boundaryCheck(Floor floorData, int xCoord, int yCoord)
{
    Floor tempFloor = floorData;
    if(tempFloor[xCoord][yCoord] != "_"
        && xCoord > 0
        && yCoord > 0
        && xCoord < tempFloor.xSize
        && xCoord < tempFloor.ySize;)
    {
        delete tempFloor;
        cout << "There is something in the way!";
        return false;
    }
    else
    {
        delete tempFloor;
        return true;
    }
    delete tempFloor;
    return false;
    
}

*/
