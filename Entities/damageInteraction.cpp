#include "PlayerChar.h"
#include "Entity.h"
#include "damageInteraction.h"
#include <iostream>
#include <string.h>

void damageInteraction::EntityDamage(Entity &targetChar1, Entity &targetChar2)
{
    targetChar1.modifyHealth(-(targetChar2.strAccess()-targetChar1.defAccess()));
    if(targetChar2.hpAccess() <= 0)
    {
        targetChar2.modifyDeathState(true);
        targetChar1.modifyExp(targetChar2.expAccess());
    }
    else
    {
        targetChar2.modifyHealth(-(targetChar1.strAccess()-targetChar2.defAccess()));
        if(targetChar1.hpAccess() <= 0)
        {
            targetChar1.modifyDeathState(true);
            targetChar2.modifyExp(targetChar1.expAccess());
        }
    }
}