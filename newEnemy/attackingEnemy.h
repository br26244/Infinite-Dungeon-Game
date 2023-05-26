#ifndef __ATTACKINGENEMY_H__
#define __ATTACKINGENEMY_H__

#include "Enemy.h"

class AttackingEnemy : public Enemy{
    public:
    int attack(Enemy&);
    void takeDamage(int attack, Enemy& );
};
#endif

