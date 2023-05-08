
#include "menu.h"
#include <limits>

using namespace std;

void displayMenu() {
    cout << "Dungeon Hero - Roguelike Game" << endl;
    cout << "-------------------------------" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Quit" << endl;
}

MenuOption getUserChoice() {
    int choice;
    
    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (choice >= 1 && choice <= 2) {
            break;
        }
    }
    
    return static_cast<MenuOption>(choice);
}
