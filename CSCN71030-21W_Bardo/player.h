#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "entity.h"
using namespace std;

class player : public entity
{
private:
public:
	player()
	{
		health = 0;
		damage = 0;
		blockval = 0;
		level = 0;
		runCon = 0;
		defense = 0;
		name = " ";
		exp = 0;
		expmax = 600;
		burnCon = 0;
	}
	player(int health, int damage, int blockval, int level, int defense, string name)
	{
		this->health = health;
		this->damage = damage;
		this->blockval = blockval;
		this->level = level;
		this->name = name;
		this->defense = defense;
		this->runCon = 0;
		this->exp = 0;
		this->expmax = 600;
		this->burnCon = 0;
	}
	void setDmg(int damage)
	{
		this->damage = damage;
	}
	int getDmg()
	{
		return this->damage;
	}
	int attack(entity& entity, int damage) override
	{
		int randDmg;
		randDmg = rand() % BASE_DMG + damage;
		if (entity.blockval != 0)
		{
			randDmg %= (2 + entity.blockval);
			if (randDmg < 0)
			{
				randDmg = 0;
			}
			entity.blockval = 0; // resets the protections back to zero
		}
		entity.health -= randDmg - entity.defense;
		cout << randDmg << " damage was done to " << entity.name << ", " << entity.name << " has " << entity.health << " hp left." << endl;
		return entity.health;
	}
	int block(entity& player) override
	{
		player.blockval += (2 + player.level);
		return player.blockval;
	}
	void displayEnemy(entity& enemy)
	{
		cout << "\n";
		cout << endl;
		cout << enemy.name << " is level " << enemy.level << endl;
		cout << enemy.name << " has " << enemy.damage << " damage" << endl;
		cout << enemy.name << " has " << enemy.health << " health" << endl;
		cout << enemy.name << " has " << enemy.blockval << " block" << endl;
		cout << enemy.name << " has " << enemy.defense << " defense" << endl;
	}
	void spellmenu(entity& enemy, entity& player)
	{
		char spell = 0;
		char asd;
		cout << endl << "What spell do you wish to use?" << endl;
		cout << "a. Fire " << endl << "b. Ice" << endl << "c. Lightning" << endl;
		scanf_s("%c", &spell, 1);
		scanf_s("%c", &asd);
		if (isalpha(spell) != 0)
		{
			switch (spell)
			{
			case 'a':
				cout << "\n------------------------------------------";
				cout << endl << "You choose to use fire. " << endl;
				cout << "------------------------------------------\n";
				fire(enemy);
				break;
			case 'b':
				cout << "\n------------------------------------------";
				cout << endl << "You choose to use ice. " << endl;
				cout << "------------------------------------------\n";
				ice(enemy, player);
				break;
			case 'c':
				cout << "\n------------------------------------------";
				cout << endl << "You choose to use lightning. " << endl;
				cout << "------------------------------------------\n";
				lightning(enemy, player);
				break;
			}
		}
		else
		{
			system("cls");
			cout << "Please enter a valid input";
			spellmenu(player, enemy);
		}
	}
	int fire(entity& enemy)
	{
		if (enemy.burnCon != 0)
		{
			cout << "\n-------------------------------";
			cout << "\nThe enemy is already burning!\n";
			cout << "-------------------------------\n";
			return enemy.burnCon;
		}
		else
		enemy.burnCon = 3 * (this->level % 2);
		return enemy.burnCon;
	}
	void ice(entity& enemy, entity& player)
	{
		cout << "You freeze the enemy skipping their turn!" << endl;
		cout << "------------------------------------------\n";
		player.choice(enemy, player);
	}
	void lightning(entity& enemy, entity& player)
	{
		cout << "\n------------------------------------------";
		cout << endl << "You shock " << enemy.name << " dealing " << 3 * player.level << " damage with a chance to stun them!" << endl;
		cout << "------------------------------------------\n";
		int randval;
		randval = rand() % 2 + 1;
		enemy.health -= 3 * player.level;
		
		if (randval == 1)
		{
			cout << "\n------------------------------------------";
			cout << endl << enemy.name << " is stunned! \n";
			cout << "------------------------------------------\n";
			player.choice(enemy, player);
		}
	}
	int run()
	{
		this->runCon = 1;
		return runCon;
	}
	void choice(entity& player, entity& enemy)
	{
		int input = 0; 
		char asd;
		cout << "\n--------------";
		cout << "\n YOUR TURN \n";
		cout << "--------------\n";
		cout << "1. Attack " << endl << "2. Block" << endl << "3. Run" << endl << "4. Heal" << endl << "5. Use Spell" << endl << endl;
		scanf_s("%d", &input);
		scanf_s("%c", &asd);
		if (!isdigit(input))
		{
			if (input > 6)
			{
				system("cls");
				cout << "Please enter a valid input";
				choice(player, enemy);
			}
			else
			{
				displayEnemy(enemy);
				switch (input)
				{
				case 1:
					cout << "\n-------------------------------------------";
					cout << endl << "You choose to attack the enemy. " << endl;
					attack(enemy, player.damage);
					cout << "-------------------------------------------\n";
					break;
				case 2:
					cout << "\n-------------------------------------------";
					cout << endl << "You choose to block the enemy. " << endl;
					block(player);
					cout << "-------------------------------------------\n";
					break;
				case 3:
					cout << "\n-------------------------------------------";
					cout << endl << "You choose to run from the enemy. " << endl;
					run();
					cout << "-------------------------------------------\n";
					break;
				case 4:
					cout << "\n-------------------------------------------";
					cout << endl << "You choose to heal. " << endl;
					heal(player);
					cout << "-------------------------------------------\n";
					break;
				case 5:
					cout << "\n-------------------------------------------";
					spellmenu(enemy, player);
					break;
				default:
					cout << "Please Try again" << endl;
					break;
				}
			}
		}
		else
		{
			cout << "Please enter a valid input";
			choice(player, enemy);
		}
	}
	void heal(entity& player)
	{
		int randHeal;
		randHeal = rand() % 3 + 1;
		int totalheal = 5 + player.level * randHeal;
		cout << player.name << " has healed for " << totalheal << endl;
		cout << player.name << " now has " << player.health + totalheal << " health" << endl;
	}
};

void levelUp(entity& player);
