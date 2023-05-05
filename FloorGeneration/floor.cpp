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

    //find character
    char spot;
    for(int y = 0; y < floorData.size(); y++){
        for(int x = 0; x < floorData[y].size(); x++){
            spot = floorData[y][x];
            if(spot == '@'){
                cout <<"player found at " << x << ", " << y << endl;
            }
        }
    }
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