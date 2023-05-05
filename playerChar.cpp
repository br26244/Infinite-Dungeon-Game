#include "playerChar.h"
#include "entity.h"
#include "floor.h"
#include "floor.cpp"
#include <iostream>
#include <string.h>


//player char constructors
PlayerChar::PlayerChar() : Entity()
{
    invSize = 10;
    inventory = new Item*[invSize];
}
PlayerChar::PlayerChar(int health, int str, int def, Item **inventory, int xCoord, int yCoord) : Entity(int health, int str, int def, int xCoord, int yCoord)
{
    this->inventory = inventory;
}

~PlayerChar()
{
    for(int i = 0; i < invSize; i++)
    {
        delete inventory[i];
    }
    delete inventory;
}