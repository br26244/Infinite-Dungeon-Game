
// menu.h
#ifndef MENU_H
#define MENU_H

#include <iostream>

class MenuOption {
public:
    static const int START_GAME = 1;
    static const int QUIT = 2;
};

class Menu {
public:
    static void displayMenu();
    static int getUserChoice();
    static void run();
};

#endif 
