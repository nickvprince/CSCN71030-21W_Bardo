#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "craftItem.h"

using namespace std;
int item_type;
int item_craft;

void craftItem(entity* p) {		// Function asks user what type of item to craft and user selects a craftable item from crafting list
										// and checks if inventory contains required crafting materials for requested item using boolean logic operaters
	item nullItem;
	nullItem.name = "";
	nullItem.failed == GOOD;
	nullItem.value = 0;
	bool namesEmpty[MAX_ITEMS] = { true };
	bool allNamesEmpty = true;
	bool validAmountItems[MAX_MATERIALS] = { false };
	bool allValid = true;
	bool exists = false;
	bool complete = false;
	int item_craft;

	if (p->INV->itemsUsed == MAX_ITEMS) {
		cout << "You already have " << MAX_ITEMS << " in your inventory" << endl;
		return;
	}

	while (item_type != 3) {
		item_craft = 50;
		if (p->INV->itemsUsed == MAX_ITEMS) { break; }
		cout << "Enter the type of item you wish to craft" << endl;
		cout << "1 - Shield" << endl;
		cout << "2 - Weapon" << endl;
		cout << "3 - Exit" << endl << endl;
		cout << "Enter: ";
		cin >> item_type;
		system("cls");

		if (cin.fail()) { // input verification check
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (item_type) {
		case 1:
			if (p->INV->itemsUsed == MAX_ITEMS) { break; }
			while (item_craft != 0) {
				for (int q = 0; q < MAX_MATERIALS; q++) {
					validAmountItems[q] = false;
				}
				cout << "Enter the shield you wish to craft. Type 0 to exit." << endl << endl;
				list* shield_list = new list;
				shield_list = getListDefences();
				printList(shield_list, 1);
				cout << endl;
				cout << "Enter: ";
				cin >> item_craft;
				system("cls");

				if (cin.fail()) { // input verification check
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				}

				if (item_craft == 0 || item_craft < 0 || item_craft - 1 >= (int)sizeof(shield_list)) {
					break;
				}

				string file_Name = DEFENCEDIR + shield_list->names[item_craft-1] + ".BAMF";
				if ((FileExists(file_Name)) == false) {
					ErrorLog("Error occured during weapon file retrieval, invalid item name - Module: Craft", "Medium");
					break;
				}
				defence craft_shield = get_Defence(shield_list->names[item_craft - 1]);

				if (p->level < craft_shield.level) {
					cout << "Insufficient level to craft item" << endl;
					break;
				}
				
				for (int i = 0; i < MAX_ITEMS; i++) {
					if (p->INV->Items[i].name == "") {
						namesEmpty[i] = true;
					}
				}

				for (int i = 0; i < MAX_ITEMS; i++) {
					if (namesEmpty[i] == false) {
						allNamesEmpty = false;
					}
				}

				for (int i = 0; i < MAX_ITEMS; i++) { // check for valid crafting items
					for (int j = 0; j < sizeof(craft_shield.craftingItems) / sizeof(string); j++) {
						if (craft_shield.craftingItems[j] == p->INV->Items[i].name) {
							if (p->INV->ItemCount[i] >= craft_shield.craftingItemsNum[j] || craft_shield.craftingItemsNum[j] == NULL) {
								validAmountItems[j] = true;
							}
						}
					}
				}

				for (int i = 0; i < MAX_MATERIALS; i++) { // check all items needed are present
					if (validAmountItems[i] != true) {
						allValid = false;
					}
				}

				if (allValid == false || allNamesEmpty == true) {
					system("cls");
					cout << "Insufficient crafting materials" << endl << endl;
					cout << "Required Items: " << endl;
					for (int i = 0; i < MAX_MATERIALS; i++) {
						if (craft_shield.craftingItems[i] != "") {
							cout << "Item: " << craft_shield.craftingItems[i] << "\t\t\t\tQuantity: " << craft_shield.craftingItemsNum[i] << endl;
						}
					}
					cout << endl;
					break;

				}

				for (int i = 0; i < MAX_ITEMS; i++) { // remove crafting items
					for (int j = 0; j < sizeof(craft_shield.craftingItems) / sizeof(string); j++) {
						if (craft_shield.craftingItems[j] == p->INV->Items[i].name && craft_shield.craftingItems[j] != "") {

							p->INV->ItemCount[i] -= craft_shield.craftingItemsNum[j];

							if (p->INV->ItemCount[i] < 1) {
								p->INV->Items[i] = nullItem;
								p->INV->itemsUsed -= 1;
								break;
							}

						}
					}
				}

				for (int i = 0; i < MAX_ITEMS; i++) {
					if (p->INV->Shields[i].name == craft_shield.name) {
						p->INV->ItemCount[i]++;
						exists = true;
						complete = true;
						break;
					}
				}

				if (exists == false) {
					for (int i = 0; i < MAX_ITEMS; i++) {
						if (p->INV->ItemCount[i] == NULL) {
							p->INV->Shields[i] = craft_shield;
							p->INV->ItemCount[i]++;
							p->INV->itemsUsed++;
							complete = true;
							break;
						}
					}
				}
				if (complete == true) {
					cout << craft_shield.name << " was crafted and added to inventory" << endl << endl;
					exists = false;
				}
				else {
					cout << "Insufficient crafting materials" << endl << endl;
					cout << "Required Items: " << endl;
					for (int i = 0; i < MAX_MATERIALS; i++) {
						if (craft_shield.craftingItems[i] != "") {
							cout << "Item: " << craft_shield.craftingItems[i] << "\t\t\t\tQuantity: " << craft_shield.craftingItemsNum[i] << endl;
						}
					}
					cout << endl;
					break;
				}
			}
			break;
		case 2:
			while (item_craft != 0) {
				for (int q = 0; q < MAX_MATERIALS; q++) {
					validAmountItems[q] = false;
				}
				if (p->INV->itemsUsed == MAX_ITEMS) { break; }
				cout << "Enter the weapon you wish to craft. Type 0 to exit." << endl << endl;
				list* weapons_list = new list;
				weapons_list = getListWeapons();
				printList(weapons_list, 1);
				cout << endl;
				cout << "Enter: ";
				cin >> item_craft;
				system("cls");

				if (cin.fail()) { // input verification check
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				}

				if (item_craft == 0 || item_craft < 0 || item_craft - 1 >= 13){
					break;
				}

				string file_Name = WEAPONDIR + weapons_list->names[item_craft-1] + ".BWPF";
				if ((FileExists(file_Name)) == false) {
					ErrorLog("Error occured during weapon file retrieval, invalid item name - Module: Craft", "Medium");
					break;
				}
				weapon craft_weapon = get_Weapon(weapons_list->names[item_craft - 1]);

				if (p->level < craft_weapon.level) {
					cout << "Insufficient level to craft item" << endl;
					break;
				}

				for (int i = 0; i < MAX_ITEMS; i++) {
					if (p->INV->Items[i].name == "") {
						namesEmpty[i] = true;
					}
				}

				for (int i = 0; i < MAX_ITEMS; i++) {
					if (namesEmpty[i] == false) {
						allNamesEmpty = false;
					}
				}

				for (int i = 0; i < MAX_ITEMS; i++) { // check for valid crafting items
					for (int j = 0; j < sizeof(craft_weapon.craftingItems) / sizeof(string); j++) {
						if (craft_weapon.craftingItems[j] == p->INV->Items[i].name) {
							if (p->INV->ItemCount[i] >= craft_weapon.craftingItemsNum[j] || craft_weapon.craftingItemsNum[j] == NULL) {
								validAmountItems[j] = true;
							}
						}
					}
				}

				for (int i = 0; i < MAX_MATERIALS; i++) { // check all items needed are present
					if (validAmountItems[i] != true) {
						allValid = false;
					}
				}

				if (allValid == false || allNamesEmpty == true) {
					system("cls");
					cout << "Insufficient crafting materials" << endl << endl;
					cout << "Required Items: " << endl;
					for (int i = 0; i < MAX_MATERIALS; i++) {
						if (craft_weapon.craftingItems[i] != "") {
							cout << "Item: " << craft_weapon.craftingItems[i] << "\t\t\t\tQuantity: " << craft_weapon.craftingItemsNum[i] << endl;
						}
					}
					cout << endl;
					break;
				}

				for (int i = 0; i < MAX_ITEMS; i++) { // remove crafting items
					for (int j = 0; j < sizeof(craft_weapon.craftingItems) / sizeof(string); j++) {
						if (craft_weapon.craftingItems[j] == p->INV->Items[i].name && craft_weapon.craftingItems[j] != "") {

							p->INV->ItemCount[i] -= craft_weapon.craftingItemsNum[j];

							if (p->INV->ItemCount[i] < 1) {
								p->INV->Items[i] = nullItem;
								p->INV->itemsUsed -= 1;
								break;
							}

						}
					}
				}

				for (int i = 0; i < MAX_ITEMS; i++) {
					if (p->INV->Weapons[i].name == craft_weapon.name) {
						p->INV->ItemCount[i]++;
						exists = true;
						complete = true;
						break;
					}
				}

				if (exists == false) {
					for (int i = 0; i < MAX_ITEMS; i++) {
						if (p->INV->ItemCount[i] == NULL) {
							p->INV->Weapons[i] = craft_weapon;
							p->INV->ItemCount[i]++;
							p->INV->itemsUsed++;
							complete = true;
							break;
						}
					}
				}
				if (complete == true) {
					cout << craft_weapon.name << " was crafted and added to inventory" << endl << endl;
					exists = false;
				}
				else {
					cout << "Insufficient crafting materials" << endl << endl;
					cout << "Your Items: " << endl;
					for (int i = 0; i < MAX_ITEMS; i++) {
						if (p->INV->Items[i].name != "") {
							cout << "Item: " << p->INV->Items[i].name << "\t\t\t\tQuantity: " << p->INV->ItemCount[i] << endl;
						}
					}
					cout << endl;
					cout << "Required Items: " << endl;
					for (int i = 0; i < MAX_MATERIALS; i++) {
						if (craft_weapon.craftingItems[i] != "") {
							cout << "Item: " << craft_weapon.craftingItems[i] << "\t\t\t\tQuantity: " << craft_weapon.craftingItemsNum[i] << endl;
						}
					}
					cout << endl;
					break;
				}
			}
			break;
		case 3:
			break;
		}
	}
	item_type = 0;
	system("cls");
}