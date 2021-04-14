/*
* File Name: ItemDealer.cpp
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

#include "ItemDealer.h"

ItemDealer::ItemDealer() : Dealer() {
	this->name = "Sterling";
	this->balance = 10000;
}

void ItemDealer::printDealerInfo() {
	cout << "Dealer Name: " << this->name << endl
		<< "Dealer Balance: " << this->balance << endl;
}

string ItemDealer::getName() {
	return this->name;
}

int ItemDealer::getDealerBalance() {
	return this->balance;
}

void ItemDealer::buy(entity* user) {

	system("cls");

	// If the user's inventory is full, return.
	if (user->INV->itemsUsed == MAX_ITEMS) {
		cout << "You already have " << MAX_ITEMS << " in your inventory, consider selling some items to make space for purchases." << endl;
		pressAnyButtonToContinue("");
		return;
	}

	bool exists = false;

	string strItem = getDealerBuyChoice(user);

	if (strItem == "No") {
		pressAnyButtonToContinue("");
		return;
	}

	item item = get_Item(strItem);
	
	// If the weapon condition fails, errorlog, return.
	if (item.failed != GOOD) {
		ErrorLog("An error has occured while getting an item - Module: Economy", "Medium");
		cout << "An error has occured while getting an item" << endl;
		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
		return;
	}

	int quant = 0;
	cout << endl << "Please enter a quantity: " << endl;
	cin >> quant;
	checkUserInput();


	if (user->gold < item.value * quant) {
		cout << "You do not have enough gold to purchase " << quant << " " << item.name << "." << endl;
		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
		return;
	}

	for (int i = 0; i < quant; i++) {
	
		user->gold -= item.value;
		this->balance += item.value;

		// If the item exists already.
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (user->INV->Items[i].name == item.name) {
				user->INV->ItemCount[i]++;
				exists = true;
				break;
			}
		}

		// If the item does not exist already.
		if (exists == false) {
			for (int i = 0; i < MAX_ITEMS; i++) {
				if (user->INV->ItemCount[i] == NULL || user->INV->ItemCount[i] == EMPTY) {
					user->INV->Items[i] = item;
					user->INV->ItemCount[i]++;
					user->INV->itemsUsed++;
					break;
				}
			}
		}

	}

	system("cls");

	cout << quant << " " << item.name << "(s)"
		<< " has been purchased for "
		<< item.value * quant << " gold." << endl << endl;


	exists = false;

	pressAnyButtonToContinue("Press any key to return to the dealer menu...");
	return;
}

void ItemDealer::sell(entity* user) {

	system("cls");

	item nullItem;

	nullItem.name = "";
	nullItem.value = 0;
	nullItem.failed = GOOD;

	for (int i = 0; i < MAX_MATERIALS; i++) {
		nullItem.BarterItems[i] = "";
		nullItem.BarterItemsNum[i] = 0;
		/*nullItem.craftingItems[i] = "";
		nullItem.craftingItemsNum[i] = 0;*/
	}

	int choice;
	cout << "Here is a list of your items, please select one to sell: " << endl;
	cout << "0. Back" << endl;

	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->INV->Items[i].name != "") {
			cout << i + 1 << ". " << user->INV->Items[i].name
				<< " (Quantity = " << user->INV->ItemCount[i] << ") valued at "
				<< user->INV->Items[i].value << "." << endl;
		}
	}
	cout << endl << "Enter : ";
	cin >> choice;
	checkUserInput();

	if (choice == 0) {
		return;
	}

	choice -= 1;

	if (this->balance < user->INV->Items[choice].value) {
		cout << "The dealer does not have enough gold to purchase that item from you." << endl;
		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
		return;
	}

	if (user->INV->ItemCount[choice] >= 1) {

		if (user->INV->itemsUsed >= 1) {
			user->gold += user->INV->Items[choice].value;
			this->balance -= user->INV->Items[choice].value;

			system("cls");

			cout << "Item: " << user->INV->Items[choice].name
				<< " has been sold for "
				<< user->INV->Items[choice].value
				<< " gold." << endl << endl;


			user->INV->ItemCount[choice] -= 1;

			if (user->INV->ItemCount[choice] == 0) {
				user->INV->itemsUsed -= 1;
				user->INV->Items[choice] = nullItem;
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

void ItemDealer::barter(entity* user) {

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

	item item;
	bool namesEmpty[MAX_ITEMS] = { true };
	bool allNamesEmpty = true;
	bool validAmountItems[MAX_MATERIALS] = { false };
	bool allValid = true;
	bool exists = false;
	bool complete = false;
	int index = 0;

	string strItem = getDealerBuyChoice(user);

	if (strItem == "No") {
		pressAnyButtonToContinue("");
		return;
	} else {
		item = get_Item(strItem);
	}

	// If the weapon condition fails, errorlog, return.
	if (item.failed != GOOD) {
		ErrorLog("An error has occured while getting an item - Module: Economy", "Medium");
		cout << "An error has occured while getting an item" << endl;
		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
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
		for (int j = 0; j < sizeof(item.BarterItems) / sizeof(string); j++) {
			if (item.BarterItems[j] == user->INV->Items[i].name) {
				// If they have more or equal to the amount || if the item is null (user needs none)
				if (user->INV->ItemCount[i] >= item.BarterItemsNum[j] || item.BarterItemsNum[j] == NULL) {
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
			if (item.BarterItems[i] != "") {
				cout << "Item: " << item.BarterItems[i] << " | Quantity: " << item.BarterItemsNum[i] << endl;
			}
		}

		cout << endl;

		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
		return;

	}

	// ----- Remove item quantites -----
	for (int i = 0; i < MAX_ITEMS; i++) {
		for (int j = 0; j < sizeof(item.BarterItems) / sizeof(string); j++) {
			if (item.BarterItems[j] == user->INV->Items[i].name && item.BarterItems[j] != "") {

				// Take away item count
				user->INV->ItemCount[i] -= item.BarterItemsNum[j];

				// If the item count is 0, make the item null (free the slot).
				if (user->INV->ItemCount[i] < 1) {
					user->INV->itemsUsed -= 1;
					user->INV->Items[i] = nullItem;
					break;
				}

			}
		}
	}


	// Find the next available slot for a weapon and put it there.
	// If the item exists already.
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->INV->Items[i].name == item.name) {
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
				user->INV->Items[i] = item;
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
			<< "item: " << item.name << endl;

		for (int i = 0; i < MAX_MATERIALS; i++) {
			if (item.BarterItems[i] != "") {
				cout << "Item: " << item.BarterItems[i] << " | Quantity: " << item.BarterItemsNum[i] << endl;
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
			if (item.BarterItems[i] != "") {
				cout << "Item: " << item.BarterItems[i] << " | Quantity: " << item.BarterItemsNum[i] << endl;
			}
		}

		cout << endl;
	}


	pressAnyButtonToContinue("Press any key to return to the dealer menu...");
	return;
}

string ItemDealer::getDealerBuyChoice(entity* user) {

	int itemChoice = 0;
	int yesNo = 0;
	bool valid = false;
	string strItem = "";

	cout << "Select an item to barter/purchase: " << endl << endl;

	list* item = new list;
	item = getListItems();
	printList(item, 1);

	int size = sizeof(item->names) / sizeof(string);
	for (int i = 0; i < MAX_NUM_FILES; i++) {
		if (item->names[i] == "") {
			size--;
		}
	}
	cout << endl << "Enter : ";
	do {
		cin >> itemChoice;
		checkUserInput();
	} while (itemChoice < 1 || itemChoice > size);

	itemChoice -= 1;

	if (!getItemStats(item->names[itemChoice], user)) {
		return "No";
	} else {
		cout << endl << "Are you sure you want to purchase/barter for " << item->names[itemChoice] << "?" << endl
			<< "1. Yes" << endl
			<< "2. No" << endl
			<< "Enter : ";

		do {
			cin >> yesNo;
			checkUserInput();
			switch (yesNo) {
			case 1:
				valid = true;
				return item->names[itemChoice];
				break;
			case 2:
				valid = true;
				return "No";
				break;
			itemault:
				valid = false;
				break;

			}
		} while (!valid);

		cleanObj(item);
	}

}

void ItemDealer::printDealerOptions() {
	cout << "Select an option: " << endl
		<< "1. Buy" << endl
		<< "2. Sell" << endl
		<< "3. Barter" << endl
		<< "4. Display Inventory" << endl
		<< "5. Back" << endl
		<< "Enter : ";
}

bool ItemDealer::getItemStats(string strItem, entity* user) {

	system("cls");

	printDealerHeader(user);

	cout << endl << "Stats: " << endl;

	int barterCost = 0;
	item ite;
	ite = get_Item(strItem);

	if (ite.failed != GOOD) {
		ErrorLog("Failed to get item stats - Module: Economy", "Severe");
		cout << "Failed to get item stats." << endl << endl;
		return false;
	} else {
		cout << endl << "item: " << strItem << endl
			<< "Value: " << ite.value << endl << endl;

		cout << "Items to barter: " << endl;

		for (int i = 0; i < MAX_MATERIALS; i++) {
			if (ite.BarterItems[i] != "") {
				item bItem;
				bItem = get_Item(ite.BarterItems[i]);

				if (bItem.failed != GOOD) {
					ErrorLog("Failed to get item for stats - Module: Economy", "Critical");
					cout << "Error retrieving barter Item(s)" << endl;
					pressAnyButtonToContinue("");
					return false;
				}
				cout << "Item: " << ite.BarterItems[i] << "\tQuantity: " << ite.BarterItemsNum[i] << "\tValue: " << bItem.value << endl;
				barterCost += bItem.value * ite.BarterItemsNum[i];
			}
		}

		cout << endl << "Total cost to barter: " << barterCost << endl;

	}

}
