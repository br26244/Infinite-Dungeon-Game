#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../newEnemy/Enemy.cpp"
#include "DamageInteraction.cpp"
#include "levelUp.cpp"
#include "Entity.cpp"
#include "PlayerChar.cpp"


TEST(Constructors, constructEntity1){
    Entity testEntity = new Entity(1, 1, 1, 1, 0, 0);
    ASSERT_EQ(testEntity.hpAccess(),1);
    ASSERT_EQ(testEntity.strAccess(),1);
    ASSERT_EQ(testEntity.defAccess(),1);
    ASSERT_EQ(testEntity.levelAccess(),1);
    ASSERT_EQ(testEntity.xAccess(),0);
    ASSERT_EQ(testEntity.yAccess(),0);
}

TEST(Constructors, constructPlayer){
    PlayerChar testChar = new PlayerChar(1, 1, 1, 1, 1, 0, 0, 1);
    ASSERT_EQ(testEntity.hpAccess(),1);
    ASSERT_EQ(testEntity.strAccess(),1);
    ASSERT_EQ(testEntity.defAccess(),1);
    ASSERT_EQ(testEntity.levelAccess(),1);
    ASSERT_EQ(testEntity.expAccess(),1);
    ASSERT_EQ(testEntity.xAccess(),0);
    ASSERT_EQ(testEntity.yAccess(),0);
    ASSERT_EQ(testEntity.accessGold(),0);
}   

TEST(LevelUP, testLeveling){
    PlayerChar testChar = new PlayerChar(0, 0, 0, 0, 3, 0, 0, 0);
    testChar.modifyEXP(40);
    levelUp::charLevelUp(testChar);
    EXPECT_EQ(testChar.levelAccess(), 4);
}

TEST(LevelUP, testExcessExp){
    PlayerChar testChar = new PlayerChar(0, 0, 0, 0, 3, 0, 0, 0);
    testChar.modifyEXP(40);
    levelUp::charLevelUp(testChar);
    EXPECT_EQ(testChar.expAccess(), 10);
}

TEST(LevelUP, levelUpOnKill){
    PlayerChar testChar = new PlayerChar(10, 10, 1, 5, 1, 0, 0, 0);
    Enemy testEnemy = new Enemy("snake", 's', 1, 1, 0, 5);
    DamageInteraction::entityDamage(testEnemy, testChar);
    EXPECT_EQ(testChar.levelAccess(), 2);
}



TEST(DamagingEnemies, damageTest1){
    PlayerChar testChar = new PlayerChar(10, 2, 0, 0, 1, 0, 0, 0);
    Enemy testEnemy = new Enemy("snake", 's', 1, 1, 0, 5);
    DamageInteraction::entityDamage(testEnemy, testChar);
    EXPECT_EQ(testChar.hpAccess(), 9);
}

TEST(DamagingEnemies, damageTest2){
    PlayerChar testChar = new PlayerChar(10, 2, 0, 0, 1, 0, 0, 0);
    Enemy testEnemy = new Enemy("snake", 's', 1, 1, 0, 5);
    DamageInteraction::entityDamage(testEnemy, testChar);
    EXPECT_EQ(testEnemy.getHealth(), 3);
}

TEST(DamagingEnemies, defenseTest1){
    PlayerChar testChar = new PlayerChar(10, 2, 1, 0, 1, 0, 0, 0);
    Enemy testEnemy = new Enemy("snake", 's', 1, 1, 0, 5);
    DamageInteraction::entityDamage(testEnemy, testChar);
    EXPECT_EQ(testChar.hpAccess(), 10);
}


