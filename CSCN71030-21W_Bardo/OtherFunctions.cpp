/*
* File Name: WeaponsDealer.h
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

#include "OtherFuntions.h"

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string>

void checkUserInput() {
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

void pressAnyButtonToContinue(string str) {

	if (str != "") {
		cout << str;
		system("pause >nul");
	} else {
		system("pause");
	}
}

void printInventory(entity* user) {

	int totalValue = 0;

	bool itemHere = false;

	system("cls");

	cout << "Here is your inventory: " << endl << endl;

	cout << endl << "Items: " << endl;
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->INV->Items[i].name != "") {
			cout << "Name: " << user->INV->Items[i].name << "\tQuantity: " << user->INV->ItemCount[i] << "\tValueIitem: " << user->INV->Items[i].value << endl;
			totalValue += user->INV->Items[i].value * user->INV->ItemCount[i];
			itemHere = true;
		}
	}

	if (itemHere != true) {
		cout << "Empty" << endl;
	}
	itemHere = false;

	cout << endl << "Weapons: " << endl;
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->INV->Weapons[i].name != "") {
			cout << "Name: " << user->INV->Weapons[i].name << "\tQuantity: " << user->INV->ItemCount[i] << "\tValue/Weapon: " << user->INV->Weapons[i].value << endl;
			totalValue += user->INV->Weapons[i].value * user->INV->ItemCount[i];
			itemHere = true;
		}
	}

	if (itemHere != true) {
		cout << "Empty" << endl;
	}
	itemHere = false;

	cout << endl << "Defence: " << endl;
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->INV->Shields[i].name != "") {
			cout << "Name: " << user->INV->Shields[i].name << "\tQuantity: " << user->INV->ItemCount[i] << "\tValue/Defence: " << user->INV->Shields[i].value << endl;
			totalValue += user->INV->Shields[i].value * user->INV->ItemCount[i];
			itemHere = true;
		}
	}

	if (itemHere != true) {
		cout << "Empty" << endl;
	}
	itemHere = false;

	cout << endl << "Potions: " << endl;
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->INV->Potions[i].name != "") {
			cout << "Name: " << user->INV->Potions[i].name << "\tQuantity: " << user->INV->ItemCount[i] << "\tValue/Potion: " << user->INV->Potions[i].value << endl;
			totalValue += user->INV->Potions[i].value * user->INV->ItemCount[i];
			itemHere = true;
		}
	}

	if (itemHere != true) {
		cout << "Empty" << endl;
	}
	itemHere = false;

	cout << endl << endl;

	cout << "User Balance: " << user->gold << "\t" << "Total Value of Inventory: " << totalValue << "\t" << "Total Item Count: " << user->INV->itemsUsed << endl << endl;

	cout << endl << endl;

	pressAnyButtonToContinue("");

	return;
}

