
#include "GameLayout.h"
#include <iostream>


GameLayout::GameLayout() : hp(20), str(16), def(0), exp(0), level(1), xCoord(0), yCoord(0), gold(0) {}

GameLayout::GameLayout(int hp, int str, int def, int exp, int level, int xCoord, int yCoord, int gold) 
    : hp(hp), str(str), def(def), exp(exp), level(level), xCoord(xCoord), yCoord(yCoord), gold(gold) {}

GameLayout::~GameLayout() {}


void GameLayout::useItem(Item newItem) {
    hp += newItem.getHealAmount();
    str += newItem.getStrUp();
    def += newItem.getDefUp();
    exp += newItem.getEXP();
}

// Getters
int GameLayout::getHp() const { return hp; }
int GameLayout::getStr() const { return str; }
int GameLayout::getDef() const { return def; }
int GameLayout::getExp() const { return exp; }
int GameLayout::getLevel() const { return level; }
int GameLayout::getXCoord() const { return xCoord; }
int GameLayout::getYCoord() const { return yCoord; }
int GameLayout::getGold() const { return gold; }

// UI method
void GameLayout::printStatus() {
    std::cout << "Level " << level << " Gold " << gold << " Hp " << hp << "/20 Str " << str
              << "/16 Arm " << def << " Exp " << exp << "/4" << std::endl;
}
