#include "./FloorGeneration/floor.cpp"
#include "./Entities/entity.cpp"

using namespace std;

int main() {
    Floor level1;
    Entity entity;
    level1.loadFloor("./Levels/floorTest.txt");
    level1.printFloor();

    char temp;

    cin >> temp;

    level1.moveCharacter(temp, entity);
    level1.printFloor();
    return 0;
}
