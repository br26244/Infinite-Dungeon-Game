#include "./GameSystem/gameSystem.cpp"

using namespace std;

int main() {
    srand(time(NULL));
    int i = 0;
    gameSystem rogue;
    rogue.startGame();
    while(rogue.getGameStatus()){
        rogue.getMoveInput();
    }
    return 0;
}
