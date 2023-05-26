#include "gameSystem.h"

gameSystem::gameSystem(){
    Floor mainFloor;
    this->mainFloor = mainFloor;
    Entity entity;
    this->player = entity;
    Customization customization;
    this->customization = customization;
    this->gameRunning = true;
}

gameSystem::~gameSystem(){
    
}

void gameSystem::startGame(){
    if(Menu::run() == 1){
        customization.showFirstOption();
        customization.showSecondOption();
        customization.showThirdOption();
        enterFloor();
    }
}

void gameSystem::enterFloor(){
    mainFloor.clearFloor();
    mainFloor.loadFloor("./Levels/StartingLevel.txt");
    mainFloor.printFloor();
}

void gameSystem::getMoveInput(){
    char temp;
    temp = getch();
    mainFloor.moveCharacter(temp, player);
    mainFloor.printFloor();
}