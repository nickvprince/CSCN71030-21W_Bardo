#include "battle.h"

enemy randEnemy(entity& player)
{
	enemy new_enemy;
	int randLvl = rand() % 3 + 0;
	int randval = rand() % 10 + 0;
	new_enemy.level = randLvl * (player.level % 2);
	new_enemy.damage = 0 * randLvl * (player.level % 2);
	new_enemy.defence = 3 * randLvl * (player.level % 2);
	new_enemy.health = 50 + randLvl * 2 * (player.level % 2);
	new_enemy.name = "randEnemy";
	new_enemy.currentexp = 300;
	new_enemy.burnCon = 0;
	return new_enemy;
}
