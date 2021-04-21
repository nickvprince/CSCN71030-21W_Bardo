#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <stdbool.h>
#include <ctype.h>
#include "seeInventory.h"

void By_Search(entity *p) {
	string find_item;
	while (find_item != "exit") {
		bool found_item = false;
		cout << "Enter the item name to search (type <exit> to exit): "; 
		getline(cin, find_item);
		system("cls");
		if (find_item != "") {
			if (find_item != "exit") {
				for (int a = 0; a < MAX_ITEMS; a++) {
					if (find_item == p->INV->Items[a].name && p->INV->ItemCount[a] != 0) {
						cout << p->INV->Items[a].name << "\t\t\t\t\t Quantity: " << p->INV->ItemCount[a] << endl;
						found_item = true;
						cout << endl;
						break;
					}
				}
				if (found_item == false) {
					for (int a = 0; a < MAX_ITEMS; a++) {
						if (find_item == p->INV->Weapons[a].name && p->INV->ItemCount[a] != 0) {
							cout << p->INV->Weapons[a].name << "\t\t\t\t\t Quantity: " << p->INV->ItemCount[a] << endl;
							cout << "Damage: " << p->INV->Weapons[a].damage << endl << endl;
							found_item = true;
							cout << endl;
							break;
						}
					}
				}
				if (found_item == false) {
					for (int a = 0; a < MAX_ITEMS; a++) {
						if (find_item == p->INV->Shields[a].name && p->INV->ItemCount[a] != 0) {
							cout << p->INV->Shields[a].name << "\t\t\t\t\t Quantity: " << p->INV->ItemCount[a] << endl;
							cout << "Block Chance: " << p->INV->Shields[a].blockChance << endl << endl;
							found_item = true;
							cout << endl;
							break;
						}
					}
				}
				if (found_item == false) {
					cout << "Item not found in inventory." << endl << endl;
				}
			}
			else {
				return;
			}
		}
	}
}