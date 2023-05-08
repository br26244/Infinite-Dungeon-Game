#include "entity.h"
#include "floor.h"
#include "floor.cpp"
#include <iostream>
#include <string.h>


//player char constructors
Entity::Entity()
{
    health = 0;
    str = 0;
    def = 0;
    xCoord = 0;
    yCoord = 0;
}
Entity::Entity(int health, int str, int def, int xCoord, int yCoord)
{
    this->health = health;
    this->str = str;
    this->def = def;
    this->xCoord = xCoord;
    this->yCoord = yCoord;
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
int Entity::xAccess()
{
    return xCoord;
}
int Entity::yAccess()
{
    return yCoord;
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
