#include "battle.h"
#include <iostream>
#include <stdio.h>
using namespace std;

void menu(entity& player)
{
	int i = 0;
	char asd;
	cout << "\n-----------------------------------------";
	cout << "\n Would you like to do a battle? (1 or 0) \n";
	cout << "-----------------------------------------\n";
	scanf_s("%d", &i);
	scanf_s("%c", &asd);
	if (!isdigit(i))
	{
		if (i == 1)
		{
			enemy e1 = randEnemy(player); // get enemy from file
			battle(player, e1);
		} 			else if (i == 0)
		{
			system("cls");
			cout << "Battle canceled " << endl;
		} 			else
		{
			system("cls");
			cout << "Please enter a valid input" << endl;
		}
	} 		else
	{
		system("cls");
		cout << "Please enter a valid input";
		menu(player);
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

	} 	else if (player.health > 0)
	{
		cout << "\n-------------------------";
		cout << "\n You have won the battle! \n";
		cout << "-------------------------\n";

		cout << endl;

		cout << "\n-------------------------";
		cout << "\n You have gained " << enemy.currentexp << "exp " << endl;
		cout << "-------------------------\n";
		player.currentexp += enemy.currentexp;

		cout << endl;

		cout << "\n-------------------------";
		cout << "\n You have gained " << enemy.gold << "gold " << endl;
		cout << "-------------------------\n";
		player.gold += enemy.gold;

		for (int i = 0; i < MAX_ITEMS; i++)
		{
			if (enemy.INV->Weapons[i].name != "")
			{
				for (int b = 0; b < MAX_ITEMS; b++)
				{
					if (player.INV->Weapons[b].name == "" && player.INV->itemsUsed != MAX_ITEMS && player.INV->ItemCount[b] == 0)
					{
						player.INV->Weapons[b] = enemy.INV->Weapons[i];
						player.INV->itemsUsed++;
						player.INV->ItemCount[b]++;
						break;
					}
				}
			}
		}
		for (int i = 0; i < MAX_ITEMS; i++)
		{
			if (enemy.INV->Potions[i].name != "")
			{
				for (int b = 0; b < MAX_ITEMS; b++)
				{
					if (player.INV->Potions[b].name == "" && player.INV->itemsUsed != MAX_ITEMS && player.INV->ItemCount[b] == 0)
					{
						player.INV->Potions[b] = enemy.INV->Potions[i];
						player.INV->itemsUsed++;
						player.INV->ItemCount[b]++;
						break;
					}
				}
			}
		}
		for (int i = 0; i < MAX_ITEMS; i++)
		{
			if (enemy.INV->Shields[i].name != "")
			{
				for (int b = 0; b < MAX_ITEMS; b++)
				{
					if (player.INV->Shields[b].name == "" && player.INV->itemsUsed != MAX_ITEMS && player.INV->ItemCount[b] == 0)
					{
						player.INV->Shields[b] = enemy.INV->Shields[i];
						player.INV->itemsUsed++;
						player.INV->ItemCount[b]++;
						break;
					}
				}
			}
		}
		for (int i = 0; i < MAX_ITEMS; i++)
		{
			if (enemy.INV->Spells[i].name != "")
			{
				for (int b = 0; b < MAX_ITEMS; b++)
				{
					if (player.INV->Spells[b].name == "" && player.INV->itemsUsed != MAX_ITEMS && player.INV->ItemCount[b] == 0)
					{
						player.INV->Spells[b] = enemy.INV->Spells[i];
						player.INV->itemsUsed++;
						player.INV->ItemCount[b]++;
						break;
					}
				}
			}
		}
		for (int i = 0; i < MAX_ITEMS; i++)
		{
			if (enemy.INV->Items[i].name != "")
			{
				for (int b = 0; b < MAX_ITEMS; b++)
				{
					if (enemy.INV->Items[i].name == player.INV->Items[b].name) {
						player.INV->ItemCount[b]++;
						break;
					}
					if (player.INV->Items[b].name == "" && player.INV->itemsUsed != MAX_ITEMS && player.INV->ItemCount[b] == 0)
					{
						player.INV->Items[b] = enemy.INV->Items[i];
						player.INV->itemsUsed++;
						player.INV->ItemCount[b]++;
						break;
					}
				}
			}
		}

		system("pause >nul");


		if (player.currentexp >= player.expmax)
		{
			player.currentexp -= player.expmax;
			player.expmax *= 2;
			levelUp(player);
		} 		else
		{
			player.health = temphealth;
		
		}
	
		return;
	} 	else if (enemy.health > 0)
	{
		cout << "\n----------------------";
		cout << "\n You have died :[ \n";
		cout << "----------------------\n";
		player.health = temphealth;
		
		return;
	} 	else
	{
		cout << "error" << endl;
	}

}
