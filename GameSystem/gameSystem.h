#ifndef GAMESYSTEM
#define GAMESYSTEM

#include "../FloorGeneration/floor.cpp"
#include "../Entities/entity.cpp"
#include "../conio.h/conio.h"
#include "../Menu/menu.cpp"
#include "../Customization/customization.cpp"

class gameSystem{
    private:
        Floor mainFloor;
        Entity player;
        Customization customization;
        bool gameRunning;
    public:
        gameSystem();
        ~gameSystem();
        
        void startGame();
        void enterFloor();
        void getMoveInput();

};

#endif