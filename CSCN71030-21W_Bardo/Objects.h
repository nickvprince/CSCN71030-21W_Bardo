/*
* File Name : Objects.h | Each object needs its own .h file with setters and getters
*
* Programmer : Danny Smith
* Class : Team Based Software Development CSCN71030-21W-SEC1-PROJECT 2
* Date : February 6, 2021
* Teacher : Dr. Elliot Coleshill
* Team : Dominic Pham, Thomas Horvath, Nicholas, Prince, Ali Syed
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
#define MAX_MATERIALS 10
#define MAX_ITEMS 20 
using namespace std;
#include <string>
typedef enum ErrorType { CHK_FAIL, EXISTS_FAIL, COMMON_FAIL, GOOD }ErrorType; // used to identify file errors
class item {

public:
	string name;
	int value = 0;
	ErrorType failed = GOOD;
};

class weapon {
public:
	string name;
	int damage = 0, value = 0, level = 0;
	string craftingItems[MAX_MATERIALS]; // name of items required for crafting
	int craftingItemsNum[MAX_MATERIALS]; // number of those items required
	ErrorType failed = GOOD;

};

class defence {
public:
	string name;
	int blockChance = 0, Defence = 0, value = 0, level = 0;
	string craftingItems[MAX_MATERIALS];
	int craftingItemsNum[MAX_MATERIALS];
	ErrorType failed = GOOD;
};

class potion {
public:
};

class spell {
public:
};

class inventory {
public:
	ErrorType failed = GOOD;
	int itemsUsed = 0; // how many items in inventory
	item Items[MAX_ITEMS];
	weapon Weapons[MAX_ITEMS];
	defence Shields[MAX_ITEMS];
	potion Potions[MAX_ITEMS];
	spell Spells[MAX_ITEMS];
	int ItemCount[MAX_ITEMS]; // number of items carried lines up with each array item at index
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
};
class user:public entity {
public:

	int lvlexp = 600;

};

class enemy:public entity {
public:

	
	int GetDefence() {

	}
	int GetArmour() {

	}
	int GetHealth() {

	}
	int GetLevel() {

	}
	int GetWeapon() {

	}

};

