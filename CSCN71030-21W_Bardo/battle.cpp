#include "battle.h"
#include "player.h"
#include "enemy.h"
#include "entity.h"
#include <iostream>
#include <stdio.h>

using namespace std;

void menu(entity& player)
{
	int i = 0;
	char asd;
	while (true)
	{
			cout << "\n-----------------------------------------";
			cout << "\n Would you like to do a battle? (1 or 0) \n";
			cout << "-----------------------------------------\n";
			scanf_s("%d", &i);
			scanf_s("%c", &asd);
			if (!isdigit(i))
			{
				if (i == 1)
				{
					enemy e1 = randEnemy(player);
					battle(player, e1);
				}
				else if (i == 0)
				{
					system("cls");
					cout << "Battle canceled " << endl;
				}
				else
				{
					system("cls");
					cout << "Please enter a valid input" << endl;
				}
			}
			else
			{
				system("cls");
				cout << "Please enter a valid input";
				menu(player);
			}
	}
}

void battle(entity& player, entity& enemy)
{
	int temphealth = player.health;
	cout << player.name << " challenges " << enemy.name << endl;
	while ((player.health > 0) && (enemy.health > 0) && (player.runCon != 1))
	{
		player.choice(player, enemy);

		enemy.choice(player, enemy);
		if (enemy.burnCon >= 1)
		{
			cout << "\n------------------------------------------------------------------------------";
			cout << "\nThe enemy is burned at the start of their turn! " << enemy.name << " has " << enemy.health << " left." << endl;
			cout << "------------------------------------------------------------------------------\n";
			enemy.health -= 5 * (player.level % 2);
			enemy.burnCon -= 1;
		}
	}
	if (player.runCon != 0)
	{
		cout << "\n-------------------------";
		cout << "\n You chose to run away \n";
		cout << "-------------------------\n";
		player.runCon = 0;
		return;
	}
	else if (player.health > 0)
	{
		cout << "\n-------------------------";
		cout << "\n You have won the battle! \n";
		cout << "-------------------------\n";

		cout << endl;

		cout << "\n-------------------------";
		cout << "\n You have gained " << enemy.exp << "exp " << endl;
		cout << "-------------------------\n";
		player.exp += enemy.exp;

		if (player.exp >= player.expmax)
		{
			player.exp -= player.expmax;
			player.expmax *= 2;
			levelUp(player);
		}
		else
		{
			player.health = temphealth;
		}
		return;
	}
	else if (enemy.health > 0)
	{
		cout << "\n----------------------";
		cout << "\n You have died :[ \n";
		cout << "----------------------\n";
		player.health = temphealth;
		return;
	}
	else
	{
		cout << "error" << endl;
	}

}
