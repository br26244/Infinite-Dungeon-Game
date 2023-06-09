#ifndef __DAMAGEINTERACTION_H__
#define __DAMAGEINTERACTION_H__
#include "Entity.h"
#include "../newEnemy/Enemy.h"
#include "PlayerChar.h"


class DamageInteraction
{
    private:

    public:
        static void entityDamage(Enemy& targetEnemy, Entity &targetChar);

};

#endif
