#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <iostream>

using namespace std;

class Enemy {
public:
    Enemy(int health, int damage);
    virtual ~Enemy();

    static void addMonster(Enemy monster);
    virtual char getSymbol() const = 0;  // Pure virtual function to get the enemy's symbol
    virtual void attack() const = 0;     // Pure virtual function to make the enemy attack

    int getHealth() const;
    void setHealth(int health);
    int getDamage() const; 
    void setDamage(int damage);
    void move();

private:
    int mon_health;
    int mon_damage;
    static vector<Enemy> mon_monsters;
    char symbol;
    int x, y;
    int speed;

    string mon_name;
};
#endif