#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "seeInventory.h"

using namespace std;

void seeInventory(inventory i) {
	int inventory_choice = 0;
	while (inventory_choice != 3) {
		cout << "Select how you would like to view items in inventory." << endl;
		cout << "1 - Item type, lists items of specified type." << endl;
		cout << "2 - Item search, search for a specified item." << endl;
		cout << "3 - Exit" << endl << endl;

		cin >> inventory_choice;
		system("cls");

		switch (inventory_choice) {
		case 1:
			By_Type(i);   // Displays all items of a specific type that exists in inventory
			break;
		case 2:
			By_Search(i); // Searches through entire inventory for specified item by user and displays item info if item exist in inventory
			break;
		case 3:
			break;
		}
	}
	system("cls");
}