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

void WeaponDealer::buy(user* user) {

	system("cls");

	// If the user's inventory is full, return.
	if (user->inv->itemsUsed == MAX_ITEMS) {
		cout << "You already have " << MAX_ITEMS << " in your inventory, consider selling some items to make space for purchases." << endl;
		getc(stdin);
		return;
	}

	weapon weap;
	bool exists = false;

	string strWeap = getDealerBuyChoice();
	// weapon weap = getWeapon(strWeap);

	// If the weapon condition fails, errorlog, return.
	if (weap.failed != GOOD) {
		//ErrorLog("An error has occured while getting a weapon", "Medium");
		cout << "An error has occured while getting a weapon" << endl;
		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
		return;
	}

	if (strWeap == "Sword") {
		weap.value = 125;
		weap.name = "IronSword";
	} else if (strWeap == "Bow") {
		weap.value = 225;
		weap.name = "Bow";
	} else if (strWeap == "Axe") {
		weap.value = 500;
		weap.name = "Axe";
	} else {
		cout << "A problem has occured" << endl;
		return;
	}

	if (user->gold < weap.value) {
		cout << "You do not have enough gold to purchase that item." << endl;
		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
		return;
	}

	user->gold -= weap.value;
	this->balance += weap.value;

	// If the item exists already.
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->inv->Weapons[i].name == weap.name) {
			user->inv->itemCount[i]++;
			user->inv->itemsUsed++;
			exists = true;
		}
	}

	// If the item does not exist already.
	if (exists == false) {
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (user->inv->itemCount[i] == NULL || user->inv->itemCount[i] == 0) {
				user->inv->Weapons[i] = weap;
				user->inv->itemCount[i]++;
				user->inv->itemsUsed++;
				break;
			}
		}
	}

	cout << "Weapon: " << weap.name
		<< " has been purchased for "
		<< weap.value << " gold." << endl << endl;


	exists = false;

	pressAnyButtonToContinue("Press any key to return to the dealer menu...");

}

void WeaponDealer::sell(user* user) {

	system("cls");

	weapon nullWeap;

	int choice;
	cout << "Here is a list of your weapons, please select one to sell: " << endl;
	cout << "0. Back" << endl;

	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->inv->Weapons[i].name != "") {
			cout << i + 1 << ". " << user->inv->Weapons[i].name 
				<< " (Quantity = " << user->inv->itemCount[i] << ") valued at " 
				<< user->inv->Weapons[i].value << "." << endl;
		}
	}

	cin >> choice;
	
	if (choice == 0) {
		return;
	}

	choice -= 1;

	if (this->balance < user->inv->Weapons[choice].value) {
		cout << "The dealer does not have enough gold to purchase that item from you." << endl;
		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
		return;
	}

	if (user->inv->itemCount[choice] >= 1) {

		if (user->inv->itemsUsed >= 1) {
			user->gold += user->inv->Weapons[choice].value;
			this->balance -= user->inv->Weapons[choice].value;

			cout << "Weapon: " << user->inv->Weapons[choice].name
				<< " has been sold for "
				<< user->inv->Weapons[choice].value
				<< " gold." << endl;

			
			user->inv->itemsUsed -= 1;
			user->inv->itemCount[choice] -= 1;

			if (user->inv->itemCount[choice] == 0) {
				user->inv->Weapons[choice] = nullWeap;
			}

		} else {
			cout << "A Problem Has Occured." << endl;
		}

	} else {
		cout << "There is nothing to sell there." << endl;
	}

	pressAnyButtonToContinue("Press any key to return to the dealer menu...");

}

void WeaponDealer::barter(user* user) {
	
	


}

string WeaponDealer::getDealerBuyChoice() {

	int itemChoice = 0;
	string strWeap = "";

	cout << "Select an item to purchase: " << endl;

	/*string weapArray = getListWeapons();

	for (int i = 0; i < sizeof(weapArray) / sizeof(string); i++) {
		cout << i << ". " << weapArray[i] << endl;
	}

	cin >> itemChoice;

	return weapArray[itemChoice];*/

	cout << "1. Sword" << endl
		 << "2. Bow" << endl
		 << "3. Axe" << endl
		 << "4. Back" << endl;

	cin >> itemChoice;

	switch (itemChoice) {
	case 1:
		strWeap = "Sword";
		break;
	case 2:
		strWeap = "Bow";
		break;
	case 3:
		strWeap = "Axe";
		break;
	case 4: break;
	default:
		cout << "please select a valid item" << endl;
		break;
	}

	return strWeap;
}

void WeaponDealer::printDealerOptions() {
	cout << "Select an option: " << endl
		<< "1. Buy" << endl
		<< "2. Sell" << endl
		<< "3. Barter" << endl
		<< "4. Back" << endl;
}
