#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "Entity.h"
template <class T>
class Enemy : public Entity {
public:
    Enemy(int level, string name, char symbol, int health, int damage, int defense, int xcor, int ycor);
    virtual ~Enemy() = default;

    void addMonster(T monster);
    virtual char getSymbol() const = 0;  // Pure virtual function to get the enemy's symbol

    int getHealth() const;
    void setHealth(int health);
    int getDamage() const;
    void setDamage(int damage);
    void move();

protected:
    vector<T> mon_monsters;
    int mon_level;
    string mon_name;
    char symbol;
};
#endif