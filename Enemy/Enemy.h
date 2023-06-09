#ifndef __ENEMY_H__
#define __ENEMY_H__
#include <ctime>
#include <string>
#include <iostream>
#include <random>

using namespace std;
class Enemy{
    public:
	Enemy(string name, char tile, int level, int attack, int defense , int health);
	
	//int attack();
	//setters
	void setPosition(int x, int y);
	void setHealth(int hp);
	void setDefense(int dp);
	int getHealth();
	int getDefense();
	int getAttack();
	int getX();
	int getY();
	//Getters
	void getPosition(int &x, int &y);
	string getName() { return _name; }
	//int takeDamage(int attack);
	char getTile() { return _tile; }
	//Gets AI move command
	char getMove(int playerX, int playerY);

	int _x;
	int _y;



    private:
	string _name;
	char _tile;
	int _level;
	int _attack;
	int _defense;
	int _health;
    
	//Position
	
};
#endif