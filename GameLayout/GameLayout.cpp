
#include "GameLayout.h"
#include <iostream>


GameLayout::GameLayout() : hp(20), str(16), def(0), exp(0), level(1), gold(0) {}

GameLayout::GameLayout(int hp, int str, int def, int exp, int level, int gold) 
    : hp(hp), str(str), def(def), exp(exp), level(level), gold(gold) {}

GameLayout::~GameLayout() {}


// Getters
int GameLayout::getHp() const { return hp; }
int GameLayout::getStr() const { return str; }
int GameLayout::getDef() const { return def; }
int GameLayout::getExp() const { return exp; }
int GameLayout::getLevel() const { return level; }
int GameLayout::getGold() const { return gold; }

// Setters
void GameLayout::setHP(int hp) { this->hp = hp; }
void GameLayout::setStr(int str) { this->str = str; }
void GameLayout::setDef(int def) { this->def = def; }
void GameLayout::setExp(int exp) { this->exp = exp; }
void GameLayout::setLevel(int level) { this->level = level; }
void GameLayout::setGold(int gold) { this->gold = gold; }
void GameLayout::setAll(int hp, int str, int def, int exp, int level, int gold){
    this->hp = hp;
    this->str = str;
    this->def = def;
    this->exp = exp;
    this->level = level;
    this->gold = gold;
};

// UI method
void GameLayout::printStatus() {
    std::cout << "Level " << level << " Gold " << gold << " Hp " << hp << "/20 Str " << str
              << "/16 Arm " << def << " Exp " << exp << "/10" << std::endl;
}
