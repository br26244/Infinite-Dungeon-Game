#include "floor.h"
#include <fstream>
#include <iostream>

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
            if(boundaryCheck(player.x, player.y-1))
            {
                floorData[player.y][player.x] = '_';
                floorData[player.y-1][player.x] = '@';
                player.y -= 1;
            }
            break;
        case 2:
            if(boundaryCheck(player.x-1, player.y))
            {
                floorData[player.y][player.x] = '_';
                floorData[player.y][player.x-1] = '@';
                player.x -= 1;
            }
            break;
        case 3:
            if(boundaryCheck(player.x, player.y+1))
            {
                floorData[player.y][player.x] = '_';
                floorData[player.y+1][player.x] = '@';
                player.y += 1;
            }
            break;
        case 4:
            if(boundaryCheck(player.x+1, player.y))
            {
                floorData[player.y][player.x] = '_';
                floorData[player.y][player.x+1] = '@';
                player.x += 1;
            }
            break;
    }
}

bool Floor::boundaryCheck(int xCoord, int yCoord)
{
    if(floorData[yCoord][xCoord] != '_')
    {
        if(floorData[yCoord][xCoord] == 's'){
            this->floor += 1;
        }
        return false;
    }
    else
    {
        return true;
    }
    return false;
    
}

int Floor::getFloorNumber(){
    return this->floor;
}
