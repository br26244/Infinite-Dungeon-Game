#ifndef GAMESYSTEM
#define GAMESYSTEM

#include "../FloorGeneration/floor.cpp"
#include "../Entities/entity.cpp"
#include "../conio.h/conio.h"
#include "../Menu/menu.cpp"
#include "../Customization/customization.cpp"
#include "../GameLayout/GameLayout.cpp"

class gameSystem{
    private:
        Floor mainFloor;
        Entity player;
        Customization customization;
        GameLayout gameLayout;
        bool gameRunning;
        int currentFloor;
    public:
        gameSystem();
        ~gameSystem();
        
        void startGame();
        void enterFloor(string level);
        void getMoveInput();
        string randomizeFloor();
        bool getGameStatus();
        void death();

};

#endif