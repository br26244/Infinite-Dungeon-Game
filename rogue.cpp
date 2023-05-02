#include "./FloorGeneration/floor.cpp"

using namespace std;

int main() {
    Floor level1;
    
    level1.loadFloor("./Levels/floorTest.txt");
    level1.printFloor();
    return 0;
}
