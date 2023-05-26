#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "Enemy.h"

class Snake : public Enemy<Snake> {
public:
    Snake();
    Snake(int level = 1, string name = "snake", char view = 's', int health = 5, int str = 2, int def = 1, int xCoord = 0, int yCoord = 0);
    virtual ~Snake();

    void applyLevelBoost();
};

#endif