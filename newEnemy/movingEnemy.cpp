#include "movingEnemy.h"



char MovingEnemy::getMove(int playerX, int playerY, Enemy& enemy){

    static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> moveRoll(0, 6);


	int distance;
	int dx = enemy.getX() - playerX;
	int dy = enemy.getY() - playerY;
	int adx = abs(dx);
	int ady = abs(dy);
	distance = adx + ady;
	
	//You can change 5 if you want
	if (distance <= 5) {
		//Moving along X axis
		if (adx > ady) {
			if (dx > 0) {
				return 'a'; 
			}
			else {
				return 'd'; 
			}
		}
		else { //Move along Y axis
			if (dy > 0) {
				return 'w';
			}
			else {
				return 's';
			}
		}
	}

	int randomMove = moveRoll(randomEngine);

	switch (randomMove) {
	case 0:
		return 'a';
	case 1:
		return 'w';
	case 2:
		return 's';
	case 3:
		return 'd';
	default:
		return '.';
	}
} 