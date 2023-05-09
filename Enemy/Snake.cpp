#include "Snake.h"
#include <iostream>
using namespace std;
 
Snake(int health = 20, int damage = 5, int x, int y, int speed ) : Enemy(health, damage, x, y, speed) {}

char getSymbol() const override {
    return 's';
}   // Override the getSymbol function to return 's'
    