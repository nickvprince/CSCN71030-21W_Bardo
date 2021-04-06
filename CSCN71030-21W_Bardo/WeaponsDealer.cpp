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

	weapon weap;
	bool exists = false;

	string strWeap = getDealerBuyChoice();
	// weapon weap = getWeapon(strWeap);

	if (weap.failed != GOOD) {
		//ErrorLog("An error has occured while getting a weapon", "Medium");
		cout << "An error has occured while getting a weapon" << endl;
		getc(stdin);
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
		getc(stdin);
		return;
	}

	user->gold -= weap.value;
	this->balance += weap.value;

	if (user->inv->itemsUsed != MAX_ITEMS) {
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (user->inv->Weapons[i].name == weap.name) {
				user->inv->itemCount[i]++;
				exists = true;
			}
		}

		if (exists == false) {
			for (int i = 0; i < MAX_ITEMS; i++) {
				if (user->inv->itemCount[i] == NULL || user->inv->itemCount[i] == 0) {
					user->inv->Weapons[i] = weap;
					user->inv->itemCount[i] += 1;
					user->inv->itemsUsed += 1;
					break;
				}
			}
		}

		cout << "Weapon: " << weap.name
			<< " has been purchased for "
			<< weap.value << " gold." << endl;

	}

	cout << endl << "press enter to continue: " << endl;

	exists = false;

	getchar();

}

void WeaponDealer::sell(user* user) {

	system("cls");

	weapon nullWeap;

	int choice;
	cout << "Here is a list of your weapons, please select one to sell: " << endl;
	cout << "0. Back" << endl;

	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->inv->Weapons[i].name != "") {
			cout << i + 1 << ". " << user->inv->Weapons[i].name << " valued at " << user->inv->Weapons[i].value << "." << endl;
		}
	}

	cin >> choice;
	
	if (choice == 0) {
		return;
	}

	choice -= 1;

	if (this->balance < user->inv->Weapons[choice].value) {
		cout << "The dealer does not have enough gold to purchase that item from you." << endl;
		getc(stdin);
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

	cout << endl << "press enter to continue: " << endl;

	getchar();
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
		cout << "please select an item" << endl;
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
