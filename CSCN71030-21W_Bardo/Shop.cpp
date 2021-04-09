/*
* File Name: Shop.cpp
*
* Programmer: Nicholas Prince
* Class: Team Based Software Development CSCN71030-21W-SEC1-PROJECT 2
* Date: March 22, 2021
* Teacher: Dr. Elliott Coleshill
* Team: Dominic Pham, Thomas Horvath, Danny Smith, Ali Syed
*
* Module: Economy
*
*/

#include "Shop.h"


bool shopMain(user* character) {

	Dealer* weaponDealer = new WeaponDealer;
	/*Dealer* defenceDealer = new DefenceDealer;
	Dealer* potionDealer = new PotionDealer;
	Dealer* itemDealer = new ItemDealer;*/

	int choice = 0;
	int optionChoice = 0;

	do {
		system("cls");
		printShops();
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			weaponDealer->printDealerHeader(character);
			weaponDealer->printDealerOptions();
			weaponDealer->getOptionChoice(weaponDealer, character);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			return true;
			break;
		default:
			break;

		}

	} while (true);
	
}
void printShops() {
	cout << "Welcome to the Market please choose a dealer: \n";
	cout << "-------------------------------------------------------\n";
	cout << endl;
	cout << "1. Hari\n"; // Weapons
	cout << "2. Ilyon\n"; // Defence
	cout << "3. Daemon\n"; // Potions
	cout << "4. Sterling\n"; // Items
	cout << "5. Exit\n";
	cout << "Enter : ";
}

