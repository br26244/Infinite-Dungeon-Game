#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Customization/customizationModulation.h"

TEST(Customization, checkConstructor){
    EXPECT_NO_THROW(CustomizationModulation *Mod = new CustomizationModulation());
}

TEST(Customization, checkHealth){
    CustomizationModulation Mod;
    Mod.increaseHealth(3);
    EXPECT_EQ(Mod.getHealth(), 3);
}

TEST(Customization, checkHealth2){
    CustomizationModulation Mod;
    Mod.increaseHealth(1);
    EXPECT_EQ(Mod.getHealth(), 1);
}

TEST(Customization, checkStr){
    CustomizationModulation Mod;
    Mod.increaseStr(3);
    EXPECT_EQ(Mod.getStr(), 3);
}

TEST(Customization, checkStr2){
    CustomizationModulation Mod;
    Mod.increaseStr(1);
    EXPECT_EQ(Mod.getStr(), 1);
}

TEST(Customization, checkGold){
    CustomizationModulation Mod;
    Mod.increaseGold(3);
    EXPECT_EQ(Mod.getGold(), 3);
}

TEST(Customization, checkGold2){
    CustomizationModulation Mod;
    Mod.increaseGold(1);
    EXPECT_EQ(Mod.getGold(), 1);
}

TEST(Customization, checkArm){
    CustomizationModulation Mod;
    Mod.increaseArm(3);
    EXPECT_EQ(Mod.getArm(), 3);
}

TEST(Customization, checkArm2){
    CustomizationModulation Mod;
    Mod.increaseArm(1);
    EXPECT_EQ(Mod.getArm(), 1);
}

