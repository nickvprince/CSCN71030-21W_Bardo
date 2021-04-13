/*
* File Name: PotionDealer.cpp
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

//#include "PotionDealer.h"
//
//PotionDealer::PotionDealer() : Dealer() {
//	this->name = "Daemon";
//	this->balance = 10000;
//}
//
//void PotionDealer::printDealerInfo() {
//	cout << "Dealer Name: " << this->name << endl
//		<< "Dealer Balance: " << this->balance << endl;
//}
//
//string PotionDealer::getName() {
//	return this->name;
//}
//
//int PotionDealer::getDealerBalance() {
//	return this->balance;
//}
//
//void PotionDealer::buy(entity* user) {
//
//	system("cls");
//
//	// If the user's inventory is full, return.
//	if (user->INV->itemsUsed == MAX_ITEMS) {
//		cout << "You already have " << MAX_ITEMS << " in your inventory, consider selling some items to make space for purchases." << endl;
//		pressAnyButtonToContinue("");
//		return;
//	}
//
//	bool exists = false;
//
//	string strPot = getDealerBuyChoice(user);
//
//	if (strPot == "No") {
//		pressAnyButtonToContinue("");
//		return;
//	}
//
//	potion pot = get_Potion(strPot);
//
//
//	// If the potion condition fails, errorlog, return.
//	if (pot.failed != GOOD) {
//		ErrorLog("An error has occured while getting a potion", "Medium");
//		cout << "An error has occured while getting a potion" << endl;
//		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
//		return;
//	}
//
//	if (user->gold < pot.value) {
//		cout << "You do not have enough gold to purchase that item." << endl;
//		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
//		return;
//	}
//
//	user->gold -= pot.value;
//	this->balance += pot.value;
//
//	// If the item exists already.
//	for (int i = 0; i < MAX_ITEMS; i++) {
//		if (user->INV->Potions[i].name == pot.name) {
//			user->INV->ItemCount[i]++;
//			exists = true;
//			break;
//		}
//	}
//
//	// If the item does not exist already.
//	if (exists == false) {
//		for (int i = 0; i < MAX_ITEMS; i++) {
//			if (user->INV->ItemCount[i] == NULL || user->INV->ItemCount[i] == EMPTY) {
//				user->INV->Potions[i] = pot;
//				user->INV->ItemCount[i]++;
//				user->INV->itemsUsed++;
//				break;
//			}
//		}
//	}
//
//	system("cls");
//
//	cout << "potion: " << pot.name
//		<< " has been purchased for "
//		<< pot.value << " gold." << endl << endl;
//
//
//	exists = false;
//
//	pressAnyButtonToContinue("Press any key to return to the dealer menu...");
//	return;
//}
//
//void PotionDealer::sell(entity* user) {
//
//	system("cls");
//
//	potion nullPot;
//
//	nullPot.name = "";
//	nullPot.value = 0;
//	nullPot.failed = GOOD;
//	nullPot.level = 0;
//
//	for (int i = 0; i < MAX_MATERIALS; i++) {
//		nullPot.BarterItems[i] = "";
//		nullPot.BarterItemsNum[i] = 0;
//		nullPot.craftingItems[i] = "";
//		nullPot.craftingItemsNum[i] = 0;
//	}
//
//	int choice;
//	cout << "Here is a list of your potions, please select one to sell: " << endl;
//	cout << "0. Back" << endl;
//
//	for (int i = 0; i < MAX_ITEMS; i++) {
//		if (user->INV->Potions[i].name != "") {
//			cout << i + 1 << ". " << user->INV->Potions[i].name
//				<< " (Quantity = " << user->INV->ItemCount[i] << ") valued at "
//				<< user->INV->Potions[i].value << "." << endl;
//		}
//	}
//	cout << endl << "Enter : ";
//	cin >> choice;
//	checkUserInput();
//
//	if (choice == 0) {
//		return;
//	}
//
//	choice -= 1;
//
//	if (this->balance < user->INV->Potions[choice].value) {
//		cout << "The dealer does not have enough gold to purchase that item from you." << endl;
//		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
//		return;
//	}
//
//	if (user->INV->ItemCount[choice] >= 1) {
//
//		if (user->INV->itemsUsed >= 1) {
//			user->gold += user->INV->Potions[choice].value;
//			this->balance -= user->INV->Potions[choice].value;
//
//			system("cls");
//
//			cout << "potion: " << user->INV->Potions[choice].name
//				<< " has been sold for "
//				<< user->INV->Potions[choice].value
//				<< " gold." << endl << endl;
//
//
//			user->INV->ItemCount[choice] -= 1;
//
//			if (user->INV->ItemCount[choice] == 0) {
//				user->INV->itemsUsed -= 1;
//				user->INV->Potions[choice] = nullPot;
//			}
//
//		} else {
//			cout << "A Problem Has Occured." << endl;
//		}
//
//	} else {
//		cout << "There is nothing to sell there." << endl;
//	}
//
//	pressAnyButtonToContinue("Press any key to return to the dealer menu...");
//	return;
//}
//
//void PotionDealer::barter(entity* user) {
//
//	system("cls");
//
//	// If the user's inventory is full, return.
//	if (user->INV->itemsUsed == MAX_ITEMS) {
//		cout << "You already have " << MAX_ITEMS << " in your inventory, consider selling some items to make space for purchases." << endl;
//		pressAnyButtonToContinue("");
//		return;
//	}
//
//	item nullItem;
//
//	nullItem.name = "";
//	nullItem.failed = GOOD;
//	nullItem.value = 0;
//	for (int i = 0; i < MAX_MATERIALS; i++) {
//		nullItem.BarterItems[i] = "";
//		nullItem.BarterItemsNum[i] = 0;
//	}
//
//	potion pot;
//	bool namesEmpty[MAX_ITEMS] = { true };
//	bool allNamesEmpty = true;
//	bool validAmountItems[MAX_MATERIALS] = { false };
//	bool allValid = true;
//	bool exists = false;
//	bool complete = false;
//	int index = 0;
//
//	string strPot = getDealerBuyChoice(user);
//
//	if (strPot == "No") {
//		pressAnyButtonToContinue("");
//		return;
//	} else {
//		pot = get_Potion(strPot);
//	}
//
//	// If the potion condition fails, errorlog, return.
//	if (pot.failed != GOOD) {
//		ErrorLog("An error has occured while getting a potion - Module: Economy", "Medium");
//		cout << "An error has occured while getting a potion" << endl;
//		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
//		return;
//	}
//
//	// If the user doesn't have any items
//	for (int i = 0; i < MAX_ITEMS; i++) {
//		if (user->INV->Items[i].name == "") {
//			namesEmpty[i] = true;
//		}
//	}
//
//	// If no items are full
//	for (int i = 0; i < MAX_ITEMS; i++) {
//		if (namesEmpty[i] == false) {
//			allNamesEmpty = false;
//		}
//	}
//
//
//	// ----- Check if user has correct amount of items -----
//	for (int i = 0; i < MAX_ITEMS; i++) {
//		for (int j = 0; j < sizeof(pot.BarterItems) / sizeof(string); j++) {
//			if (pot.BarterItems[i] == user->INV->Items[j].name) {
//				// If they have more or equal to the amount || if the item is null (user needs none)
//				if (user->INV->ItemCount[i] >= pot.BarterItemsNum[j] || pot.BarterItemsNum[j] == NULL) {
//					validAmountItems[j] = true;
//				}
//			}
//		}
//	}
//
//	// ----- Check make sure that the user has the correct amount for ALL items (errorCheck) -----
//
//	for (int i = 0; i < MAX_MATERIALS; i++) {
//		if (validAmountItems[i] != true) {
//			allValid = false;
//		}
//	}
//
//	if (allValid == false || allNamesEmpty == true) {
//		system("cls");
//		cout << "You are missing items to complete the trade!" << endl << endl;
//		cout << "Your Items: " << endl;
//		for (int i = 0; i < MAX_ITEMS; i++) {
//			if (user->INV->Items[i].name != "") {
//				cout << "Item: " << user->INV->Items[i].name << " | Quantity: " << user->INV->ItemCount[i] << endl;
//			}
//		}
//		cout << endl;
//		cout << "Required Items: " << endl;
//		for (int i = 0; i < MAX_MATERIALS; i++) {
//			if (pot.BarterItems[i] != "") {
//				cout << "Item: " << pot.BarterItems[i] << " | Quantity: " << pot.BarterItemsNum[i] << endl;
//			}
//		}
//
//		cout << endl;
//
//		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
//		return;
//
//	}
//
//	// ----- Remove item quantites -----
//	for (int i = 0; i < MAX_ITEMS; i++) {
//		for (int j = 0; j < sizeof(pot.BarterItems) / sizeof(string); j++) {
//			if (pot.BarterItems[j] == user->INV->Items[i].name && pot.BarterItems[j] != "") {
//
//				// Take away item count
//				user->INV->ItemCount[i] -= pot.BarterItemsNum[j];
//
//				// If the item count is 0, make the item null (free the slot).
//				if (user->INV->ItemCount[i] < 1) {
//					user->INV->itemsUsed -= 1;
//					user->INV->Items[i] = nullItem;
//					break;
//				}
//
//			}
//		}
//	}
//
//
//	// Find the next available slot for a potion and put it there.
//	// If the item exists already.
//	for (int i = 0; i < MAX_ITEMS; i++) {
//		if (user->INV->Potions[i].name == pot.name) {
//			user->INV->ItemCount[i]++;
//			exists = true;
//			complete = true;
//			break;
//		}
//	}
//
//	// If the item does not exist already.
//	if (exists == false) {
//		for (int i = 0; i < MAX_ITEMS; i++) {
//			if (user->INV->ItemCount[i] == NULL) {
//				user->INV->Potions[i] = pot;
//				user->INV->ItemCount[i]++;
//				user->INV->itemsUsed++;
//				complete = true;
//				break;
//			}
//		}
//	}
//
//	system("cls");
//
//	if (complete == true) {
//		cout << "You have successfully bartered the following materials for:" << endl
//			<< "potion: " << pot.name << endl;
//
//		for (int i = 0; i < MAX_MATERIALS; i++) {
//			if (pot.BarterItems[i] != "") {
//				cout << "Item: " << pot.BarterItems[i] << " | Quantity: " << pot.BarterItemsNum[i] << endl;
//			}
//		}
//
//		exists = false;
//	} else {
//		cout << "You are missing items to complete the trade!" << endl << endl;
//		cout << "Your Items: " << endl;
//		for (int i = 0; i < MAX_ITEMS; i++) {
//			if (user->INV->Items[i].name != "") {
//				cout << "Item: " << user->INV->Items[i].name << " | Quantity: " << user->INV->ItemCount[i] << endl;
//			}
//		}
//		cout << endl;
//		cout << "Required Items: " << endl;
//		for (int i = 0; i < MAX_MATERIALS; i++) {
//			if (pot.BarterItems[i] != "") {
//				cout << "Item: " << pot.BarterItems[i] << " | Quantity: " << pot.BarterItemsNum[i] << endl;
//			}
//		}
//
//		cout << endl;
//	}
//
//
//	pressAnyButtonToContinue("Press any key to return to the dealer menu...");
//	return;
//}
//
//string PotionDealer::getDealerBuyChoice(entity* user) {
//
//	int itemChoice = 0;
//	int yesNo = 0;
//	bool valid = false;
//	string strPot = "";
//
//	cout << "Select an item to barter/purchase: " << endl << endl;
//
//	list* potion = new list;
//	potion = getListPotions();
//	printList(potion, 1);
//
//	int size = sizeof(potion->names) / sizeof(string);
//	for (int i = 0; i < MAX_NUM_FILES; i++) {
//		if (potion->names[i] == "") {
//			size--;
//		}
//	}
//	cout << endl << "Enter : ";
//	do {
//		cin >> itemChoice;
//		checkUserInput();
//	} while (itemChoice < 1 || itemChoice > size);
//
//	itemChoice -= 1;
//
//	if (!getItemStats(potion->names[itemChoice], user)) {
//		return "No";
//	} else {
//		cout << endl << "Are you sure you want to purchase/barter for " << potion->names[itemChoice] << "?" << endl
//			<< "1. Yes" << endl
//			<< "2. No" << endl
//			<< "Enter : ";
//
//		do {
//			cin >> yesNo;
//			checkUserInput();
//			switch (yesNo) {
//			case 1:
//				valid = true;
//				return potion->names[itemChoice];
//				break;
//			case 2:
//				valid = true;
//				return "No";
//				break;
//			potault:
//				valid = false;
//				break;
//
//			}
//		} while (!valid);
//
//		cleanObj(potion);
//	}
//
//}
//
//void PotionDealer::printDealerOptions() {
//	cout << "Select an option: " << endl
//		<< "1. Buy" << endl
//		<< "2. Sell" << endl
//		<< "3. Barter" << endl
//		<< "4. Display Inventory" << endl
//		<< "5. Back" << endl
//		<< "Enter : ";
//}
//
//bool PotionDealer::getItemStats(string strPot, entity* user) {
//
//	system("cls");
//
//	printDealerHeader(user);
//
//	cout << endl << "Stats: " << endl;
//
//	int barterCost = 0;
//	potion pot;
//	pot = get_Potion(strPot);
//
//	if (pot.failed != GOOD) {
//		ErrorLog("Failed to get potion stats - Module: Economy", "Severe");
//		cout << "Failed to get potion stats." << endl << endl;
//		return false;
//	} else {
//		cout << endl << "potion: " << strPot << endl
//			//<< "Level: " << pot.level << endl
//			<< "Value: " << pot.value << endl << endl;
//
//		cout << "Items to barter: " << endl;
//
//		for (int i = 0; i < MAX_MATERIALS; i++) {
//			if (pot.BarterItems[i] != "") {
//				item bItem;
//				bItem = get_Item(pot.BarterItems[i]);
//
//				if (bItem.failed != GOOD) {
//					ErrorLog("Failed to get item for stats - Module: Economy", "Critical");
//					cout << "Error retrieving barter Item(s)" << endl;
//					pressAnyButtonToContinue("");
//					return false;
//				}
//				cout << "Item: " << pot.BarterItems[i] << "\tQuantity: " << pot.BarterItemsNum[i] << "\tValue: " << bItem.value << endl;
//				barterCost += bItem.value * pot.BarterItemsNum[i];
//			}
//		}
//
//		cout << endl << "Total cost to barter: " << barterCost << endl;
//
//	}
//
//}
