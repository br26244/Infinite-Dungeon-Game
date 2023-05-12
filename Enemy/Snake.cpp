#include "Snake.h"
#include <iostream>

using namespace std;

Snake::Snake() : Enemy<Snake>() {}

Snake::Snake(int level, string name, char view, int health, int str, int def, int xCoord, int yCoord)
    : Enemy<Snake>(level, name, view, health, str, def, xCoord, yCoord) {}

Snake::~Snake() {}

void Snake::applyLevelBoost() {
    int boost = getLevel() * 2;
    modifyStrength(boost);
    modifyHealth(boost);
    modifyDefense(boost);
}



    