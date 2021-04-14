#include "BattleModule.h"
#include <stdbool.h>
#include <time.h>

bool battleMain(entity& player)
{
	srand((unsigned)time(NULL));
	menu(player);

	return true;
}

