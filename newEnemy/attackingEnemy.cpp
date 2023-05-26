#include "attackingEnemy.h"


int AttackingEnemy::attack(Enemy& enemy) {
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackRoll(0, enemy.getAttack());
	return attackRoll(randomEngine);
}

void AttackingEnemy::takeDamage(int attack,Enemy& enemy) {
	attack -= enemy.getDefense();
	//Cjecl of the attack does damage
	if (attack > 0) {
		enemy.setHealth(enemy.getHealth() - attack);
		//Check if he died
		if (enemy.getHealth() <= 0) {
			cout << "Enemy is dead" << endl;

		}

	}

} 

