#include "Enemy.h"
#include <iostream>

using namespace std;

Enemy(string name, int health, int damage) : mon_name(name), mon_symbol(symbol), mon_health(health), mon_attack(attack) {}

static void addMonster(Enemy monster) {
    mon_monsters.push_back(monster);
}

int Enemy::getHealth()const {
    return mon_health; 
}

string Enemy::getName() const{
    return mon_name;
}

void Enemy::setHealth(int health){ 
    mon_health = health;
}

int Enemy::getDamage() const {
    return mon_damage;
}
void Enemy::setDamage(int damage) {
    mon_damage = damage;
}

void move() {
    // Generate a random number between 0 and 3
    int direction = rand() % 4;

    if(direction == 0){// Move up
            y -= speed;
            break;
    }
    if(direction == 1){ // Move down
            y += speed;
            break;
    }
    if(direction == 2){ // Move left
            x -= speed;
            break;
    }
    if(direction == 3){ // Move right
            x += speed;
            break;
    }
}

