/*
* File Name : Objects.h | Each object needs its own .h file with setters and getters
*
* Programmer : Danny Smith
* Class : Team Based Software Development CSCN71030-21W-SEC1-PROJECT 2
* Date : February 6, 2021
* Teacher : Dr. Elliott Coleshill
* Team : Dominic Pham, Thomas Horvath, Nicholas Prince, Ali Syed
*
* Description :
*
*
* Version : 1.0
*
*
* History :
*	Object classes named : weapon, defence, potion, spell, inventory, user, enemy
*	base weapon variables defined, class item created
*/
#define MAX_MATERIALS 10 // max number of crafting/Bartering materials for an item
#define MAX_ITEMS 20  // max number of items in a players inventory
#define MAX_NUM_FILES 15 // max files that can be found in a directory
#define BASE_DMG 5 // base damage of characters and enemies
using namespace std;
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
typedef enum ErrorType { CHK_FAIL, EXISTS_FAIL, COMMON_FAIL, GOOD }ErrorType; // used to identify file errors
class item {
public:
	string name;
	int value = 0;
	string BarterItems[MAX_MATERIALS];
	int BarterItemsNum[MAX_MATERIALS];
	ErrorType failed = GOOD;
};

class weapon {
public:
	string name;
	int damage = 0, value = 0, level = 0;
	string craftingItems[MAX_MATERIALS]; // name of items required for crafting
	string BarterItems[MAX_MATERIALS];
	int BarterItemsNum[MAX_MATERIALS];
	int craftingItemsNum[MAX_MATERIALS]; // number of those items required
	ErrorType failed = GOOD;

};

class defence {
public:
	string name;
	int blockChance = 0, Defence = 0, value = 0, level = 0;
	string craftingItems[MAX_MATERIALS];
	int craftingItemsNum[MAX_MATERIALS];
	string BarterItems[MAX_MATERIALS];
	int BarterItemsNum[MAX_MATERIALS];
	ErrorType failed = GOOD;
};

class potion {
public:
	ErrorType failed = GOOD;
	int Power = 0;
	string craftingItems[MAX_MATERIALS];
	int craftingItemsNum[MAX_MATERIALS];
	string BarterItems[MAX_MATERIALS];
	int BarterItemsNum[MAX_MATERIALS];
	string name;
	int value = 0;
};

class spell {
public:
	string name;
};

class inventory {
public:
	ErrorType failed = GOOD;
	int itemsUsed = 0; // how many items in inventory
	int ItemCount[MAX_ITEMS]; // number of items carried lines up with each array item at index
	item Items[MAX_ITEMS];
	weapon Weapons[MAX_ITEMS];
	defence Shields[MAX_ITEMS];
	potion Potions[MAX_ITEMS];
	spell Spells[MAX_ITEMS];
	
};

class entity {
public:
	string name;
	string race;
	weapon Weapon;
	defence Shield;
	inventory* INV; // items an enemy could drop in combat
	ErrorType failed = GOOD;
	int defence = 0, health = 0, level = 1, damage = 0, currentexp = 0, gold = 0;
	int skillpoints = 0;  // unspent skill points
	int Skills[3]; // Health, Defence, attack
	int blockval = 0, runCon = 0, expmax = 600, burnCon = 0;

	virtual int attack(entity& entity, int damage) = 0;
	virtual void choice(entity& player, entity& enemy) = 0;
	virtual int getDmg() = 0;
	virtual int block(entity& player) = 0;

};
class user :public entity {
public:

	user()
	{
		health = 0;
		damage = 0;
		blockval = 0;
		level = 0;
		runCon = 0;
		defence = 0;
		name = " ";
		currentexp = 0;
		expmax = 600;
		burnCon = 0;
	}
	user(int health, int damage, int blockval, int level, int defence, string name)
	{
		this->health = health;
		this->damage = damage;
		this->blockval = blockval;
		this->level = level;
		this->name = name;
		this->defence = defence;
		this->runCon = 0;
		this->currentexp = 0;
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
		int randDmg = 0;
		randDmg = rand() % BASE_DMG + damage + entity.Weapon.damage;
		if (entity.blockval != 0)
		{
			randDmg %= (2 + entity.blockval);
			if (randDmg < 0)
			{
				randDmg = 0;
			}
			entity.blockval = 0; // resets the protections back to zero
		}
		if (entity.defence <= randDmg)
		{
			entity.health -= randDmg - entity.defence;
		}
		else
		{
			entity.health--;
		}
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
		cout << enemy.name << " has " << enemy.defence << " defence" << endl;
	}
	void spellmenu(entity& enemy, entity& player)
	{
		int flag = 0;
		for (int i = 0; i < MAX_ITEMS; i++)
		{
			if (enemy.INV->Items[i].name == "Scroll")
			{
				player.INV->ItemCount[i]--;
				if(player.INV->ItemCount[i] == 0) {
					player.INV->Items[i].name = "";
				}
				flag++;
			}
			if (flag == 0) {
				cout << "You do not have a scroll...";
				getc(stdin);
				return;
			}
		}
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
		} else
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
		} else
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
		cout << "1. Attack " << endl << "2. Block" << endl << "3. Run" << endl << "4. Health Potion" << endl << "5. Use Spell" << endl << endl;
		scanf_s("%d", &input);
		scanf_s("%c", &asd);
		if (!isdigit(input))
		{
			if (input > 6)
			{
				system("cls");
				cout << "Please enter a valid input";
				choice(player, enemy);
			} else
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
		} else
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

class enemy :public entity {
public:
	enemy()
	{
		health = 0;
		damage = 0;
		blockval = 0;
		level = 0;
		defence = 0;
		name = " ";
		currentexp = 300;
		burnCon = 0;
	}
	enemy(int health, int damage, int blockval, int level, int defence, string name)
	{
		this->health = health;
		this->damage = damage;
		this->blockval = blockval;
		this->level = level;
		this->defence = defence;
		this->name = name;
		this->currentexp = 300;
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
		randDmg = rand() % BASE_DMG + damage + entity.Weapon.damage;
		if (entity.blockval != 0)
		{
			randDmg %= (2 + entity.blockval); // reduces the damage that is dealt that turn based on the players protections 
			if (randDmg < 0)
			{
				randDmg = 0;
			}
			entity.blockval = 0; // resets the protections back to zero
		}
		if (entity.defence <= randDmg)
		{
			entity.health -= randDmg - entity.defence;
		}
		else
		{
			entity.health--;
		}
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
		cout << "\n----------------";
		cout << "\n ENEMY'S TURN \n";
		cout << "----------------\n";
		randChoice = rand() % 10 + 1;

		if (randChoice >= 5)
		{
			randChoice = 1;
		} else if (randChoice >= 2 && randChoice < 5)
		{
			randChoice = 2;
		} else if (randChoice == 1)
		{
			randChoice = 3;
		} else
		{
			cout << "Enemy can't decide " << randChoice << endl;
		}
		switch (randChoice)
		{
		case 1:
			cout << "\n------------------------------------------";
			attack(player, enemy.getDmg());
			cout << "------------------------------------------\n";
			break;
		case 2:
			cout << "\n------------------------------------------";
			block(enemy);
			cout << "------------------------------------------\n";
			break;
		case 3:
			cout << "\n------------------------------------------";
			heal(enemy);
			cout << "------------------------------------------\n";
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

class list {
public:
	string names[MAX_NUM_FILES];
};