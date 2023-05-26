#include "customizationModulation.h"
#include <iostream>

using namespace std;

CustomizationModulation::CustomizationModulation(){
    health = 0;
    gold = 0;
    arm = 0;
    str = 0;

}

CustomizationModulation::~CustomizationModulation(){
    
}

void CustomizationModulation::increaseHealth(int vHealth){
    this->health += vHealth;
}

void CustomizationModulation::increaseStr(int vStr){
    this->str += vStr;
}

void CustomizationModulation::increaseGold(int vGold){
    this->gold += vGold;
}

void CustomizationModulation::increaseArm(int vArm){
    this->arm += vArm;
}

int CustomizationModulation::getHealth(){
    return this->health;
}

int CustomizationModulation::getStr(){
    return this->str;
}

int CustomizationModulation::getGold(){
    return this->gold;
}

int CustomizationModulation::getArm(){
    return this->arm;
}