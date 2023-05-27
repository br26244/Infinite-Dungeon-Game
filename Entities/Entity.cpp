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
    xCoord = 0;
    yCoord = 0;
}
Entity::Entity(int health, int str, int def, int level, int xCoord, int yCoord)
{
    this->health = health;
    this->str = str;
    this->def = def;
    exp = 0;
    isDead = false;
    this->level = level;
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
void Entity::modifyX(int xMod)
{
    xCoord = xMod;
}
void Entity::modifyY(int yMod)
{
    yCoord = yMod;
}






