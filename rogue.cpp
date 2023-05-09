#include "./FloorGeneration/floor.cpp"
#include "./Entities/entity.cpp"
#include "./conio.h/conio.h"

using namespace std;

int main() {
    Floor level1;
    Entity entity;
    level1.loadFloor("./Levels/floorTest.txt");
    level1.printFloor();

    char temp;

    temp = getch();

    level1.moveCharacter(temp, entity);
    level1.printFloor();
    return 0;
}
