#include "gameSystem.h"

gameSystem::gameSystem(){
    Floor mainFloor;
    this->mainFloor = mainFloor;
    Entity entity;
    this->player = entity;
    Customization customization;
    this->customization = customization;
    GameLayout gameLayout;
    this->gameLayout = gameLayout;
    this->gameRunning = true;
    this->currentFloor = 0;
}

gameSystem::~gameSystem(){
    
}

void gameSystem::startGame(){
    if(Menu::run() == 1){
        customization.showFirstOption();
        customization.showSecondOption();
        customization.showThirdOption();
        enterFloor(randomizeFloor());
    }
}

void gameSystem::enterFloor(string level){
    this->currentFloor = mainFloor.getFloorNumber();
    mainFloor.clearFloor();
    mainFloor.loadFloor(level);
    mainFloor.printFloor();
    gameLayout.printStatus();
}

void gameSystem::getMoveInput(){
    char temp;
    temp = getch();
    mainFloor.moveCharacter(temp, player);
    mainFloor.printFloor();
    gameLayout.printStatus();
    if(this->currentFloor != mainFloor.getFloorNumber()){
        enterFloor(randomizeFloor());
    }
    
}

string gameSystem::randomizeFloor(){
    int randNum = (rand() % 3) + 1;
    if((this->mainFloor.getFloorNumber() - (4*(this->mainFloor.getFloorNumber()/4))) % 4 == 0){
        return "./Levels/FourOne.txt";
    }else if((this->mainFloor.getFloorNumber() - (4*(this->mainFloor.getFloorNumber()/4))) % 3 == 0){
        if(randNum == 1){
             return "./Levels/ThreeOne.txt";
        }else if(randNum == 2){
            return "./Levels/ThreeTwo.txt";
        }else{
            return "./Levels/ThreeThree.txt";
        }
    }else if((this->mainFloor.getFloorNumber() - (4*(this->mainFloor.getFloorNumber()/4))) % 2 == 0){
        if(randNum == 1){
             return "./Levels/TwoOne.txt";
        }else if(randNum == 2){
            return "./Levels/TwoTwo.txt";
        }else{
            return "./Levels/TwoThree.txt";
        }
    }else{
        if(randNum == 1){
             return "./Levels/OneOne.txt";
        }else if(randNum == 2){
            return "./Levels/OneTwo.txt";
        }else{
            return "./Levels/OneThree.txt";
        }
    }
    return "junk";
}

bool gameSystem::getGameStatus(){
    return this->gameRunning;
}

void gameSystem::death(){
    system("clear");
    cout << "You Died!" << endl;
    cout << "You made it to floor " << mainFloor.getFloorNumber() << endl;
    cout << "Press 'r' to go back to menu" << endl;
    string input;
    cin >> input;
}