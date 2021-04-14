/*
* File Name: Dealer.cpp
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

#include "Dealer.h"

Dealer::Dealer() {
	this->name = "";
	this->balance = 0;
}

void Dealer::printDealerOptions() {
	cout << "Select an option: " << endl
		<< "1. Buy" << endl
		<< "2. Sell" << endl
		<< "3. Barter" << endl
		<< "4. Back" << endl;
}

void Dealer::printDealerHeader(entity* character) {
	cout << "Dealer Name: " << this->name << " || Dealer Balance: " << this->balance << " || User Balance: " << character->gold << endl
		 << "-----------------------------------------------------------------" << endl << endl;
}

void Dealer::getOptionChoice(Dealer* dealer, entity* character) {

	int choice = 0;
	int itemChoice = 0;
	string strWeap = "";

	do {
		//system("cls");
		cin >> choice;
		switch (choice) {
		case 1:
			dealer->printDealerHeader(character);
			dealer->buy(character);
			break;
		case 2: 
			dealer->printDealerHeader(character);
			dealer->sell(character);
			break;
		case 3:
			dealer->printDealerHeader(character);
			dealer->barter(character);
			break;
		case 4:
			printInventory(character);
			break;
		case 5:
			break;
		default:
			break;

		}
	} while ((getchar()) != '\n');
}
