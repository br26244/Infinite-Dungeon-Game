#include <string>
#ifndef __ITEM_H__
#define __ITEM_H__
using namespace std;

class Item
{

public:
	Item(int itemId);
	string getName();
	int getHealAmount();
	int getStrUp();
	int getDefUp();
	int getEXP();
	int getId();

private:
	string name;
	string description;

	int id;
	int healAmount;
	int healthLossAmount;
	int strengthUp;
	int defenceUp;
	int exp;
	bool used;

};