#include "./FloorGeneration/floor.cpp"

using namespace std;

int main() {
    Floor level1;
    
    level1.loadFloor("./Levels/floorTest.txt");
    level1.printFloor();
    level1.clearFloor();
    level1.loadFloor("./Levels/longFloorTest.txt");
    level1.printFloor();
    level1.clearFloor();
    level1.loadFloor("./Levels/bigFloorTest.txt");
    level1.printFloor();
    level1.clearFloor();

    return 0;
}
