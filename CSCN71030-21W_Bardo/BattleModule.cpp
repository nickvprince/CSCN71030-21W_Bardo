#include "battle.h"
#include "player.h"
#include "enemy.h"
#include <stdbool.h>
#include <time.h>

int battleMain()
{
	//system("Color 0C");
	srand((unsigned)time(NULL));
	player p1(100, 10, 0, 1, 5, "Bababooy");
	menu(p1);

	return 0;
}

