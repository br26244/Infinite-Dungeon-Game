

#ifndef MENU_H
#define MENU_H

#include <iostream>

enum class MenuOption {
    START_GAME = 1,
    QUIT
};

void displayMenu();
MenuOption getUserChoice();

#endif
