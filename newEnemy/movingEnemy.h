#ifndef __MOVINGENEMY_H__
#define __MOVINGENEMY_H__
#include "Enemy.h"

class MovingEnemy : public Enemy{
    public:
    char getMove(int playerX, int playerY, Enemy&);
};
#endif