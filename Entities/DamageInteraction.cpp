#include "PlayerChar.h"
#include "Entity.h"
#include "../Enemy/Enemy.h"
#include "DamageInteraction.h"
#include "levelUp.cpp"
#include <iostream>
#include <string.h>

bool DamageInteraction::entityDamage(Enemy &targetEnemy, PlayerChar &targetChar)
{
    targetEnemy.setHealth(targetEnemy.getHealth()-(targetChar.strAccess()-targetEnemy.getDefense()));
    cout << "Player struck for " << (targetChar.strAccess()-targetEnemy.getDefense()) << " damage!!\n"; 
    if(targetEnemy.getHealth() <= 0)
    {
        // targetEnemy.setDeathState(true);
        cout << "Enemy has been slain!\n";
        targetChar.modifyExp(5);
        cout << "You have gained 5 exp from this encounter!\n";
        levelUp::charLevelUp(targetChar);
        return true;
    }
    else
    {
        targetChar.modifyHealth(-(targetEnemy.getAttack()-targetChar.defAccess()));
        cout << "Player was hit for " << (targetEnemy.getAttack()-targetChar.defAccess()) << " damage!!\n";
        if(targetChar.hpAccess() <= 0)
        {
            targetChar.modifyDeathState(true);
            cout << "Player has been slain!\n";
            //targetEnemy.modifyExp(targetChar1.expAccess());
        }
    }
    return false;
}
