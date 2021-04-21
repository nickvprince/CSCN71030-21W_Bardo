
/*
* File Name : Main.cpp
*
* Programmer : Ali Syed
* Class : Team Based Software Development CSCN71030-21W-SEC1-PROJECT 2
* Date : April 3, 2021
* Teacher : Dr. Elliott Coleshill
* Team : Dominic Pham, Thomas Horvath, Nicholas, Prince, Danny Smith

*/


#include <iostream>
#include <direct.h>
#include <algorithm>
#include <string>
#include "Character.h"


using namespace std;

entity* selectStarterShield(entity* Player);
entity* selectStarterWeapon(entity* Player);
entity* manualSetStats(entity* Player);
entity* setStats(entity* Player);
void setRace(entity* Player);
bool defaultStat(entity* Player);
bool defaultConfirmation();
void humanStats();
void elfStats();
void dwarfStats();
entity* startIO(entity* Player);
bool valueCheck(const string& value);

int startMenu() {
STARTMENU:
	system("cls");
	char menuInput;
	cout << "Welcome" << endl << "0.New Game" << endl << "1.Load Game" << endl;
	cout << "Enter: ";
	cin >> menuInput;
	if (menuInput == '0') {
		return 0;
	} 	else if (menuInput == '1') {
		return 1;
	} 	else if (((menuInput != '0') && (menuInput != '1')) || (isdigit(menuInput) == 0))
	{
		cout << "Invalid Entry. Try Again" << endl;
		//startMenu();
		goto STARTMENU;
	}

}

entity* newGame() {
	system("cls");
	string characterName;

	entity* Player = new user;

	cout << "Please enter character name: ";
	cin >> characterName;
	transform(characterName.begin(), characterName.end(), characterName.begin(), ::toupper);
	Player->name = characterName;
	setRace(Player);
	Player->INV = get_Inventory("entity");
	/*Player->Weapon = get_Weapon("WoodAxe");
	Player->Shield = get_Defence("WoodShield");
	Player->defence = 2 + Player->Shield.Defence;
	Player->damage = 2 + Player->Weapon.damage;
	Player->health = 250;*/
	Player = setStats(Player);
	Player->level = 1;
	Player->gold = 25;
	Player->damage += 100000; // For demo
	Player->skillpoints = 10;
	Save(Player);
	return Player;

}

void setRace(entity* Player) {
CHARACTERRACE:
	char characterRace;
	system("cls");
	cout << "Enter the corresponding number to pick a race" << endl;
	cout << "1.HUMAN" << endl;
	cout << "2.ELF" << endl;
	cout << "3.DWARF" << endl;
	cin >> characterRace;
	//transform(characterRace.begin(), characterRace.end(), characterRace.begin(), ::toupper);
	if (((characterRace != '1') && (characterRace != '2') && (characterRace != '3')) || (isdigit(characterRace) == 0))
	{
		cout << "Invalid Entry. Try Again" << endl;
		//setRace(Player);
		goto CHARACTERRACE;
	}
	if (characterRace == '1') {
		humanStats();
		if (defaultConfirmation() == true)
		{
			Player->race = "HUMAN";
		} 		else {
			//setRace(Player);
			goto CHARACTERRACE;
		}
	}
	if (characterRace == '2')
	{
		elfStats();
		if (defaultConfirmation() == true)
		{
			Player->race = "ELF";
		} 		else {
			//setRace(Player);
			goto CHARACTERRACE;
		}
	}
	if (characterRace == '3') {
		dwarfStats();
		if (defaultConfirmation() == true)
		{
			Player->race = "DWARF";
		} 		else {
			//setRace(Player);
			goto CHARACTERRACE;
		}
	}

}

entity* setStats(entity* Player) {
	char choice;
SETSTATS:
	cout << "To play with default character status enter 0, to build personalized character enter 1: ";
	cin >> choice;
	if (((choice != '0') && (choice != '1')) || (isdigit(choice) == 0)) {
		cout << "Invalid Entry. Try Again" << endl;
		//setStats(Player);
		goto SETSTATS;
	}
	if (choice == '0')
	{
		
		/*bool statCheck = defaultStat(Player);
		if (statCheck == true) {*/
		if (Player->race == "HUMAN") {
			Player->health = 250;
			Player->Weapon = get_Weapon("WoodSword");
			Player->Shield = get_Defence("WoodShield");
			Player->defence = 3 + Player->Shield.Defence;
			Player->damage = 2 + Player->Weapon.damage;

		}
		if (Player->race == "ELF") {
			Player->health = 300;
			Player->Weapon = get_Weapon("WoodBow");
			Player->Shield = get_Defence("WoodShield");
			Player->defence = 3 + Player->Shield.Defence;
			Player->damage = 3 + Player->Weapon.damage;

		}
		if (Player->race == "DWARF") {
			Player->health = 275;
			Player->Weapon = get_Weapon("WoodAxe");
			Player->Shield = get_Defence("WoodArmour");
			Player->defence = 6 + Player->Shield.Defence;
			Player->damage = 4 + Player->Weapon.damage;

		}
		/*}
		else {
			setStats(Player);
		}*/
	}
	if (choice == '1') {
		manualSetStats(Player);
	}
	return Player;
}

entity* manualSetStats(entity* Player) {
	char option;
	int beginnerAttPoints = 10;
	char health[5];
	char attack[5];
	char defence[5];
	int healthpoints = 0;
	int attpoints = 0;
	int defpoints = 0;
	int hp = 0, ap = 0, dp = 0;

	if (Player->race == "HUMAN") {
		Player->health = 250;
		Player->defence = 0;
		Player->damage = 0;

	}
	if (Player->race == "ELF") {
		Player->health = 300;
		Player->defence = 0;
		Player->damage = 0;

	}
	if (Player->race == "DWARF") {
		Player->health = 275;
		Player->defence = 0;
		Player->damage = 0;

	}
	do {

		if (beginnerAttPoints > 0)
		{

		defaultreturn:
			system("cls");
			cout << endl << "Character Builder" << endl;
			cout << "Current Attribute Points: " << beginnerAttPoints << endl;
			cout << "Please select any of the following to distribute beginner attribute points" << endl;
			if ((hp > 0) || (ap > 0) || (dp > 0))
			{
				cout << "1. Health" << "      Allocated Points: " << hp << endl;
				cout << "2. Attack" << "      Allocated Points: " << ap << endl;
				cout << "3. Defence" << "     Allocated Points: " << dp << endl;
			} 			else { cout << "1. Health" << endl << "2. Attack" << endl << "3. Defence" << endl; }
			cin >> option;
			if (((option != '1') && (option != '2') && (option != '3')) || (isdigit(option) == 0)) {
				cout << "Invalid Entry. Try Again" << endl;
				goto defaultreturn;
			}
			switch (option)
			{
			case '1':

				cout << "For each attribute point, 10 health will increase" << endl;
				cout << "Enter the number of attribute points to use: ";
				cin >> health;
				healthpoints = atoi(health);

				if ((valueCheck(health) == false) || (healthpoints > beginnerAttPoints))
				{
					cout << "Invalid Entry. Try Again" << endl;
					goto defaultreturn;
				} 				else if (beginnerAttPoints >= healthpoints)
				{
					int healthtemp = healthpoints * 10;
					Player->health = Player->health + healthtemp;
					beginnerAttPoints = beginnerAttPoints - healthpoints;
					hp = hp + healthpoints;

				}

				break;
			case '2':

				cout << "Enter the number of attribute points to use: ";
				cin >> attack;
				attpoints = atoi(attack);

				if ((valueCheck(attack) == false) || (attpoints > beginnerAttPoints))
				{
					cout << "Invalid Entry. Try Again" << endl;
					goto defaultreturn;
				} 				else if (beginnerAttPoints >= attpoints)
				{
					Player->damage = Player->damage + attpoints;
					beginnerAttPoints = beginnerAttPoints - attpoints;
					ap = ap + attpoints;
				}

				break;
			case '3':

				cout << "Enter the number of attribute points to use: ";
				cin >> defence;
				defpoints = atoi(defence);

				if ((valueCheck(defence) == false) || (defpoints > beginnerAttPoints))
				{
					cout << "Invalid Entry. Try Again" << endl;
					goto defaultreturn;
				} 				else if (beginnerAttPoints >= defpoints)
				{
					Player->defence = Player->defence + defpoints;
					beginnerAttPoints = beginnerAttPoints - defpoints;
					dp = dp + defpoints;
				}

				break;
			default:
				cout << "Invalid Entry. Try Again" << endl;
				goto defaultreturn;
			}
		}
	} while (beginnerAttPoints != 0);
	system("cls");
	cout << "1. Health" << "      Allocated Points: " << hp << endl;
	cout << "2. Attack" << "      Allocated Points: " << ap << endl;
	cout << "3. Defence" << "     Allocated Points: " << dp << endl;

	if (defaultConfirmation() == false) {
		beginnerAttPoints = 10;
		hp = 0;
		ap = 0;
		dp = 0;
		goto defaultreturn;
	}
WEAPON:
	Player = selectStarterWeapon(Player);
	if (defaultConfirmation() == false) {
		goto WEAPON;
	}
SHIELD:
	Player = selectStarterShield(Player);
	if (defaultConfirmation() == false) {
		goto SHIELD;
	}
	Player->level = 1;
	Player->gold = 25;
	return Player;

}

void printStats(entity* Player) {

	cout << "Character Name: " << Player->name << endl;
	cout << "Weapon: " << Player->Weapon.name << endl;
	//cout << "Race: " << Player->race << endl;
	//cout << "Attack: " << Player->damage << endl;
	cout << "Defence: " << Player->defence << endl;
	cout << "Health: " << Player->health << endl;
	cout << "Level: " << Player->level << endl;
	cout << "Current Experience: " << Player->currentexp << endl;
	cout << "Level Experience: " << Player->expmax << endl;
	cout << "Gold: " << Player->gold << endl;
	cout << "Shield: " << Player->Shield.name << endl;
	cout << endl;


}

entity* selectStarterWeapon(entity* Player) {
	char starterWeapon;
STARTERWEAPON:
	cout << endl << "Please select a starter weapon from the list of available weapons" << endl;
	cout << "1. Wood Axe" << endl << "2. Wood Bow" << endl << "3. Wood Mace" << endl << "4. Wood Sword" << endl;
	cin >> starterWeapon;

	if (((starterWeapon != '1') && (starterWeapon != '2') && (starterWeapon != '3') && (starterWeapon != '4')) || (isdigit(starterWeapon) == 0)) {
		cout << "Invalid Selection. Try Again" << endl;
		//return selectStarterWeapon(Player);
		goto STARTERWEAPON;
	}
	if (starterWeapon == '1') {
		Player->Weapon = get_Weapon("WoodAxe");
		Player->damage = Player->damage + Player->Weapon.damage;
	}
	if (starterWeapon == '2') {
		Player->Weapon = get_Weapon("WoodBow");
		Player->damage = Player->damage + Player->Weapon.damage;
	}
	if (starterWeapon == '3') {
		Player->Weapon = get_Weapon("WoodMace");
		Player->damage = Player->damage + Player->Weapon.damage;
	}
	if (starterWeapon == '4') {
		Player->Weapon = get_Weapon("WoodSword");
		Player->damage = Player->damage + Player->Weapon.damage;
	}
	return Player;
}

entity* selectStarterShield(entity* Player) {
	char starterShield;
STARTERSHIELD:
	cout << endl << "Please select a starter shield from the list of available shields" << endl;
	cout << "1. Wood Armour" << endl << "2. Wood Shield" << endl;
	cin >> starterShield;

	if (((starterShield != '1') && (starterShield != '2')) || (isdigit(starterShield) == 0)) {

		cout << "Invalid Selection. Try Again" << endl;
		//return selectStarterShield(Player);
		goto STARTERSHIELD;
	}
	if (starterShield == '1') {
		Player->Shield = get_Defence("WoodArmour");
		Player->defence = Player->defence + Player->Shield.Defence;
	}
	if (starterShield == '2') {
		Player->Shield = get_Defence("WoodShield");
		Player->defence = Player->defence + Player->Shield.Defence;
	}
	return Player;
}

bool loadScreen(entity* Player) {
	system("cls");
	if (Player->name == "")
	{
		cout << "No save file exists" << endl;
		if (defaultConfirmation() == true)
		{
			return false;
		} 		else {
			exit(0);
		}
	} 	else {
	LOAD:
		char load;
		cout << "Character: " << Player->name << " Level: " << Player->level << endl;
		cout << "Enter 0 to load game " << endl;
		cout << "Enter 1 to start new game" << endl;
		cin >> load;
		if (load == '1')
		{
			return false;
		}
		if ((load != '0') || (isdigit(load) == 0))
		{

			cout << "Invalid Entry. Try Again" << endl;
			//loadScreen(Player);
			goto LOAD;
		} 		else {
			return true;
		}
	}

}

void humanStats() {
	cout << "HUMAN DEFAULT STATUS_______________" << endl;
	cout << "Health: 250" << endl;
	cout << "Weapon: Wood Sword" << endl;
	cout << "Shield: Wood Shield" << endl;
	cout << "Defence: 6" << endl;
	cout << "Attack: 76" << endl;
}

void elfStats() {
	cout << "ELF DEFAULT STATUS_______________" << endl;
	cout << "Health: 300" << endl;
	cout << "Weapon: Wood Bow" << endl;
	cout << "Shield: Wood Shield" << endl;
	cout << "Defence: 6" << endl;
	cout << "Attack: 77" << endl;
}

void dwarfStats() {
	cout << "DWARF DEFAULT STATUS_______________" << endl;
	cout << "Health: 275" << endl;
	cout << "Weapon: Wood Axe" << endl;
	cout << "Shield: Wood Armour" << endl;
	cout << "Defence: 12" << endl;
	cout << "Attack: 78" << endl;
}

bool defaultStat(entity* Player)
{
	if (Player->race == "HUMAN") {
		cout << "HUMAN_______________" << endl;
		cout << "Health: 250" << endl;
		cout << "Weapon: Wood Sword" << endl;
		cout << "Shield: Wood Shield" << endl;
		cout << "Defence: 6" << endl;
		cout << "Attack: 76" << endl;


	}
	if (Player->race == "ELF") {
		cout << "ELF_______________" << endl;
		cout << "Health: 300" << endl;
		cout << "Weapon: Wood Bow" << endl;
		cout << "Shield: Wood Shield" << endl;
		cout << "Defence: 6" << endl;
		cout << "Attack: 77" << endl;

	}
	if (Player->race == "DWARF") {
		cout << "DWARF_______________" << endl;
		cout << "Health: 275" << endl;
		cout << "Weapon: Wood Axe" << endl;
		cout << "Shield: Wood Armour" << endl;
		cout << "Defence: 12" << endl;
		cout << "Attack: 78" << endl;


	}
	if (defaultConfirmation() == true)
	{
		return true;
	} 	else
	{
		return false;
	}

}

bool defaultConfirmation() {
	string confirm;
CONFIRM:
	cout << "Would you like to continue: YES/NO" << endl;
	cin >> confirm;
	transform(confirm.begin(), confirm.end(), confirm.begin(), ::toupper);
	if (confirm == "YES") {
		return true;
	} 	else if (confirm == "NO") {
		return false;
	} 	else if ((confirm != "YES") && (confirm != "NO"))
	{
		cout << "Invalid Input. Try Again" << endl;
		goto CONFIRM;
		//defaultConfirmation();
	}
}

entity* startIO(entity* Player) {
	int checkStart = startMenu();
	if (checkStart == 0)
	{
		Player = newGame();

	} 	else if (checkStart == 1)
	{
		Player = get_User("USER");
		bool checkLoad = loadScreen(Player);
		if (checkLoad == false)
		{
			Player = newGame();

		}

	}
	return Player;
}

bool valueCheck(const string& value)
{
	for (char const& charvalue : value)
	{
		if (isdigit(charvalue) == 0)
		{
			return false;
		}
	}
	return true;
}


