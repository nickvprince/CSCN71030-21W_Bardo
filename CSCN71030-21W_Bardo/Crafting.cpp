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

#include "Crafting.h"
int Crafting(void) {
	inventory i;								// Below are test data to simulate game items in inventory, the data is used to test the 
												// crafting module functions, this is just a basic data setup and will be changed in the future
	i.material[0].setItem("Wood", "Organic", 5);
	i.material[1].setItem("Iron Ore", "Found on mountains and used for weapon crafting", 12);
	i.material[2].setItem("Saltpetre", "A white soluble substance that is found in caves, Also known as potassium nitrate", 10);
	i.material[3].setItem("Sulfur", "A brittle solid found deep underground or near volcanic regions", 4);
	i.material[4].setItem("Charcoal", "A black residue that is a byproduct of pyrolysis", 4);
	i.material[5].setItem("Black Powder", " Great for making explosives, careful not to blow your finger off", true);
	i.material[6].setItem("Flash Powder", " Emits bright light when ignited", true);
	i.material[7].setItem("Magnesium", "Found in sea water and minerals", 5);

	i.weapon[0].setItem("Sword", "Kills just about anything", true, 25);
	i.weapon[1].setItem("Warhammer", "Highly destructive weapon", true, 100);
	i.weapon[2].setItem("Bow", "Hits any target within 150 meters, there is no escape", 1, 50);
	i.weapon[3].setItem("Musket", "Boom stick, good against a heavy armoured enemy", true, 160);

	i.spell[0].setItem("Healing Potion", "Player regains 100 HP", 5);
	i.spell[1].setItem("Flash Spell", "Emits blinding light, puts enemy in disabled state", true);

	while (userInput != 3) {
		StarterMenu();
		cin >> userInput;
		system("cls");

		if (cin.fail()) { // input verification check
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (userInput) {
		case 1: // Craft
			craftItem(&i);
			break;
		case 2: // See Inventory
			seeInventory(i);
			break;
		case 3: // Exit
			cout << "Farewell adventurer." << endl;
			break;
		}
	}
}