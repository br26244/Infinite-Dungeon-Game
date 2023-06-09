#include "floor.h"
#include <fstream>
#include <iostream>

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

    unsigned seed = time(0);
    srand(seed);
    char tile = 'S';
    int randY = rand()%(floorData.size() - 2) + 1;
    int randX = rand()%(floorData.size() - 2) + 1;

    while(floorData[randY][randX] == '@' || floorData[randY][randX] == '#'  ){
        randY = rand()%(floorData.size() - 2) + 1;
        randX = rand()%(floorData.size() - 2) + 1;
    }
    floorData[randY][randX] = tile;
    Enemy Snake("Snake", 'S', 1,1,1,5);
    enemies.push_back(Snake);
    enemies.back().setPosition(randY, randX);
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
            if(boundaryCheck(player.xCoord, player.yCoord-1))
            {
                floorData[player.yCoord][player.xCoord] = '_';
                floorData[player.yCoord-1][player.xCoord] = '@';
                player.yCoord -= 1;
            }
            break;
        case 2:
            if(boundaryCheck(player.xCoord-1, player.yCoord))
            {
                floorData[player.yCoord][player.xCoord] = '_';
                floorData[player.yCoord][player.xCoord-1] = '@';
                player.xCoord -= 1;
            }
            break;
        case 3:
            if(boundaryCheck(player.xCoord, player.yCoord+1))
            {
                floorData[player.yCoord][player.xCoord] = '_';
                floorData[player.yCoord+1][player.xCoord] = '@';
                player.yCoord += 1;
            }
            break;
        case 4:
            if(boundaryCheck(player.xCoord+1, player.yCoord))
            {
                floorData[player.yCoord][player.xCoord] = '_';
                floorData[player.yCoord][player.xCoord+1] = '@';
                player.xCoord += 1;
            }
            break;
    }
}

bool Floor::boundaryCheck(int xCoord, int yCoord)
{
    if(floorData[yCoord][xCoord] != '_')
    {
        cout << "There is something in the way!" << endl;
        return false;
    }
    else
    {
        return true;
    }
    return false;
    
}

void Floor::setSym(int x, int y, char tile) {
	floorData[y][x] = tile;

}

char Floor::getSym(int x, int y){
	return floorData[y][x];
}

// void Floor::updateEnemies(Entity &player) {
// 	char aiMove;
// 	int playerX;
// 	int playerY;
// 	int enemyX;
// 	int enemyY;


// 	player.returnXY(playerX, playerY);
// 	for (int i = 0; i < enemies.size(); i++) {
// 		aiMove = enemies[i].getMove(playerX, playerY);
// 		enemies[i].getPosition(enemyX, enemyY);
	
// 	switch (aiMove) {
// 	case 'w':

// 		processEnemyMove(player, i, enemyX, enemyY - 1);

// 		break;
// 	case 's':

// 		processEnemyMove(player, i, enemyX, enemyY + 1);

// 		break;
// 	case 'a':
// 		processEnemyMove(player, i, enemyX - 1, enemyY);
// 		break;
// 	case 'd':
// 		processEnemyMove(player, i , enemyX + 1, enemyY);
// 		break;

// 	}
// 	}
// }

// void Floor::processEnemyMove(Entity &player, int enemyIndex, int targetX, int targetY) {
// 	int playerX;
// 	int playerY;
// 	int enemyX;
// 	int enemyY;

// 	enemies[enemyIndex].getPosition(enemyX, enemyY);
// 	player.returnXY(playerX, playerY);

// 	char moveTile = getSym(targetX, targetY);

// 	switch (moveTile) {
// 	case '_':
// 		enemies[enemyIndex].setPosition(targetX, targetY);
// 		setSym(enemyX, enemyY, '_');
// 		setSym(targetX, targetY, enemies[enemyIndex].getTile());
// 		break;
// 	case '#':
// 		break;
//     case '@':
//         break;
// 	default:
// 		break;
// 	}
// }
