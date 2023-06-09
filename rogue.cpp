#include "./GameSystem/gameSystem.cpp"

using namespace std;

int main() {
    srand(time(NULL));
    int i = 0;
    gameSystem rogue;
    while(true){
        rogue.startGame();
        while(rogue.getGameStatus()){
            rogue.getMoveInput();
        }
        rogue.death();
    }
    return 0;
}
