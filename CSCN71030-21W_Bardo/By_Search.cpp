#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "seeInventory.h"


void By_Search(inventory i) {	
	string find_item;
	while (find_item != "exit") {
		bool found_item = false;
		cout << "Enter the item name to search (type <exit> to quit): "; 
		cin >> find_item;
		system("cls");

		if (find_item != "exit") {
			for (int a = 0; a < MAX_MATERIAL; a++) {
				if (find_item == i.material[a].getItemName() && i.material[a].getQuantity() != 0) {
					cout << "Name: " << i.material[a].getItemName() << "\t\t\t\t Quantity: " << i.material[a].getQuantity() << endl;
					cout << "Description: " << i.material[a].getItemDescription() << endl << endl;
					found_item = true;
					break;
				}
			}
			if (found_item == false) {
				for (int a = 0; a < MAX_WEAPON; a++) {
					if (find_item == i.weapon[a].getItemName() && i.weapon[a].getQuantity() != 0) {
						cout << "Name: " << i.weapon[a].getItemName() << "\t\t\t\t Quantity: " << i.weapon[a].getQuantity() << endl;
						cout << "Description: " << i.weapon[a].getItemDescription() << endl << endl;
						found_item = true;
						break;
					}
				}
			}
			if (found_item == false) {
				for (int a = 0; a < MAX_SPELL; a++) {
					if (find_item == i.spell[a].getItemName() && i.spell[a].getQuantity() != 0) {
						cout << "Name: " << i.spell[a].getItemName() << "\t\t\t\t Quantity: " << i.spell[a].getQuantity() << endl;
						cout << "Description: " << i.spell[a].getItemDescription() << endl << endl;
						found_item = true;
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