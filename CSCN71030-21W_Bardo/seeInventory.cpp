#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "seeInventory.h"

using namespace std;

void seeInventory(entity *p) {
	int inventory_choice = 0;
	while (inventory_choice != 3) {
		cout << "Select how you would like to view items in inventory." << endl;
		cout << "1 - Item type, lists items of specified type." << endl;
		cout << "2 - Item search, search for a specified item." << endl;
		cout << "3 - Exit" << endl << endl;

		cin >> inventory_choice;
		system("cls");

		if (cin.fail()) { // input verification check
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (inventory_choice) {
		case 1:
			By_Type(p);   // Displays all items of a specific type that exists in inventory
			break;
		case 2:
			By_Search(p); // Searches through entire inventory for specified item by user and displays item info if item exist in inventory
			break;
		case 3:
			break;
		}
	}
	system("cls");
}