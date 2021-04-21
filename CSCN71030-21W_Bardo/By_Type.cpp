#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "seeInventory.h"

using namespace std;

void By_Type(entity *p) {
	int type_choice = 0;
	while (type_choice != 4) {
		bool empty = true;
		cout << "Select a type of item to view from the inventory:" << endl;
		cout << "1 - Items" << endl;
		cout << "2 - Weapon" << endl;
		cout << "3 - Shield" << endl;
		cout << "4 - Exit" << endl << endl;
		cout << "Enter: ";
		cin >> type_choice;
		system("cls");

		if (cin.fail()) { // input verification check
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
		}

		switch (type_choice) {  
		case 1:
			for (int a = 0; a < MAX_ITEMS; a++) {
				if (p->INV->ItemCount[a] != 0 && p->INV->Items[a].name != "") {
					cout << p->INV->Items[a].name << "\t\t\t\t\t Quantity: " << p->INV->ItemCount[a] << endl;
					empty = false;
				}
			}
			if (empty == true) {
				cout << "No items of this type in inventory" << endl;
			}
			cout << endl;
			break;
		case 2:
			for (int a = 0; a < MAX_ITEMS; a++) {
				if (p->INV->ItemCount[a] != 0 && p->INV->Weapons[a].name != "") {
					cout << p->INV->Weapons[a].name << "\t\t\t\t\t Quantity: " << p->INV->ItemCount[a] << endl;
					cout << "Damage: " << p->INV->Weapons[a].damage << endl << endl;
					empty = false;
				}
			}
			if (empty == true) {
				cout << "No items of this type in inventory" << endl;
			}
			cout << endl;
			break;
		case 3:
			for (int a = 0; a < MAX_ITEMS; a++) {
				if (p->INV->ItemCount[a] != 0 && p->INV->Shields[a].name != "") {
					cout << p->INV->Shields[a].name << "\t\t\t\t\t Quantity: " << p->INV->ItemCount[a] << endl;
					cout << "Block Chance: " << p->INV->Shields[a].blockChance << endl << endl;
					empty = false;
				}
			}
			if (empty == true) {
				cout << "No items of this type in inventory" << endl;
			}
			cout << endl;
			break;
		case 4:
			return;
		}
	}
	system("cls");
}