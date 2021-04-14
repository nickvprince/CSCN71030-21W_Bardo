/*
* File Name: DefenceDealer.cpp
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

#include "DefenceDealer.h"

DefenceDealer::DefenceDealer() : Dealer() {
	this->name = "Ilyon";
	this->balance = 10000;
}

void DefenceDealer::printDealerInfo() {
	cout << "Dealer Name: " << this->name << endl
		<< "Dealer Balance: " << this->balance << endl;
}

string DefenceDealer::getName() {
	return this->name;
}

int DefenceDealer::getDealerBalance() {
	return this->balance;
}

void DefenceDealer::buy(entity* user) {

	system("cls");

	// If the user's inventory is full, return.
	if (user->INV->itemsUsed == MAX_ITEMS) {
		cout << "You already have " << MAX_ITEMS << " in your inventory, consider selling some items to make space for purchases." << endl;
		pressAnyButtonToContinue("");
		return;
	}

	bool exists = false;

	string strDef = getDealerBuyChoice(user);

	if (strDef == "No") {
		pressAnyButtonToContinue("");
		return;
	}

	defence def = get_Defence(strDef);


	// If the defensive item condition fails, errorlog, return.
	if (def.failed != GOOD) {
		ErrorLog("An error has occured while getting a defensive item - Module: Economy", "Medium");
		cout << "An error has occured while getting a defensive item" << endl;
		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
		return;
	}

	if (user->level < def.level) {
		pressAnyButtonToContinue("\nYou are not a high enough level to purchase that item.");
		return;
	}

	if (user->gold < def.value) {
		cout << "You do not have enough gold to purchase that item." << endl;
		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
		return;
	}

	user->gold -= def.value;
	this->balance += def.value;

	// If the item exists already.
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->INV->Shields[i].name == def.name) {
			user->INV->ItemCount[i]++;
			exists = true;
			break;
		}
	}

	// If the item does not exist already.
	if (exists == false) {
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (user->INV->ItemCount[i] == NULL || user->INV->ItemCount[i] == EMPTY) {
				user->INV->Shields[i] = def;
				user->INV->ItemCount[i]++;
				user->INV->itemsUsed++;
				break;
			}
		}
	}

	system("cls");

	cout << "Defensive Item: " << def.name
		<< " has been purchased for "
		<< def.value << " gold." << endl << endl;


	exists = false;

	pressAnyButtonToContinue("Press any key to return to the dealer menu...");
	return;
}

void DefenceDealer::sell(entity* user) {

	system("cls");

	defence nullDef;

	nullDef.name = "";
	nullDef.value = 0;
	nullDef.failed = GOOD;
	nullDef.level = 0;
	nullDef.blockChance = 0;

	for (int i = 0; i < MAX_MATERIALS; i++) {
		nullDef.BarterItems[i] = "";
		nullDef.BarterItemsNum[i] = 0;
		nullDef.craftingItems[i] = "";
		nullDef.craftingItemsNum[i] = 0;
	}

	int choice;
	cout << "Here is a list of your defensive items, please select one to sell: " << endl;
	cout << "0. Back" << endl;

	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->INV->Shields[i].name != "") {
			cout << i + 1 << ". " << user->INV->Shields[i].name
				<< " (Quantity = " << user->INV->ItemCount[i] << ") valued at "
				<< user->INV->Shields[i].value << "." << endl;
		}
	}
	cout << endl << "Enter : ";
	cin >> choice;
	checkUserInput();

	if (choice == 0) {
		return;
	}

	choice -= 1;

	if (this->balance < user->INV->Shields[choice].value) {
		cout << "The dealer does not have enough gold to purchase that item from you." << endl;
		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
		return;
	}

	if (user->INV->ItemCount[choice] >= 1) {

		if (user->INV->itemsUsed >= 1) {
			user->gold += user->INV->Shields[choice].value;
			this->balance -= user->INV->Shields[choice].value;

			system("cls");

			cout << "Defensive Item: " << user->INV->Shields[choice].name
				<< " has been sold for "
				<< user->INV->Shields[choice].value
				<< " gold." << endl << endl;


			user->INV->ItemCount[choice] -= 1;

			if (user->INV->ItemCount[choice] == 0) {
				user->INV->itemsUsed -= 1;
				user->INV->Shields[choice] = nullDef;
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

void DefenceDealer::barter(entity* user) {

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

	defence def;
	bool namesEmpty[MAX_ITEMS] = { true };
	bool allNamesEmpty = true;
	bool validAmountItems[MAX_MATERIALS] = { false };
	bool allValid = true;
	bool exists = false;
	bool complete = false;
	int index = 0;

	string strDef = getDealerBuyChoice(user);

	if (strDef == "No") {
		pressAnyButtonToContinue("");
		return;
	} else {
		def = get_Defence(strDef);
	}

	// If the defensive item condition fails, errorlog, return.
	if (def.failed != GOOD) {
		ErrorLog("An error has occured while getting a defensive item - Module: Economy", "Medium");
		cout << "An error has occured while getting a defensive item" << endl;
		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
		return;
	}

	if (user->level < def.level) {
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
		for (int j = 0; j < sizeof(def.BarterItems) / sizeof(string); j++) {
			if (def.BarterItems[j] == user->INV->Items[i].name) {
				// If they have more or equal to the amount || if the item is null (user needs none)
				if (user->INV->ItemCount[i] >= def.BarterItemsNum[j] || def.BarterItemsNum[j] == NULL) {
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
			if (def.BarterItems[i] != "") {
				cout << "Item: " << def.BarterItems[i] << " | Quantity: " << def.BarterItemsNum[i] << endl;
			}
		}

		cout << endl;

		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
		return;

	}

	// ----- Remove item quantites -----
	for (int i = 0; i < MAX_ITEMS; i++) {
		for (int j = 0; j < sizeof(def.BarterItems) / sizeof(string); j++) {
			if (def.BarterItems[j] == user->INV->Items[i].name && def.BarterItems[j] != "") {

				// Take away item count
				user->INV->ItemCount[i] -= def.BarterItemsNum[j];

				// If the item count is 0, make the item null (free the slot).
				if (user->INV->ItemCount[i] < 1) {
					user->INV->itemsUsed -= 1;
					user->INV->Items[i] = nullItem;
					break;
				}

			}
		}
	}


	// Find the next available slot for a defensive item and put it there.
	// If the item exists already.
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->INV->Shields[i].name == def.name) {
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
				user->INV->Shields[i] = def;
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
			<< "Defensive item: " << def.name << endl;

		for (int i = 0; i < MAX_MATERIALS; i++) {
			if (def.BarterItems[i] != "") {
				cout << "Item: " << def.BarterItems[i] << " | Quantity: " << def.BarterItemsNum[i] << endl;
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
			if (def.BarterItems[i] != "") {
				cout << "Item: " << def.BarterItems[i] << " | Quantity: " << def.BarterItemsNum[i] << endl;
			}
		}

		cout << endl;
	}


	pressAnyButtonToContinue("Press any key to return to the dealer menu...");
	return;
}

string DefenceDealer::getDealerBuyChoice(entity* user) {

	int itemChoice = 0;
	int yesNo = 0;
	bool valid = false;
	string strDef = "";

	cout << "Select an item to barter/purchase: " << endl << endl;

	list* defence = new list;
	defence = getListDefences();
	printList(defence, 1);

	int size = sizeof(defence->names) / sizeof(string);
	for (int i = 0; i < MAX_NUM_FILES; i++) {
		if (defence->names[i] == "") {
			size--;
		}
	}
	cout << endl << "Enter : ";
	do {
		cin >> itemChoice;
		checkUserInput();
	} while (itemChoice < 1 || itemChoice > size);

	itemChoice -= 1;

	if (!getItemStats(defence->names[itemChoice], user)) {
		return "No";
	} else {
		cout << endl << "Are you sure you want to purchase/barter for " << defence->names[itemChoice] << "?" << endl
			<< "1. Yes" << endl
			<< "2. No" << endl
			<< "Enter : ";

		do {
			cin >> yesNo;
			checkUserInput();
			switch (yesNo) {
			case 1:
				valid = true;
				return defence->names[itemChoice];
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

		cleanObj(defence);
	}

}

void DefenceDealer::printDealerOptions() {
	cout << "Select an option: " << endl
		<< "1. Buy" << endl
		<< "2. Sell" << endl
		<< "3. Barter" << endl
		<< "4. Display Inventory" << endl
		<< "5. Back" << endl
		<< "Enter : ";
}

bool DefenceDealer::getItemStats(string strDef, entity* user) {

	system("cls");

	printDealerHeader(user);

	cout << endl << "Stats: " << endl;

	int barterCost = 0;
	defence def;
	def = get_Defence(strDef);

	if (def.failed != GOOD) {
		ErrorLog("Failed to get defensive item stats - Module: Economy", "Severe");
		cout << "Failed to get defensive item stats." << endl << endl;
		return false;
	} else {
		cout << endl << "Defensive Item: " << strDef << endl
			<< "Block Chance: " << def.blockChance << endl
			<< "Level: " << def.level << endl
			<< "Value: " << def.value << endl << endl;

		cout << "Items to barter: " << endl;

		for (int i = 0; i < MAX_MATERIALS; i++) {
			if (def.BarterItems[i] != "") {
				item bItem;
				bItem = get_Item(def.BarterItems[i]);

				if (bItem.failed != GOOD) {
					ErrorLog("Failed to get item for stats - Module: Economy", "Critical");
					cout << "Error retrieving barter Item(s)" << endl;
					pressAnyButtonToContinue("");
					return false;
				}
				cout << "Item: " << def.BarterItems[i] << "\tQuantity: " << def.BarterItemsNum[i] << "\tValue: " << bItem.value << endl;
				barterCost += bItem.value * def.BarterItemsNum[i];
			}
		}

		cout << endl << "Total cost to barter: " << barterCost << endl;

	}

}
