#include "customization.h"
#include <iostream>

using namespace std;

Customization::Customization(){
    health = 0;
    gold = 0;
    arm = 0;
    str = 0;

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
        gold += 1;
    }else if(choice == 2){
        str += 1;
    }else if(choice == 3){
        arm += 1;
    }else if(choice == 4){
        health += 1;
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
        gold += 2;
    }else if(choice == 2){
        str += 2;
    }else if(choice == 3){
        arm += 2;
    }else if(choice == 4){
        health += 2;
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
        gold += 3;
    }else if(choice == 2){
        str += 3;
    }else if(choice == 3){
        arm += 3;
    }else if(choice == 4){
        health += 3;
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
    return this->health;
}

int Customization::getStr(){
    return this->str;
}

int Customization::getGold(){
    return this->gold;
}

int Customization::getArm(){
    return this->arm;
}