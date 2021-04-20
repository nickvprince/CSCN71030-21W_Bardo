// File Name : Crafting.cpp
//
// Programmer : Dominic Pham
// Class : Team Based Software Development CSCN71030-21W-SEC1-PROJECT 2
// Date : March 26, 2021
// Teacher : Dr. Elliott Coleshill
// Team : Danny Smith, Thomas Horvath, Nicholas Prince, Ali Syed
//
// Description: Tests crafting functions such as crafting items and viewing items in inventory
//
//
// Version 1.0
// First draft of crafting module
//
// Future improvements and fixes:
// - fix search function, cannot search for items with names that consists of more than 1 word (fixed 04/05/21)
// - improve search algorithmn to be more efficient
// - better method to implement crafting recipes 

#include <iostream>
#include "Crafting.h"
#include "seeInventory.h"

bool Crafting(entity* player) {
	system("cls");
	int userInput = 0;
	while (userInput != 3) {

		StarterMenu();
		cout << "Enter: ";
		cin >> userInput;
		system("cls");

		if (cin.fail()) { // input verification check
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (userInput) {
		case 1: // Craft
			craftItem(player);
			break;
		case 2: // See Inventory
			seeInventory(player);
			break;
		case 3: // Exit
			break;
		}
	}
	return true;
}