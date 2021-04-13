#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "seeInventory.h"

using namespace std;

void By_Type(inventory i) {	
	int type_choice = 0;
	while (type_choice != 4) {
		cout << "Select a type of item to view from the inventory:" << endl;
		cout << "1 - Material" << endl;
		cout << "2 - Weapon" << endl;
		cout << "3 - Spell" << endl;
		cout << "4 - Exit" << endl << endl;
		cin >> type_choice;
		system("cls");

		if (cin.fail()) { // input verification check
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
		}

		switch (type_choice) {  
		case 1:
			for (int a = 0; a < MAX_MATERIAL; a++) {
				if ((i.material[a].getQuantity()) != 0) {
					cout << "Name: " << i.material[a].getItemName() << "\t\t\t\t Quantity: " << i.material[a].getQuantity() << endl;
					cout << "Description: " << i.material[a].getItemDescription() << endl << endl;
				}
			}
			break;
		case 2:
			for (int a = 0; a < MAX_WEAPON; a++) {
				if ((i.weapon[a].getQuantity()) != 0) {
					cout << "Name: " << i.weapon[a].getItemName() << "\t\t\t\t Quantity: " << i.weapon[a].getQuantity() << endl;
					cout << "Description: " << i.weapon[a].getItemDescription() << endl;
					cout << "Damage: " << i.weapon[a].getDamage() << endl << endl;
				}
			}
			break;
		case 3:
			for (int a = 0; a < MAX_SPELL; a++) {
				if ((i.spell[a].getQuantity()) != 0) {
					cout << "Name: " << i.spell[a].getItemName() << "\t\t\t\t Quantity: " << i.spell[a].getQuantity() << endl;
					cout << "Description: " << i.spell[a].getItemDescription() << endl << endl;
					if ((i.spell[a].getDamage()) != 0) {
						cout << "Damage: " << i.spell[a].getDamage() << endl << endl;
					}
				}
			}
			break;
		case 4:
			return;
		}
	}
	system("cls");
}