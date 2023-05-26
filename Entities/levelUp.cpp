#include "PlayerChar.h"
#include "levelUp.h"
#include "Entity.h"
#include <iostream>
#include <string.h>

void levelUp::charLevelUp(Entity &playerCharacter)
{
    while(playerCharacter.expAccess() >= (playerCharacter.levelAccess()*10))
    {
        playerCharacter.modifyExp(-(playerCharacter.levelAccess()*10));
        playerCharacter.modifyLevel();
        playerCharacter.modifyHealth(5);
        playerCharacter.modifyStrength(1);
        playerCharacter.modifyDefense(1);
        
    }
}