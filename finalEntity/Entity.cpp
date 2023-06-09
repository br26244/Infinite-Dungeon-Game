#include "Entity.h"
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
    xCoord = 1;
    yCoord = 1;
}
Entity::Entity(int health, int str, int def, int level, int xCoord, int yCoord)
{
    this->health = health;
    this->str = str;
    this->def = def;
    exp = 0;
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



void Entity::attack(Entity &oppTarget)
{
    oppTarget.modifyHealth(-str);
}

void Entity::returnXY(int &x, int&y){
    x = xCoord;
	y = yCoord;
}

void Entity::setX(int x){
    xCoord = x;
}

void Entity::setY(int y){
    yCoord = y;
}
int Entity::attack() {
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackRoll(0, str);
	return attackRoll(randomEngine);
}

int Entity::takeDamage(int attack) {
	attack -= def;
	//Cjecl of the attack does damage
	if (attack > 0) {
		health -= attack;
		//Check if he died
		if (health <= 0) {
			return 1;

		}

	}


	return 0;

}