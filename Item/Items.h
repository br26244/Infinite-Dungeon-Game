#include <string>
#include "../Entities/Entity.h"
#ifndef __ITEMS_H__
#define __ITEMS_H__
using namespace std;

class Item
{

public:
	Item(int itemId, int xPoint, int yPoint);
	string getName();
	int getHealAmount();
	int getStrUp();
	int getDefUp();
	int getEXP();
	int getId();
	int getX();
	int getY();
	void modPlayer(Entity& player);
	bool used;

private:
	string name;
	string description;

	int id;
	char sym;
	int healAmount;
	int healthLossAmount;
	int strengthUp;
	int defenceUp;
	int exp;
	
	int x;
	int y;

};
#endif