#include "OtherFuntions.h"

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string>

void checkUserInput() {

	string enter;
	cin >> enter;

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

void printInventory(user* user) {

	int totalValue = 0;

	cout << endl << "Items: " << endl;
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->inv->Items[i].name != "") {
			cout << "Name: " << user->inv->Items[i].name << "\tQuantity: " << user->inv->itemCount[i] << "\tValue: " << user->inv->Items[i].value << endl;
			totalValue += user->inv->Items[i].value;
		}
	}

	cout << endl << "Weapons: " << endl;
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->inv->Weapons[i].name != "") {
			cout << "Name: " << user->inv->Weapons[i].name << "\tQuantity: " << user->inv->itemCount[i] << "\tValue: " << user->inv->Weapons[i].value << endl;
			totalValue += user->inv->Weapons[i].value;
		}
	}

	cout << endl << "Defence: " << endl;
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->inv->Shields[i].name != "") {
			cout << "Name: " << user->inv->Shields[i].name << "\tQuantity: " << user->inv->itemCount[i] << "\tValue: " << user->inv->Shields[i].value << endl;
			totalValue += user->inv->Shields[i].value;
		}
	}

	cout << endl << "Potions: " << endl;
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->inv->Potions[i].name != "") {
			cout << "Name: " << user->inv->Potions[i].name << "\tQuantity: " << user->inv->itemCount[i] << "\tValue: " << user->inv->Potions[i].value << endl;
			totalValue += user->inv->Potions[i].value;
		}
	}

	cout << endl << endl;

	cout << "User Balance: " << user->gold << "\t" << "Total Value of Inventory: " << totalValue << "\t" << "Total Item Count: " << user->inv->itemsUsed << endl << endl;

	cout << endl << endl;

	pressAnyButtonToContinue("");

	return;
}

