#include "gameSystem.h"

gameSystem::gameSystem(){
    Floor mainFloor;
    this->mainFloor = mainFloor;
    PlayerChar player;
    this->player = player;
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
        customizeCharacter();
        enterFloor(randomizeFloor());
    }
}

void gameSystem::enterFloor(string level){
    this->currentFloor = mainFloor.getFloorNumber();
    mainFloor.clearFloor();
    mainFloor.loadFloor(level);
    mainFloor.printFloor();
    updateDisplay();
    gameLayout.printStatus();
    setCharacterPos();
    
}

void gameSystem::getMoveInput(){
    char temp;
    temp = getch();
    mainFloor.moveCharacter(temp, player);
    mainFloor.printFloor();
    updateDisplay();
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

void gameSystem::setCharacterPos(){
    this->player.x = mainFloor.getPlayerX();
    this->player.y = mainFloor.getPlayerY();
}

void gameSystem::customizeCharacter(){
    this->player.modifyGold(customization.getGold());
    this->player.modifyHealth(customization.getHealth());
    this->player.modifyStrength(customization.getStr());
    this->player.modifyDefense(customization.getArm());
}

void gameSystem::updateDisplay(){
    gameLayout.setAll(player.hpAccess(), player.strAccess(), player.defAccess(), player.expAccess(), player.levelAccess(), player.accessGold());
}