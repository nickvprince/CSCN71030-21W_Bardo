#include <iostream>
#include <time.h>
#include <stdio.h>
#include "entity.h"
using namespace std;

class enemy: public entity
{
private:
public:
	enemy()
	{
		health = 0;
		damage = 0;
		blockval = 0;
		level = 0;
		defense = 0;
		name = " ";
		exp = 300;
		burnCon = 0;
	}
	enemy(int health, int damage, int blockval, int level, int defense, string name)
	{
		this->health = health;
		this->damage = damage;
		this->blockval = blockval;
		this->level = level;
		this->defense = defense;
		this->name = name;
		this->exp = 300;
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
		cout << endl << "The enemy attacks you!" << endl;
		int randDmg;
		randDmg = rand() % BASE_DMG + damage;
		if (entity.blockval != 0)
		{
			randDmg %= (2 + entity.blockval); // reduces the damage that is dealt that turn based on the players protections 
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
	int block(entity& enemy) override
	{
		enemy.blockval += (2 + enemy.level);
		cout << endl << "The enemy blocks and gains " << enemy.blockval << " block!" << endl;
		return enemy.blockval;
	}
	void choice(entity& player, entity& enemy)
	{
		int randChoice;
		cout << "\n****************";
		cout << "\n ENEMY'S TURN \n";
		cout << "****************\n";
		randChoice = rand() % 10 + 1;
		
		if (randChoice >= 5)
		{
			randChoice = 1;
		}
		else if (randChoice >= 2 && randChoice < 5)
		{
			randChoice = 2;
		}
		else if (randChoice == 1)
		{
			randChoice = 3;
		}
		else
		{
			cout << "Enemy can't decide " << randChoice <<endl;
		}
		switch (randChoice)
		{
		case 1:
			cout << "\n*****************************************";
			attack(player, enemy.getDmg());
			cout << "*****************************************\n";
			break;
		case 2:
			cout << "\n*****************************************";
			block(enemy);
			cout << "*****************************************\n";
			break;
		case 3:
			cout << "\n*****************************************";
			heal(enemy);
			cout << "*****************************************\n";
			break;
		default:
			cout << "Please Try again" << endl;
			break;
		}
	}
	void heal(entity& enemy)
	{
		int randHeal;
		randHeal = rand() % 2 + 1;
		int totalheal = 2 + enemy.level * randHeal;
		enemy.health += totalheal;
		cout << endl << enemy.name << " has healed for " << totalheal << endl;
	}
};

enemy randEnemy(entity& player);