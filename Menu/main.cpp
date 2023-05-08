
#include "menu.h"

using namespace std;

int main() {
    MenuOption userChoice;
    
    do {
        userChoice = getUserChoice();
        
        switch (userChoice) {
            case MenuOption::START_GAME:
                // Code to start the game
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
