#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "craftItem.h"
using namespace std;
int item_type;

void craftItem(inventory* i) {		// Function asks user what type of item to craft and user selects a craftable item from crafting list
									// and checks if inventory contains required crafting materials for requestes item using boolean logic operaters
	int item_craft = 0;
	while (item_type != 4) {
		cout << "Select the type of item you wish to craft" << endl;
		cout << "1 - Material" << endl;
		cout << "2 - Weapon" << endl;
		cout << "3 - Spell" << endl;
		cout << "4 - Exit" << endl << endl;
		cin >> item_type;

		switch (item_type) {
		case 1:
			while (item_craft != 3) {
				cout << "Select the material you wish to craft" << endl;
				cout << "1 - Black Powder\t\t" << R_BLACK_POWDER << endl;
				cout << "2 - Flash Powder\t\t" << R_FLASH_POWDER << endl;
				cout << "3 - Exit" << endl << endl;
				cin >> item_craft;
				system("cls");
				switch (item_craft) {
				case 1:
					if ((BLACK_POWDER(i->material[2].getQuantity(), i->material[3].getQuantity(), i->material[4].getQuantity())) == 1) {
						i->material[2].subQuantity(6);
						i->material[3].subQuantity(1);
						i->material[4].subQuantity(1);
						i->material[5].addQuantity(1);
						cout << i->material[5].getItemName() << " has been added to the inventory." << endl << endl;
					}
					else {
						cout << "Insufficient crafting materials" << endl << endl;
					}
					break;
				case 2:
					if ((FLASH_POWDER(i->material[7].getQuantity(), i->material[4].getQuantity(), i->material[3].getQuantity())) == 1) {
						i->material[2].subQuantity(6);
						i->material[3].subQuantity(1);
						i->material[4].subQuantity(1);
						i->material[5].addQuantity(1);
						cout << i->material[6].getItemName() << " has been added to the inventory." << endl << endl;
					}
					else {
						cout << "Insufficient crafting materials" << endl << endl;
					}
					break;
				case 3:
					break;
				}
			}
			break;
		case 2:
			while (item_craft != 4) {
				cout << "Select the weapon you wish to craft" << endl;
				cout << "1 - Sword\t\t" << R_SWORD << endl;
				cout << "2 - Warhammer\t\t" << R_WAR_HAMMER << endl;
				cout << "3 - Musket\t\t" << R_MUSKET << endl;
				cout << "4 - Exit" << endl << endl;
				cin >> item_craft;
				system("cls");
				switch (item_craft) {
				case 1:
					if ((SWORD(i->material[0].getQuantity(), i->material[1].getQuantity())) == 1) {
						i->material[0].subQuantity(1);
						i->material[1].subQuantity(10);
						i->weapon[0].addQuantity(1);
						cout << i->weapon[0].getItemName() << " has been added to the inventory." << endl << endl;
					}
					else {
						cout << "Insufficient crafting materials" << endl << endl;
					}
					break;
				case 2:
					if ((WAR_HAMMER(i->material[0].getQuantity(), i->material[1].getQuantity())) == 1) {
						i->material[0].subQuantity(3);
						i->material[1].subQuantity(5);
						i->weapon[1].addQuantity(1);
						cout << i->weapon[1].getItemName() << " has been added to the inventory." << endl << endl;
					}
					else {
						cout << "Insufficient crafting materials" << endl << endl;
					}
					break;
				case 3:
					if ((MUSKET(i->material[0].getQuantity(), i->material[1].getQuantity())) == 1) {
						i->material[0].subQuantity(3);
						i->material[1].subQuantity(15);
						i->weapon[3].addQuantity(1);
						cout << i->weapon[3].getItemName() << " has been added to the inventory." << endl << endl;
					}
					else {
						cout << "Insufficient crafting materials" << endl << endl;
					}
					break;
				case 4:
					break;
				}
			}
			break;
		case 3:
			while (item_craft != 2) {
				cout << "Select the spell you wish to craft" << endl;
				cout << "1 - Flash Spell\t\t" << R_FLASH_SPELL << endl;
				cout << "2 - Exit" << endl << endl;
				cin >> item_craft;
				system("cls");
				switch (item_craft) {
				case 1:
					if ((FLASH_SPELL(i->material[6].getQuantity(), i->material[5].getQuantity())) == 1) {
						i->material[6].subQuantity(3);
						i->material[5].subQuantity(1);
						i->spell[1].addQuantity(1);
						cout << i->spell[1].getItemName() << " has been added to the inventory." << endl << endl;
					}
					else {
						cout << "Insufficient crafting materials" << endl << endl;
					}
					break;
				case 2:
					break;
				}
			}
		case 4:
			break;
		}
	}
	item_type = 0;
	system("cls");
}