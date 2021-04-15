#include "battle.h"
#define NUM_ENEMIES 4

enemy randEnemy(entity& player)
{
	list* Enames = getListEnemy();
	int flag = 0;
	Enames->names;

	int	i = rand() % NUM_ENEMIES;
	if (Enames->names[i] != "")
	{
		while (flag != 10)
		{
			enemy* new_enemy = get_Enemy(Enames->names[i], player.level);
			if (new_enemy->failed == GOOD)
			{
				int randLvl = rand() % 3 + 0;
				int randval = rand() % 10 + 0;
				new_enemy->damage = 1 * randLvl * (player.level % 2);
				new_enemy->burnCon = 0;

				return *new_enemy;
			}
			else
			{
				flag++;
			}
		}
	}
}
