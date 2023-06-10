#ifndef __DAMAGEINTERACTION_H__
#define __DAMAGEINTERACTION_H__
#include "Entity.h"
#include "../Enemy/Enemy.h"
#include "PlayerChar.h"


class DamageInteraction
{
    private:

    public:
        static bool entityDamage(Enemy &targetEnemy, PlayerChar &targetChar);

};

#endif
