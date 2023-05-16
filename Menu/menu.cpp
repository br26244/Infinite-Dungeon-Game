#include "menu.h"
#include <limits>

using namespace std;

void Menu::displayMenu() {
     system("clear");
    cout << "Dungeon Hero - Roguelike Game" << endl;
    cout << "-------------------------------" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Quit" << endl;
}

int Menu::getUserChoice() {
    int choice;
    
    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (choice >= MenuOption::START_GAME && choice <= MenuOption::QUIT) {
            break;
        }
    }
    system("clear");
    return choice;
}

int Menu::run() {
    int userChoice;
    
    do {
        userChoice = getUserChoice();
        
        switch (userChoice) {
            case MenuOption::START_GAME:
                return 1;
                break;
            case MenuOption::QUIT:
                cout << "Thanks for playing Dungeon Hero. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (userChoice != MenuOption::QUIT);
    return 0;
}