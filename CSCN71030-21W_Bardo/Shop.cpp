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

#include "WeaponsDealer.h"
#include "DefenceDealer.h"
#include "PotionDealer.h"
#include "ItemDealer.h"
#include "Shop.h"


bool shopMain(entity* character) {

	Dealer* weaponDealer = new WeaponDealer;
	Dealer* defenceDealer = new DefenceDealer;
	//Dealer* potionDealer = new PotionDealer;
	Dealer* itemDealer = new ItemDealer;

	int choice = 0;
	int optionChoice = 0;

	do {
		system("cls");
		printShops();
		cin >> choice;
		checkUserInput();
		switch (choice) {
		case 1:
				system("cls");
				weaponDealer->printDealerHeader(character);
				weaponDealer->printDealerOptions();
				weaponDealer->getOptionChoice(weaponDealer, character);
			break;
		case 2:
			system("cls");
			defenceDealer->printDealerHeader(character);
			defenceDealer->printDealerOptions();
			defenceDealer->getOptionChoice(defenceDealer, character);
			break;
		case 3:
			/*system("cls");
			potionDealer->printDealerHeader(character);
			potionDealer->printDealerOptions();
			potionDealer->getOptionChoice(potionDealer, character);*/
			break;
		case 4:
			system("cls");
			itemDealer->printDealerHeader(character);
			itemDealer->printDealerOptions();
			itemDealer->getOptionChoice(itemDealer, character);
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
	cout << "5. Exit Shop\n";
	cout << "Enter : ";
}

