#include "Enemy.h"

Enemy::Enemy(int level, string name, char symbol, int health, int damage, int defense, int xcor, int ycor) :
    Entity(health, damage, defense, xcor, ycor), mon_level(level), mon_name(name), symbol(symbol) {}

void Enemy::addMonster(T monster) {
    mon_monsters.push_back(monster);
}

int Enemy::getHealth() const {
    return health; 
}

string Enemy::getName() const {
    return mon_name;
}

void Enemy::setHealth(int hp) {
    health = hp;
}

int Enemy::getDamage() const {
    return str;
}

void Enemy::setDamage(int damage) {
    str = damage;
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

