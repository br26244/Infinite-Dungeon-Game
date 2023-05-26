#include "customization.h"
#include <iostream>

using namespace std;

Customization::Customization(){
    CustomizationModulation modulation;
    this->modulation = modulation;
}

Customization::~Customization(){
    
}

void Customization::showFirstOption(){
    int choice = 0;
    cout << "Hello adventurere!" << endl;
    cout << "Which best describes you?" << endl;
    cout << endl;
    cout << "Growing up my parents were..." << endl;
    cout << "1. bankers" << endl;
    cout << "2. town guards" << endl;
    cout << "3. blacksmiths" << endl;
    cout << "4. clergy" << endl;
    cout << endl;
    while(choice == 0){
        choice = getUserChoice();
    }

    if(choice == 1){
        modulation.increaseGold(1);
    }else if(choice == 2){
        modulation.increaseStr(1);
    }else if(choice == 3){
        modulation.increaseArm(1);
    }else if(choice == 4){
        modulation.increaseHealth(1);
    }
}

void Customization::showSecondOption(){
    int choice = 0;
    cout << "Hello adventurere!" << endl;
    cout << "Which best describes you?" << endl;
    cout << endl;
    cout << "As a teen I..." << endl;
    cout << "1. worked at the market" << endl;
    cout << "2. was a part of the scouts" << endl;
    cout << "3. was an apprentice" << endl;
    cout << "4. served in the church" << endl;
    cout << endl;
    while(choice == 0){
        choice = getUserChoice();
    }

    if(choice == 1){
        modulation.increaseGold(2);
    }else if(choice == 2){
        modulation.increaseStr(2);
    }else if(choice == 3){
        modulation.increaseArm(2);
    }else if(choice == 4){
        modulation.increaseHealth(2);
    }
}

void Customization::showThirdOption(){
    int choice = 0;
    cout << "Hello adventurere!" << endl;
    cout << "Which best describes you?" << endl;
    cout << endl;
    cout << "Before you entered the dungeon, you took..." << endl;
    cout << "1. gold" << endl;
    cout << "2. a dagger" << endl;
    cout << "3. leather armor" << endl;
    cout << "4. health potion" << endl;
    cout << endl;
    while(choice == 0){
        choice = getUserChoice();
    }

    if(choice == 1){
        modulation.increaseGold(3);
    }else if(choice == 2){
        modulation.increaseStr(3);
    }else if(choice == 3){
        modulation.increaseArm(3);
    }else if(choice == 4){
        modulation.increaseHealth(3);
    }
}

int Customization::getUserChoice() {
    int choice = 0;
    
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (choice > 0 && choice < 5) {
            break;
        }
    }
    system("clear");
    return choice;
}

int Customization::getHealth(){
    return modulation.getHealth();
}

int Customization::getStr(){
    return modulation.getStr();
}

int Customization::getGold(){
    return modulation.getGold();
}

int Customization::getArm(){
    return modulation.getArm();
}