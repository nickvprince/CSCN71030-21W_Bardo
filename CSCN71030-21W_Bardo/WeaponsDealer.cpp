/*
* File Name: WeaponsDealer.cpp
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

WeaponDealer::WeaponDealer() : Dealer() {
	this->name = "Hari";
	this->balance = 10000;
}

void WeaponDealer::printDealerInfo() {
	cout << "Dealer Name: " << this->name << endl
		<< "Dealer Balance: " << this->balance << endl;
}

string WeaponDealer::getName() {
	return this->name;
}

int WeaponDealer::getDealerBalance() {
	return this->balance;
}

void WeaponDealer::buy(user* user, string w) {

	// Get item by name
	// do blance stuff
	// add item to inventory

	weapon sword;
	sword.value = 100;
	sword.name = "IronSword";

	user->gold -= sword.value;
	this->balance += sword.value;
	
	if (user->outBattleINV->itemsUsed != MAX_ITEMS) {
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (user->outBattleINV->ItemCount[i] == NULL) {
				user->outBattleINV->Weapons[i] = sword;
				break;
			}
		}
	}

	cout << "Weapon: " << w << endl;
}

void WeaponDealer::sell(inventory* inv, string weapon) {


}

void WeaponDealer::listDealerItems() {

}

void WeaponDealer::printDealerOptions() {
	cout << "Select an option: " << endl
		<< "1. Buy" << endl
		<< "2. Sell" << endl
		<< "3. Barter" << endl
		<< "4. Back" << endl;
}
