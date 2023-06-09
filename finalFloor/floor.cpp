#include "floor.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cstdio>

using namespace std;

Floor::Floor(){

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
                cout <<"player found at " << x << ", " << y << endl;
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
                cout <<"player found at " << x << ", " << y << endl;
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

void Floor::moveCharacter(char input, Entity &player)
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
            if(boundaryCheck(player.xAccess(), player.yAccess()-1, player))
            {
                floorData[player.yAccess()][player.xAccess()] = '_';
                floorData[player.yAccess()-1][player.xAccess()] = '@';
                player.setY(player.yAccess() - 1);
            }
            break;
        case 2:
            if(boundaryCheck(player.xAccess()-1, player.yAccess(), player))
            {
                floorData[player.yAccess()][player.xAccess()] = '_';
                floorData[player.yAccess()][player.xAccess()-1] = '@';
                player.setX(player.xAccess() - 1);
            }
            break;
        case 3:
            if(boundaryCheck(player.xAccess(), player.yAccess()+1, player))
            {
                floorData[player.yAccess()][player.xAccess()] = '_';
                floorData[player.yAccess()+1][player.xAccess()] = '@';
                player.setY(player.yAccess() + 1);
            }
            break;
        case 4:
            if(boundaryCheck(player.xAccess()+1, player.yAccess(), player))
            {
                floorData[player.yAccess()][player.xAccess()] = '_';
                floorData[player.yAccess()][player.xAccess()+1] = '@';
                player.setX(player.xAccess() + 1);
            }
            break;
    }
    updateEnemies(player);
}

//please add changes to most update floor file
bool Floor::boundaryCheck(int xCoord, int yCoord,Entity& player)
{
    if(floorData[yCoord][xCoord] == 'h'){
        identifyItem(player,xCoord,yCoord);
    }
    if(floorData[yCoord][xCoord] != '_')
    {
       /* if(floorData[yCoord][xCoord] == 'S' || floorData[yCoord][xCoord] == 'Z' || floorData[yCoord][xCoord] == 'D'){
            battleMonster(player, xCoord, yCoord);
        }*/
        cout << "There is something in the way!" << endl;
        return false;
    }
    else
    {
        return true;
    }
    return false;
    
}

//please add to most update floor file
void Floor::setSym(int x, int y, char tile) {
	floorData[y][x] = tile;

}

//please add to most update floor file
char Floor::getSym(int x, int y){
	return floorData[y][x];
}

//please add to most update floor file
void Floor::updateEnemies(Entity &player) {
	char aiMove;
	int playerX;
	int playerY;
	int enemyX;
	int enemyY;


	player.returnXY(playerX, playerY);
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
	player.returnXY(playerX, playerY);

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
    int randY = rand()%(floorData.size()) + 1;
    int randX = rand()%(floorData.size()) + 1;
    for(unsigned i = 0; i < (floorData.size() / 5) ; ++i){
    while(floorData[randY][randX] == '@' || floorData[randY][randX] == '#' || floorData[randY][randX] == 'S' || floorData[randY][randX] == 'Z' || floorData[randY][randX] == 'D' || floorData[randY][randX] == 'h'  ){
        randY = rand()%(floorData.size() ) + 1;
        randX = rand()%(floorData.size() ) + 1;
    }
    int chance = rand() % 10 + 1;
    if(chance >= 1 && chance <= 5){
        tile = 'S';
    }
    else if(chance >= 6 && chance <= 8){
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
    int randY = rand()%(floorData.size() - 2) + 1;
    int randX = rand()%(floorData.size() - 2) + 1;
    for(unsigned i = 0; i < 2 ; ++i){
    while(floorData[randY][randX] == '@' || floorData[randY][randX] == '#' || floorData[randY][randX] == 'S' || floorData[randY][randX] == 'h' || floorData[randY][randX] == 'Z'  || floorData[randY][randX] == 'D' ){
        randY = rand()%(floorData.size() - 2) + 1;
        randX = rand()%(floorData.size() - 2) + 1;
    }
    floorData[randY][randX] = tile;
    Item Health(0,randX,randY);
    items.push_back(Health);
    }
}

/*
void Floor::battleMonster(Entity &player, int targetX, int targetY) {
	int enemyX;
	int enemyY;
	int attackRoll;
	int attackResult;
	int playerX;
	int playerY;
	string enemyName;

	playerX = player.xAccess();
    playerY = player.yAccess();


	for (int i = 0; i < enemies.size(); i++) {
		enemies[i].getPosition(enemyX, enemyY);
		enemyName = enemies[i].getName();
		if (targetX == enemyX && targetY == enemyY) {
			attackRoll = player.attack();
			printf("\nPlayer attacked %s with a roll of: %d\n", enemyName.c_str(), attackRoll);
			attackResult = enemies[i].takeDamage(attackRoll);
			if (attackResult != 0) {
				setSym(targetX, targetY, '_');
				printFloor();
				printf("Monster died!\n");
				
				//Remove the enemy
				enemies[i] = enemies.back();
				enemies.pop_back();
				i--;
				system("PAUSE");
				//player.addExperience(attackResult);

				

				return;
			}
			
			attackRoll = enemies[i].attack();
			printf("%s attacked player with a roll of: %d\n", enemyName.c_str(), attackRoll);

			attackResult = player.takeDamage(attackRoll);

			if (attackResult != 0) {
				
				setSym(playerX, playerY, 'X');
				printf("You died!\n");
				printFloor();
				system("PAUSE");
				
				exit(0);
				return;
			}
			
			system("PAUSE");

			return;
		}

	}


}
*/
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
