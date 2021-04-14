/*
* File Name: WeaponsDealer.cpp
*
* Programmer: Nicholas Prince
* Class: Team Based Software Development CSCN71030-21W-SEC1-PROJECT 2
* Date: March 22, 2021
* Teacher: Dr. Elliott Coleshill
* Team: Dominic Pham, Thomas Horvath, Danny Smith, Ali Syed
*
* Module: Economy
*
*/

#include "WeaponsDealer.h"

WeaponDealer::WeaponDealer() : Dealer() {
	this->name = "Hari";
	this->balance = 10000;
}

void WeaponDealer::printDealerInfo() {
	cout << "Dealer Name: " << this->name << endl
		<< "Dealer Balance: " << this->balance << endl;
}

string WeaponDealer::getName() {
	return this->name;
}

int WeaponDealer::getDealerBalance() {
	return this->balance;
}

void WeaponDealer::buy(entity* user) {

	system("cls");

	// If the user's inventory is full, return.
	if (user->INV->itemsUsed == MAX_ITEMS) {
		cout << "You already have " << MAX_ITEMS << " in your inventory, consider selling some items to make space for purchases." << endl;
		pressAnyButtonToContinue("");
		return;
	}

	bool exists = false;

	string strWeap = getDealerBuyChoice(user);

	if (strWeap == "No") {
		pressAnyButtonToContinue("");
		return;
	} 

	weapon weap = get_Weapon(strWeap);
	

	// If the weapon condition fails, errorlog, return.
	if (weap.failed != GOOD) {
		ErrorLog("An error has occured while getting a weapon - Module: Economy", "Medium");
		cout << "An error has occured while getting a weapon" << endl;
		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
		return;
	}

	if (user->level < weap.level) {
		pressAnyButtonToContinue("\nYou are not a high enough level to purchase that item.");
		return;
	}


	if (user->gold < weap.value) {
		cout << "You do not have enough gold to purchase that item." << endl;
		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
		return;
	}

	user->gold -= weap.value;
	this->balance += weap.value;

	// If the item exists already.
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->INV->Weapons[i].name == weap.name) {
			user->INV->ItemCount[i]++;
			exists = true;
			break;
		}
	}

	// If the item does not exist already.
	if (exists == false) {
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (user->INV->ItemCount[i] == NULL || user->INV->ItemCount[i] == EMPTY) {
				user->INV->Weapons[i] = weap;
				user->INV->ItemCount[i]++;
				user->INV->itemsUsed++;
				break;
			}
		}
	}

	system("cls");

	cout << "Weapon: " << weap.name
		<< " has been purchased for "
		<< weap.value << " gold." << endl << endl;


	exists = false;

	pressAnyButtonToContinue("Press any key to return to the dealer menu...");
	return;
}

void WeaponDealer::sell(entity* user) {

	system("cls");

	weapon nullWeap;

	nullWeap.name = "";
	nullWeap.value = 0;
	nullWeap.failed = GOOD;
	nullWeap.level = 0;
	nullWeap.damage = 0;
	
	for (int i = 0; i < MAX_MATERIALS; i++) {
		nullWeap.BarterItems[i] = "";
		nullWeap.BarterItemsNum[i] = 0;
		nullWeap.craftingItems[i] = "";
		nullWeap.craftingItemsNum[i] = 0;
	}

	int choice;
	cout << "Here is a list of your weapons, please select one to sell: " << endl;
	cout << "0. Back" << endl;

	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->INV->Weapons[i].name != "") {
			cout << i + 1 << ". " << user->INV->Weapons[i].name 
				<< " (Quantity = " << user->INV->ItemCount[i] << ") valued at " 
				<< user->INV->Weapons[i].value << "." << endl;
		}
	}
	cout << endl << "Enter : ";
	cin >> choice;
	checkUserInput();
	
	if (choice == 0) {
		return;
	}

	choice -= 1;

	if (this->balance < user->INV->Weapons[choice].value) {
		cout << "The dealer does not have enough gold to purchase that item from you." << endl;
		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
		return;
	}

	if (user->INV->ItemCount[choice] >= 1) {

		if (user->INV->itemsUsed >= 1) {
			user->gold += user->INV->Weapons[choice].value;
			this->balance -= user->INV->Weapons[choice].value;

			system("cls");

			cout << "Weapon: " << user->INV->Weapons[choice].name
				<< " has been sold for "
				<< user->INV->Weapons[choice].value
				<< " gold." << endl << endl;

			
			user->INV->ItemCount[choice] -= 1;

			if (user->INV->ItemCount[choice] == 0) {
				user->INV->itemsUsed -= 1;
				user->INV->Weapons[choice] = nullWeap;
			}

		} else {
			cout << "A Problem Has Occured." << endl;
		}

	} else {
		cout << "There is nothing to sell there." << endl;
	}

	pressAnyButtonToContinue("Press any key to return to the dealer menu...");
	return;
}

void WeaponDealer::barter(entity* user) {
	
	system("cls");

	// If the user's inventory is full, return.
	if (user->INV->itemsUsed == MAX_ITEMS) {
		cout << "You already have " << MAX_ITEMS << " in your inventory, consider selling some items to make space for purchases." << endl;
		pressAnyButtonToContinue("");
		return;
	}

	item nullItem;

	nullItem.name = "";
	nullItem.failed = GOOD;
	nullItem.value = 0;
	for (int i = 0; i < MAX_MATERIALS; i++) {
		nullItem.BarterItems[i] = "";
		nullItem.BarterItemsNum[i] = 0;
	}

	weapon weap;
	bool namesEmpty[MAX_ITEMS] = { true };
	bool allNamesEmpty = true;
	bool validAmountItems[MAX_MATERIALS] = { false };
	bool allValid = true;
	bool exists = false;
	bool complete = false;
	int index = 0;

	string strWeap = getDealerBuyChoice(user);

	if (strWeap == "No") {
		pressAnyButtonToContinue("");
		return;
	} else {
		weap = get_Weapon(strWeap);
	}

	// If the weapon condition fails, errorlog, return.
	if (weap.failed != GOOD) {
		ErrorLog("An error has occured while getting a weapon - Module: Economy", "Medium");
		cout << "An error has occured while getting a weapon" << endl;
		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
		return;
	}

	if (user->level < weap.level) {
		pressAnyButtonToContinue("\nYou are not a high enough level to barter for that item.");
		return;
	}

	// If the user doesn't have any items
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->INV->Items[i].name == "") {
			namesEmpty[i] = true;
		}
	}

	// If no items are full
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (namesEmpty[i] == false) {
			allNamesEmpty = false;
		}
	}


	// ----- Check if user has correct amount of items -----
	for (int i = 0; i < MAX_ITEMS; i++) {
		for (int j = 0; j < sizeof(weap.BarterItems) / sizeof(string); j++) {
			if (weap.BarterItems[j] == user->INV->Items[i].name) {
				// If they have more or equal to the amount || if the item is null (user needs none)
				if (user->INV->ItemCount[i] >= weap.BarterItemsNum[j] || weap.BarterItemsNum[j] == NULL) {
					validAmountItems[j] = true;
				}
			}
		}
	}

	// ----- Check make sure that the user has the correct amount for ALL items (errorCheck) -----

	for (int i = 0; i < MAX_MATERIALS; i++) {
		if (validAmountItems[i] != true) {
			allValid = false;
		}
	}

	if (allValid == false || allNamesEmpty == true) {
		system("cls");
		cout << "You are missing items to complete the trade!" << endl << endl;
		cout << "Your Items: " << endl;
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (user->INV->Items[i].name != "") {
				cout << "Item: " << user->INV->Items[i].name << " | Quantity: " << user->INV->ItemCount[i] << endl;
			}
		}
		cout << endl;
		cout << "Required Items: " << endl;
		for (int i = 0; i < MAX_MATERIALS; i++) {
			if (weap.BarterItems[i] != "") {
				cout << "Item: " << weap.BarterItems[i] << " | Quantity: " << weap.BarterItemsNum[i] << endl;
			}
		}

		cout << endl;

		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
		return;

	}
	
	// ----- Remove item quantites -----
	for (int i = 0; i < MAX_ITEMS; i++) {
		for (int j = 0; j < sizeof(weap.BarterItems) / sizeof(string); j++) {
			if (weap.BarterItems[j] == user->INV->Items[i].name && weap.BarterItems[j] != "") {
				
				// Take away item count
				user->INV->ItemCount[i] -= weap.BarterItemsNum[j];

				// If the item count is 0, make the item null (free the slot).
				if (user->INV->ItemCount[i] < 1) {
					user->INV->Items[i] = nullItem;
					user->INV->itemsUsed -= 1;
					break;
				}

			}
		}
	}


	// Find the next available slot for a weapon and put it there.
	// If the item exists already.
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->INV->Weapons[i].name == weap.name) {
			user->INV->ItemCount[i]++;
			exists = true;
			complete = true;
			break;
		}
	}

	// If the item does not exist already.
	if (exists == false) {
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (user->INV->ItemCount[i] == NULL) {
				user->INV->Weapons[i] = weap;
				user->INV->ItemCount[i]++;
				user->INV->itemsUsed++;
				complete = true;
				break;
			}
		}
	}

	system("cls");

	if (complete == true) {
		cout << "You have successfully bartered the following materials for:" << endl
			<< "Weapon: " << weap.name << endl;

		for (int i = 0; i < MAX_MATERIALS; i++) {
			if (weap.BarterItems[i] != "") {
				cout << "Item: " << weap.BarterItems[i] << " | Quantity: " << weap.BarterItemsNum[i] << endl;
			}
		}

		exists = false;
	} else {
		cout << "You are missing items to complete the trade!" << endl << endl;
		cout << "Your Items: " << endl;
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (user->INV->Items[i].name != "") {
				cout << "Item: " << user->INV->Items[i].name << " | Quantity: " << user->INV->ItemCount[i] << endl;
			}
		}
		cout << endl;
		cout << "Required Items: " << endl;
		for (int i = 0; i < MAX_MATERIALS; i++) {
			if (weap.BarterItems[i] != "") {
				cout << "Item: " << weap.BarterItems[i] << " | Quantity: " << weap.BarterItemsNum[i] << endl;
			}
		}

		cout << endl;
	}


	pressAnyButtonToContinue("Press any key to return to the dealer menu...");
	return;
}

string WeaponDealer::getDealerBuyChoice(entity* user) {

	int itemChoice = 0;
	int yesNo = 0;
	bool valid = false;
	string strWeap = "";

	cout << "Select an item to barter/purchase: " << endl << endl;
	
	list* weapons = new list;
	weapons = getListWeapons();
	printList(weapons, 1);

	int size = sizeof(weapons->names) / sizeof(string);
	for (int i = 0; i < MAX_NUM_FILES; i++) {
		if (weapons->names[i] == "") {
			size--;
		}
	}
	cout << endl << "Enter : ";
	do {
		cin >> itemChoice;
		checkUserInput();
	} while (itemChoice < 1 || itemChoice > size);

	itemChoice -= 1;

	if (!getItemStats(weapons->names[itemChoice], user)) {
		return "No";
	} else {
		cout << endl << "Are you sure you want to purchase/barter for " << weapons->names[itemChoice] << "?" << endl
			<< "1. Yes" << endl
			<< "2. No" << endl
			<< "Enter : ";

		do {
			cin >> yesNo;
			checkUserInput();
			switch (yesNo) {
			case 1:
				valid = true;
				return weapons->names[itemChoice];
				break;
			case 2:
				valid = true;
				return "No";
				break;
			default:
				valid = false;
				break;

			}
		} while (!valid);

		cleanObj(weapons);
	}

}

void WeaponDealer::printDealerOptions() {
	cout << "Select an option: " << endl
		<< "1. Buy" << endl
		<< "2. Sell" << endl
		<< "3. Barter" << endl
		<< "4. Display Inventory" << endl
		<< "5. Back" << endl
		<< "Enter : ";
}

bool WeaponDealer::getItemStats(string strWeap, entity* user) {
	
	system("cls");

	printDealerHeader(user);

	cout << endl << "Stats: " << endl;

	int barterCost = 0;
	weapon weap;
	weap = get_Weapon(strWeap);

	if (weap.failed != GOOD) {
		ErrorLog("Failed to get weapon stats - Module: Economy", "Severe");
		cout << "Failed to get weapon stats." << endl << endl;
		return false;
	} else {
		cout << endl << "Weapon: " << strWeap << endl
			<< "Damage: " << weap.damage << endl
			<< "Level: " << weap.level << endl
			<< "Value: " << weap.value << endl << endl;

		cout << "Items to barter: " << endl;
		
		for (int i = 0; i < MAX_MATERIALS; i++) {
			if (weap.BarterItems[i] != "") {
				item bItem;
				bItem = get_Item(weap.BarterItems[i]);

				if (bItem.failed != GOOD) {
					ErrorLog("Failed to get item for stats - Module: Economy", "Critical");
					cout << "Error retrieving barter Item(s)" << endl;
					pressAnyButtonToContinue("");
					return false;
				}
				cout << "Item: " << weap.BarterItems[i] << "\tQuantity: " << weap.BarterItemsNum[i] << "\tValue: " << bItem.value << endl;
				barterCost += bItem.value * weap.BarterItemsNum[i];
			}
		}

		cout << endl << "Total cost to barter: " << barterCost << endl;

	}

}
