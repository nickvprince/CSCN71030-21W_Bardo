#include "BattleModule.h"
#include <stdbool.h>
#include <time.h>

bool battleMain(entity& player)
{
	srand((unsigned)time(NULL));
	menu(player);

	return true;
}

void credits3()
{
	int i = 91;
	printf("  _____                             \n");
	printf(" |_   _|                            \n");
	printf("   | |  ___ ___ _   _  ___  ___     \n");
	printf("   | | / __/ __| | | |/ _ %c/ __|    \n", i);
	printf("  _| |_%c__ %c__ %c |_| |  __/%c__ %c    \n", i, i, i, i, i);
	printf(" |_____|___/___/%c__,_|%c___||___/    \n", i, i);

	printf("\nThe main issues were as follows:\n");
	printf("1. The player would heal when the enemies would attack them. \nThis was due to the damage value being less than the defence stat of the player and the damage going into the negatives.\n\n");
	printf("2. Get weapons had poorly formatted data files which led to cascading issues.\n\n");
	printf("3. Get defence did not increment a variable that was cruicial to its function. \n\n");
	printf("4. Merge errors that led us to take much more time than needed for integration.\n\n");
	printf("5. As seen earlier we had 2219 errors after merging which had to be sorted out but they turned out to be mostly include errors.\n");


	system("cls");

	printf("  _____                           ______ _              _ \n");
	printf(" |_   _|                         |  ____(_)            | |\n");
	printf("   | |  ___ ___ _   _  ___  ___  | |__   ___  _____  __| |\n");
	printf("   | | / __/ __| | | |/ _ %c/ __| |  __| | %c %c/ / _ %c/ _` |\n", i, i, i, i);
	printf("  _| |_%c__ %c__ %c |_| |  __/%c__ %c | |    | |>  <  __/ (_| |\n", i, i, i, i, i);
	printf(" |_____|___/___/%c__,_|%c___||___/ |_|    |_/_/%c_%c___|%c__,_|\n", i, i, i, i, i);

	printf("\nIn the end everything ended up passing.\n\n");
	printf("To fix these we had an excessively 11 and a half hour call re-analyzing algorithms and fixing and merging all that was left.\n\n\n");



}