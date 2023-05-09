#include "Item.h"


Item::Item(int itemId){
    if(itemId == 0){
        name = "Healing Potion";
		id = 0;
		healAmount = 50;
		strengthUp = 0;
		defenceUp = 0;
		exp = 0;
		used = false;
	    break;
    }

	if(itemId == 1){
		name = "Super Healing Potion";
		id = 1;
		healAmount = 100;
		strengthUp = 0;
		exp = 0;
		used = false;
	    break;
    }

	if(itemId == 2){
		name = "Sword";
		id = 2;
		healAmount = 0;
		strengthUp = 5;
		defenceUp = 0;
		exp = 0;
		used = false;
		break;
    }

	if(itemId == 3){
		name = "Shield";
		id = 3;
		healAmount = 0;
		strengthUp = 0;
		defenceUp = 5;
		exp = 0;
		used = false;
		break;
    }

	if(itemId == 4){
		name = "EXP potion";
		id = 4;
		healAmount = 0;
		strengthUp = 0;
		defenceUp = 0;
		exp = 0;
		used = false;
		break;
    }

	if(itemId == 5){
		name = "Super EXP Potion";
		id = 5;
		healAmount = 0;
		strengthUp = 0;
		defenceUp = 0;
		exp = 20;
		used = false;
		break;
	}
}

std::string Item::getName()
{
	return name;
}

int Item::getHealAmount()
{
	return healAmount;
}

int Item::getStrUp()
{
	return strengthUp;
}

int Item::getDefUp()
{
	return defenceUp;
}

int Item::getEXP()
{
	return exp;
}

int Item::getId()
{
	return id;
}

