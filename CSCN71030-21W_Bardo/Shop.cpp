/*
* File Name: Shop.cpp
*
* Programmer: Nicholas Prince
* Class: Team Based Software Development CSCN71030-21W-SEC1-PROJECT 2
* Date: March 22, 2021
* Teacher: Dr. Elliot Coleshill
* Team: Dominic Pham, Thomas Horvath, Danny Smith, Ali Syed
*
* Module: Economy
*
*/

#include "Shop.h"


int shopMain(user* character) {

	Dealer* dealer;

	int choice = 0;
	int optionChoice = 0;

	do {
		system("cls");
		printShops();
		cin >> choice;
		switch (choice) {
		case 1: // 1
			//system("cls");
			dealer = new WeaponDealer;
			dealer->printDealerHeader();
			dealer->printDealerOptions();
			dealer->getOptionChoice(dealer, character);
			break;
		case 2: // 2
			break;
		case 3: // 3
			break;
		case 4: // 4
			break;
		case 5: // 5
			exit(0);
			break;
		default:
			break;

		}
	} while ((getchar()) != '\n');
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

