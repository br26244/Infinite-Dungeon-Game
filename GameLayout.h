
#ifndef __GAME_LAYOUT_H__
#define __GAME_LAYOUT_H__

#include "Item.h"

class GameLayout {
private:
    int hp, str, def, exp, level, xCoord, yCoord, gold;

public:
    GameLayout();
    GameLayout(int hp, int str, int def, int exp, int level, int xCoord, int yCoord, int gold);
    ~GameLayout();

    void useItem(Item newItem);
    int getHp() const;
    int getStr() const;
    int getDef() const;
    int getExp() const;
    int getLevel() const;
    int getXCoord() const;
    int getYCoord() const;
    int getGold() const;
    
    void printStatus(); 
};

#endif // __GAME_LAYOUT_H__
