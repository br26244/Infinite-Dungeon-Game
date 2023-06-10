#include "floor.h"
#include "../Entities/Entity.h"
#include "../Entities/PlayerChar.h"
#include "../Enemy/Enemy.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <random>

using namespace std;

Floor::Floor(){
    this->floor = 1;
}

void Floor::loadFloor(string file){

    //read in floor
    ifstream floor;

    floor.open(file);
    if(floor.fail()){
        perror(file.c_str());
        system("PAUSE");
        exit(1);
    }

    string line;

    while(getline(floor, line)){
        floorData.push_back(line);
    }

    floor.close();
    spawnMonsters();
    spawnItems();
}

int Floor::getPlayerX(){
    char spot;
    for(int y = 0; y < floorData.size(); y++){
        for(int x = 0; x < floorData[y].size(); x++){
            spot = floorData[y][x];
            if(spot == '@'){
                return x;
            }
        }
    }
    return 0;
}

int Floor::getPlayerY(){
    char spot;
    for(int y = 0; y < floorData.size(); y++){
        for(int x = 0; x < floorData[y].size(); x++){
            spot = floorData[y][x];
            if(spot == '@'){
                return y;
            }
        }
    }
    return 0;
}

void Floor::printFloor(){
    system("clear");
    for(int i = 0; i < floorData.size(); i++){
        cout << floorData[i] << endl;
    }

}

void Floor::clearFloor(){
    floorData.clear();
}

void Floor::moveCharacter(char input, PlayerChar &player)
{
    int inputEnum = 0;
    if(input == 'w' || input == 'W')
    {
        inputEnum = 1;
    }
    else if(input == 'a' || input == 'A')
    {
        inputEnum = 2;
    }
    else if(input == 's' || input == 'S')
    {
        inputEnum = 3;
    }
    else if(input == 'd' || input == 'D')
    {
        inputEnum = 4;
    }

    switch(inputEnum)
    {
        case 1:
            if(boundaryCheck(player.x, player.y-1, player))
            {
                floorData[player.y][player.x] = '_';
                floorData[player.y-1][player.x] = '@';
                player.y -= 1;
            }
            break;
        case 2:
            if(boundaryCheck(player.x-1, player.y, player))
            {
                floorData[player.y][player.x] = '_';
                floorData[player.y][player.x-1] = '@';
                player.x -= 1;
            }
            break;
        case 3:
            if(boundaryCheck(player.x, player.y+1, player))
            {
                floorData[player.y][player.x] = '_';
                floorData[player.y+1][player.x] = '@';
                player.y += 1;
            }
            break;
        case 4:
            if(boundaryCheck(player.x+1, player.y, player))
            {
                floorData[player.y][player.x] = '_';
                floorData[player.y][player.x+1] = '@';
                player.x += 1;
            }
            break;
    }
    updateEnemies(player);
}

bool Floor::boundaryCheck(int xCoord, int yCoord, PlayerChar &player)
{
    if(floorData[yCoord][xCoord] != '_' && floorData[yCoord][xCoord] != 'g')
    {
        if(floorData[yCoord][xCoord] == 's'){
            this->floor += 1;
        }
        if(floorData[yCoord][xCoord] == 'S' || floorData[yCoord][xCoord] == 'D' || floorData[yCoord][xCoord] == 'Z')
        {
            if(enemyAttacking(xCoord,yCoord, player))
            {
                return true;
            }
        }
        return false;
    }
    else
    {
        if(floorData[yCoord][xCoord] == 'g'){
            player.modifyGold(1);
        }
        return true;
    
    }
    return false;
    
}

int Floor::getFloorNumber(){
    return this->floor;
}

void Floor::setSym(int x, int y, char tile) {
	floorData[y][x] = tile;

}

char Floor::getSym(int x, int y){
	return floorData[y][x];
}

void Floor::updateEnemies(Entity &player) {
	char aiMove;
	int playerX;
	int playerY;
	int enemyX;
	int enemyY;


	playerX = player.x;
    playerY = player.y;
	for (int i = 0; i < enemies.size(); i++) {
		aiMove = enemies[i].getMove(playerX, playerY);
		enemies[i].getPosition(enemyX, enemyY);
	
	switch (aiMove) {
	case 'w':

		processEnemyMove(player, i, enemyX, enemyY - 1);

		break;
	case 's':

		processEnemyMove(player, i, enemyX, enemyY + 1);

		break;
	case 'a':
		processEnemyMove(player, i, enemyX - 1, enemyY);
		break;
	case 'd':
		processEnemyMove(player, i , enemyX + 1, enemyY);
		break;

	}
	}
}

//please add to most update floor file
void Floor::processEnemyMove(Entity &player, int enemyIndex, int targetX, int targetY) {
	int playerX;
	int playerY;
	int enemyX;
	int enemyY;

	enemies[enemyIndex].getPosition(enemyX, enemyY);
	playerX = player.x;
    playerY = player.y;

	char moveTile = getSym(targetX, targetY);

	switch (moveTile) {
	case '_':
		enemies[enemyIndex].setPosition(targetX, targetY);
		setSym(enemyX, enemyY, '_');
		setSym(targetX, targetY, enemies[enemyIndex].getTile());
		break;
	case '#':
		break;
    case '@':
        //battleMonster(player, enemyX, enemyY);
        break;
	default:
		break;
	}
}

//please add to most update floor file
void Floor::spawnMonsters(){
    unsigned seed = time(0);
    srand(seed);
    char tile = 'S';
    int randY = rand()%(floorData.size());
    int randX = rand()%(floorData.size());
    for(unsigned i = 0; i < (floorData.size() / 5) ; ++i){
    while(floorData[randY][randX] != '_'){
        randY = rand()%(floorData.size() );
        randX = rand()%(floorData.size() );
    }
    int chance = rand() % 10 + 1;
    if(chance >= 1 && chance <= 5){
        tile = 'S';
    }
    else if(chance >= 6 && chance <= 9){
        tile = 'Z';
    }
    else{
        tile = 'D';
    }

    switch (tile) {
				case 'S'://Snake
                    floorData[randY][randX] = tile;
					enemies.push_back(Enemy("Snake", tile, 1, 1, 1, 5, 1));
					enemies.back().setPosition(randY, randX);
					break;
				case 'Z':
                    floorData[randY][randX] = tile;
					enemies.push_back(Enemy("Zombie", tile, 3, 5, 10, 10, 5));
					enemies.back().setPosition(randY, randX);
					break;
				case 'D':
                    floorData[randY][randX] = tile;
					enemies.push_back(Enemy("Dragon", tile, 30, 60, 90, 90, 100));
					enemies.back().setPosition(randY, randX);
					break;
    	}	}
}

//please add to most update floor file
void Floor::spawnItems(){
    unsigned seed = time(0);
    srand(seed);
    char tile = 'h';
    int randY = rand()%(floorData.size() - 2);
    int randX = rand()%(floorData.size() - 2);
    for(unsigned i = 0; i < 2 ; ++i){
    while(floorData[randY][randX] == '@' || floorData[randY][randX] == '#' || floorData[randY][randX] == 'S' || floorData[randY][randX] == 'h' || floorData[randY][randX] == 'Z'  || floorData[randY][randX] == 'D' || floorData[randY][randX] == ' '){
        randY = rand()%(floorData.size() - 2);
        randX = rand()%(floorData.size() - 2);
    }
    floorData[randY][randX] = tile;
    Item Health(0,randX,randY);
    items.push_back(Health);
    }
}

void Floor::identifyItem(Entity& player, int x, int y){
    if(floorData[y][x] == 'h' || floorData[y][x] == 'H' || floorData[y][x] == '^' || floorData[y][x] == 'O' || floorData[y][x] == '*' || floorData[y][x] == '%'){
        char itemSymbol = floorData[y][x];
        itemPickUp(player, x,y, itemSymbol);
    }
}

void Floor::itemPickUp(Entity& player, int xPoint, int yPoint, char itemType){
    for(unsigned i = 0; i < items.size(); ++i){
        if(((items.at(i)).getX() == xPoint) && ((items.at(i)).getX() == yPoint ) && ((items.at(i)).used == false) ){
            items.at(i).modPlayer(player);
            floorData[yPoint][xPoint] == '_';
            items.at(i).used == true;
        }
    }
}



bool Floor::enemyAttacking(int playerX, int playerY, PlayerChar &player)
{
    for(unsigned i = 0; i < enemies.size(); ++i){
        if(playerX == enemies.at(i).getX() && playerY == enemies.at(i).getY()){
            if(DamageInteraction::entityDamage(enemies.at(i), player))
            {
                enemies.at(i).setPosition(1,1);
                return true;
            }
        }
    }
    return false;
}