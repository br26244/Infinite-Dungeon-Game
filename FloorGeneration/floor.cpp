#include "floor.h"
#include <fstream>
#include <iostream>

Floor::Floor(){

}

void Floor::loadFloor(string file){
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

void Floor::printFloor(){
    for(int i = 0; i < floorData.size(); i++){
        cout << floorData[i] << endl;
    }

}