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

void WeaponDealer::buy(user* user) {

	system("cls");

	// If the user's inventory is full, return.
	if (user->inv->itemsUsed == MAX_ITEMS) {
		cout << "You already have " << MAX_ITEMS << " in your inventory, consider selling some items to make space for purchases." << endl;
		pressAnyButtonToContinue("");
		return;
	}

	weapon weap;
	bool exists = false;

	string strWeap = getDealerBuyChoice();

	if (strWeap == "No") {
		pressAnyButtonToContinue("");
		return;
	} else {
		// weapon weap = getWeapon(strWeap);
	}

	// If the weapon condition fails, errorlog, return.
	if (weap.failed != GOOD) {
		//ErrorLog("An error has occured while getting a weapon", "Medium");
		cout << "An error has occured while getting a weapon" << endl;
		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
		return;
	}

	if (strWeap == "Sword") {
		weap.value = 125;
		weap.name = "IronSword";
	} else if (strWeap == "Bow") {
		weap.value = 225;
		weap.name = "Bow";
	} else if (strWeap == "Axe") {
		weap.value = 500;
		weap.name = "Axe";
	} else {
		cout << "A problem has occured" << endl;
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
		if (user->inv->Weapons[i].name == weap.name) {
			user->inv->itemCount[i]++;
			user->inv->itemsUsed++;
			exists = true;
			break;
		}
	}

	// If the item does not exist already.
	if (exists == false) {
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (user->inv->itemCount[i] == NULL) {
				user->inv->Weapons[i] = weap;
				user->inv->itemCount[i]++;
				user->inv->itemsUsed++;
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

void WeaponDealer::sell(user* user) {

	system("cls");

	weapon nullWeap;

	int choice;
	cout << "Here is a list of your weapons, please select one to sell: " << endl;
	cout << "0. Back" << endl;

	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->inv->Weapons[i].name != "") {
			cout << i + 1 << ". " << user->inv->Weapons[i].name 
				<< " (Quantity = " << user->inv->itemCount[i] << ") valued at " 
				<< user->inv->Weapons[i].value << "." << endl;
		}
	}

	cin >> choice;
	
	if (choice == 0) {
		return;
	}

	choice -= 1;

	if (this->balance < user->inv->Weapons[choice].value) {
		cout << "The dealer does not have enough gold to purchase that item from you." << endl;
		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
		return;
	}

	if (user->inv->itemCount[choice] >= 1) {

		if (user->inv->itemsUsed >= 1) {
			user->gold += user->inv->Weapons[choice].value;
			this->balance -= user->inv->Weapons[choice].value;

			system("cls");

			cout << "Weapon: " << user->inv->Weapons[choice].name
				<< " has been sold for "
				<< user->inv->Weapons[choice].value
				<< " gold." << endl;

			
			user->inv->itemsUsed -= 1;
			user->inv->itemCount[choice] -= 1;

			if (user->inv->itemCount[choice] == 0) {
				user->inv->Weapons[choice] = nullWeap;
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

void WeaponDealer::barter(user* user) {
	
	system("cls");

	// If the user's inventory is full, return.
	if (user->inv->itemsUsed == MAX_ITEMS) {
		cout << "You already have " << MAX_ITEMS << " in your inventory, consider selling some items to make space for purchases." << endl;
		pressAnyButtonToContinue("");
		return;
	}

	item nullItem;
	bool validAmountItems[MAX_MATERIALS] = { false };
	weapon weap;
	bool exists = false;
	bool allValid = true;

	string strWeap = getDealerBuyChoice();

	if (strWeap == "No") {
		pressAnyButtonToContinue("");
		return;
	} else {
		// weapon weap = getWeapon(strWeap);
	}

	// If the weapon condition fails, errorlog, return.
	if (weap.failed != GOOD) {
		//ErrorLog("An error has occured while getting a weapon", "Medium");
		cout << "An error has occured while getting a weapon" << endl;
		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
		return;
	}

	if (strWeap == "Sword") {
		weap.value = 125;
		weap.name = "IronSword";

		weap.BarterItems[0] = "wood";
		weap.BarterItems[1] = "iron";
		weap.BarterItems[2] = "";

		weap.BarterItemNum[0] = 1;
		weap.BarterItemNum[1] = 2;
		weap.BarterItemNum[2] = 0;
		
	} else if (strWeap == "Bow") {
		weap.value = 225;
		weap.name = "Bow";

		weap.BarterItems[0] = "wood";
		weap.BarterItems[1] = "";
		weap.BarterItems[2] = "iron";

		weap.BarterItemNum[0] = 2;
		weap.BarterItemNum[1] = NULL;
		weap.BarterItemNum[2] = 1;


	} else if (strWeap == "Axe") {
		weap.value = 500;
		weap.name = "Axe";

		weap.BarterItems[0] = "wood";
		weap.BarterItems[1] = "iron";
		weap.BarterItems[2] = "";

		weap.BarterItemNum[0] = 3;
		weap.BarterItemNum[1] = 3;
		weap.BarterItemNum[2] = 0;

	} else {
		cout << "A problem has occured" << endl;
		return;
	}

	// ----- Check if user has correct amount of items -----
	for (int i = 0; i < MAX_ITEMS; i++) {
		for (int j = 0; j < sizeof(weap.BarterItems) / sizeof(string); j++) {
			if (weap.BarterItems[i] == user->inv->Items[j].name) {
				// If they have more or equal to the amount || if the item is null (user needs none)
				if (user->inv->itemCount[i] >= weap.BarterItemNum[j] || weap.BarterItemNum[j] == NULL) {
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

	if (allValid == false) {
		cout << "You are missing items to complete the trade!" << endl << endl;
		cout << "Your Items: " << endl;
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (user->inv->Items[i].name != "") {
				cout << "Item: " << user->inv->Items[i].name << " | Quantity: " << user->inv->itemCount[i] << endl;
			}
		}
		cout << endl;
		cout << "Required Items: " << endl;
		for (int i = 0; i < MAX_MATERIALS; i++) {
			if (weap.BarterItems[i] != "") {
				cout << "Item: " << weap.BarterItems[i] << " | Quantity: " << weap.BarterItemNum[i] << endl;
			}
		}

		cout << endl;

		pressAnyButtonToContinue("Press any key to return to the dealer menu...");
		return;

	}
	
	// ----- Remove item quantites -----
	for (int i = 0; i < MAX_ITEMS; i++) {
		for (int j = 0; j < sizeof(weap.BarterItems) / sizeof(string); j++) {
			if (weap.BarterItems[i] == user->inv->Items[j].name && weap.BarterItems[i] != "") {
				
				// Take away item count
				user->inv->itemCount[i] -= weap.BarterItemNum[j];
				user->inv->itemsUsed -= weap.BarterItemNum[j];
		
				// If the item count is 0, make the item null (free the slot).
				if (user->inv->itemCount[i] < 1) {
					user->inv->Items[i] = nullItem;
					break;
				} 

			}
		}
	}


	// Find the next available slot for a weapon and put it there.

	// If the item exists already.
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (user->inv->Weapons[i].name == weap.name) {
			user->inv->itemCount[i]++;
			user->inv->itemsUsed++;
			exists = true;
			break;
		}
	}

	// If the item does not exist already.
	if (exists == false) {
		for (int i = 0; i < MAX_ITEMS; i++) {
			if (user->inv->itemCount[i] == NULL) {
				user->inv->Weapons[i] = weap;
				user->inv->itemCount[i]++;
				user->inv->itemsUsed++;
				break;
			}
		}
	}

	system("cls");

	cout << "You have successfully bartered the following materials for:" << endl
		<< "Weapon: " << weap.name << endl;

	for (int i = 0; i < MAX_MATERIALS; i++) {
		if (weap.BarterItems[i] != "") {
			cout << "Item: " << weap.BarterItems[i] << " | Quantity: " << weap.BarterItemNum[i] << endl;
		}
	} 

	exists = false;

	pressAnyButtonToContinue("Press any key to return to the dealer menu...");
	return;
}

string WeaponDealer::getDealerBuyChoice() {


	int itemChoice = 0;
	int yesNo = 0;
	bool valid = false;
	string strWeap = "";

	cout << "Select an item to barter/purchase: " << endl << endl;

	
	/*list* weapons = getListWeapons();
	printList(weapons, 1);

	cin >> itemChoice;

	cleanObj(weapons);

	getItemStats(weapons->names[choice]);

	cout << endl << "Are you sure you want to purchase/barter for " << weapons->names[choice] << "?" << endl
		 << "1. Yes" << endl
		 << "2. No" << endl;

	do {
		cin >> yesNo;
		checkUserInput();
		switch (yesNo) {
		case 1:
			valid = true;
			return weapons->names[choice];
			break;
		case 2:
			valid = true;
			return "No";
			break;
		default:
			valid = false;
			break;

		}
	} while (!valid);*/

	

	cout << "1. Sword" << endl
		 << "2. Bow" << endl
		 << "3. Axe" << endl
		 << "4. Back" << endl;

	cin >> itemChoice;

	switch (itemChoice) {
	case 1:
		strWeap = "Sword";
		break;
	case 2:
		strWeap = "Bow";
		break;
	case 3:
		strWeap = "Axe";
		break;
	case 4: break;
	default:
		cout << "please select a valid item" << endl;
		break;
	}

	return strWeap;
}

void WeaponDealer::printDealerOptions() {
	cout << "Select an option: " << endl
		<< "1. Buy" << endl
		<< "2. Sell" << endl
		<< "3. Barter" << endl
		<< "4. Display Inventory" << endl
		<< "5. Back" << endl;
}

void WeaponDealer::getItemStats(string strWeap) {
	
	int barterCost = 0;
	weapon weap;
	//weap = getWeapon(strWeap);

	if (weap.failed != GOOD) {
		//ErrorLog("Failed to get weapon stats", "Medium");
		cout << "Failed to get weapon stats." << endl << endl;
		return;
	} else {
		cout << "Weapon: " << strWeap << endl
			<< "Damage: " << weap.damage << endl
			<< "Level: " << weap.level << endl
			<< "Value: " << weap.value << endl << endl;

		cout << "Items to barter: " << endl;
		
		for (int i = 0; i < MAX_MATERIALS; i++) {
			if (weap.BarterItems[i] != "") {
				item bItem;
				//bItem = getItem(weap.BarterItems[i]);

				if (bItem.failed != GOOD) {
					//ErrorLog("Failed to get item for stats - Module: Economy", "Critical")
					cout << "Error retrieving barter Item(s)" << endl;
					pressAnyButtonToContinue("");
					return;
				}
				cout << "Item: " << weap.BarterItems[i] << "\tValue: " << bItem.value << endl;
				barterCost += bItem.value;
			}
		}

		cout << endl << "Total cost to barter: " << barterCost << endl;

	}

}
