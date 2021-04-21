#define _CRT_SECURE_NO_WARNINGS

#include "FileIO.h"
#include <fstream>
#include <iostream>
#include <direct.h>
#include <ctime>

using namespace std;

/*
* File Name : FileIO.cpp
*
* Programmer : Danny Smith
* Class : Team Based Software Development CSCN71030-21W-SEC1-PROJECT 2
* Date : February 6, 2021
* Teacher : Dr. Elliott Coleshill
* Team : Dominic Pham, Thomas Horvath, Nicholas, Prince, Ali Syed
*
* Description :
*
*
* Version : 1.2
*
*
* History :
*	Functions created but left empty
*	new file creation, length of file, file exists, and create directory functionality added and completed
*	testing void pointer to check if an error has arisen and if not return object
* 	isFileGood Written
*	get_Weapon version 1 finished without comments
*   get_Weapon version 1.1 finished without comments
*/

// directories
#define SPELLSDIR "./GameFiles/Spells/"
#define POTIONSDIR "./GameFiles/Potions/"
#define WEAPONDIR "./GameFiles/Weapons/"
#define DEFENCEDIR "./GameFiles/Armour/"
#define ITEMDIR "./GameFiles/Items/"
#define INVENTORYDIR "./GameFiles/Inventory/"
#define ENEMYDIR "./GameFiles/Enemy/"
#define USERDIR "./GameFiles/UserFiles/"
string ERRORLOG = "./GameFiles/ErrorLog.txt";


// longest line in a given file
#define WORD_SIZE 15

// equivelent to null
#define Empty 0x00000000CDCDCDCD




// used in file verification
int checkSums[] = { 1,16,16,16,16,14,14,14,14,26,26,26,26,16,1,1,1,1,1,0,1,1,0,0,0,1,0,0,5,679,45,30,1249,18,2,24,33,27,22,45,19 };
string checkSumNames[] = { "Scroll","WoodSword.BWPF","WoodAxe.BWPF","WoodMace.BWPF","WoodBow.BWPF","IronSword.BWPF","IronAxe.BWPF","IronMace.BWPF","IronBow.BWPF","GoldSword.BWPF","GoldAxe.BWPF","GoldMace.BWPF","GoldBow.BWPF","PlatinumStaff.BWPF","BabyDragon.BINVF","DarkElf.BINVF","Drough.BINVF","Elliott.BINVF","Orc.BINVF","Copper.BITMF","Gold.BITMF","Iron.BITMF","Leather.BITMF","Magnesium.BITMF","Paper.BITMF","Platinum.BITMF","Silver.BITMF","Water.BITMF","BabyDragon.BENF","DarkElf.BENF","Drough.BENF","Elliott.BENF","Orc.BENF","GoldArmour.BAMF","GoldShield.BAMF","IronArmour.BAMF","IronShield.BAMF","WoodShield.BAMF","WoodArmour.BAMF","PlatinumShield.BAMF","PlatinumArmour.BAMF" };
string Directories[] = { ITEMDIR,WEAPONDIR,WEAPONDIR,WEAPONDIR ,WEAPONDIR ,WEAPONDIR ,WEAPONDIR ,WEAPONDIR ,WEAPONDIR ,WEAPONDIR ,WEAPONDIR ,WEAPONDIR ,WEAPONDIR ,WEAPONDIR,INVENTORYDIR ,INVENTORYDIR ,INVENTORYDIR ,INVENTORYDIR ,INVENTORYDIR,ITEMDIR,ITEMDIR,ITEMDIR,ITEMDIR,ITEMDIR,ITEMDIR,ITEMDIR,ITEMDIR,ITEMDIR,ENEMYDIR,ENEMYDIR,ENEMYDIR,ENEMYDIR,ENEMYDIR,DEFENCEDIR,DEFENCEDIR,DEFENCEDIR,DEFENCEDIR,DEFENCEDIR,DEFENCEDIR,DEFENCEDIR,DEFENCEDIR };

// used in file reading
fstream file;

/*
* TO ADD TO A FILE
* increment CRAFTING_MATERIAL_START + 1
* add the next case number after the highest case number with the code required atoi(word) returns 0 if chars are in the word and the int if input is a number ( retrieval--; to stay in the case for as long as needed )
* Decrypt the file
* add the word or values required on seperate lines in the file seperated by ; if EOL or & if EOF when the file is in plain text NOT cipher text
* Encrypt the file
* change the checksum value of the encrypted version of the file in the checksums[] in comparison to that file in the checkSumNames[]
*/
weapon get_Weapon(string name) { // retrieves a weapon from a file and returns it as an object

#define CRAFTING_MATERIAL_START 3
	int length = 0;
	char input;
	int itemPosition = 0;
	int retrieval = 0;
	char word[WORD_SIZE];
	fstream file;

	int counter = 0;
	weapon Weapon;
	Weapon.name = name;
	int SWITCH = 0;
	int barterPosition = 0;
	name = name + ".BWPF";
	DECRYPT(WEAPONDIR+name);
	switch (isFileGood((char*)name.c_str())) { // is the file passed usable
	case CHK_FAIL: // weapon fail state set to checksum fail
		Weapon.failed = CHK_FAIL;
		ErrorLog("Checksum Fail", "Low");
		break;
	case EXISTS_FAIL: // weapon fail state set to file not exists fail
		Weapon.failed = EXISTS_FAIL;
		ErrorLog("Exists Fail", "Average");
		break;
	case GOOD: // file is usable start reading
		for (int i = 0; i < MAX_MATERIALS; i++) {
			Weapon.BarterItemsNum[i] = 0;
			Weapon.craftingItemsNum[i] = 0;
		}
		
		Weapon.failed = GOOD;
		file.open(WEAPONDIR + (string)name, ios::in);
		if (file.is_open()) {


			file >> input;

			// get info ->
			while (input != 38) {

				while (input != 59 && input != 38) {
					word[counter] = input;
					counter++;

					file >> input;
				}
				// debugging and seeing each word >
				//cout << "WORD : " << word << "\n";

				switch (retrieval) {
				case 0:

					Weapon.damage = atoi(word);
					break;
				case 1:
					Weapon.value = atoi(word);
					break;
				case 2:
					Weapon.level = atoi(word);
					break;

				case (CRAFTING_MATERIAL_START + 1):
					if (SWITCH == 0) {
						Weapon.craftingItemsNum[itemPosition] = atoi(word);
						itemPosition++;
						retrieval--;
						SWITCH++;
					} 					else {
						Weapon.BarterItemsNum[barterPosition] = atoi(word);
						retrieval = CRAFTING_MATERIAL_START - 1;
						barterPosition++;
						SWITCH--;
					}
					break;
				default:

					if (atoi(word) == 0) {
						if (SWITCH == 0) {
							Weapon.craftingItems[itemPosition] = word;
							retrieval--;
							SWITCH++;
						} 						else {
							Weapon.BarterItems[barterPosition] = word;
							SWITCH--;
						}
					} 					else {
						Weapon.failed = COMMON_FAIL;
						ENCRYPT(WEAPONDIR + name);
						return Weapon;
					}

				}
				retrieval++;
				counter = 0;

				for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
					word[emptyCounter] = '\0';
				}

				file >> input;

			}
			// get info  < -

		} // if is open
		break;
	default: // all other fails
		Weapon.failed = COMMON_FAIL;
		ErrorLog("Unkown Fail", "High");
		break;
	}

	file.close();
	ENCRYPT(WEAPONDIR + name);
	return Weapon;
} // just takes in name of file not the dir
// been updated for bartering ^


defence get_Defence(string name) { // retrieves a defence item from a file and returns it as an object
	int length = 0;
	char input;
	int itemPosition = 0;
	int retrieval = 0;
	char word[WORD_SIZE];
	fstream file;
	int counter = 0;
	defence Defence;
#define CRAFTING_MATERIAL_START 4
	int SWITCH = 0;
	int barterPosition = 0;
	Defence.name = name;
	name = name + ".BAMF";
	DECRYPT(DEFENCEDIR + name);
	switch (isFileGood((char*)name.c_str())) { // is the file passed usable
	case CHK_FAIL: // weapon fail state set to checksum fail
		Defence.failed = CHK_FAIL;
		ErrorLog("Checksum Fail", "Low");
		break;
	case EXISTS_FAIL: // weapon fail state set to file not exists fail
		Defence.failed = EXISTS_FAIL;
		ErrorLog("Exists Fail", "Average");
		break;
	case GOOD: // file is usable start reading
		for (int i = 0; i < MAX_MATERIALS; i++) {
			Defence.BarterItemsNum[i] = 0;
			Defence.craftingItemsNum[i] = 0;
		}
		Defence.failed = GOOD;
		file.open(DEFENCEDIR + (string)name, ios::in);
		if (file.is_open()) {


			file >> input;

			// get info ->
			while (input != 38) {

				while (input != 59 && input != 38) {
					word[counter] = input;
					counter++;

					file >> input;
				}
				// debugging and seeing each word >
				//cout << "WORD : " << word << "\n";

				switch (retrieval) {
				case 0:
					Defence.blockChance = atoi(word);
					break;
				case 1:
					Defence.Defence = atoi(word);
					break;
				case 2:
					Defence.value = atoi(word);
					break;
				case 3:
					Defence.level = atoi(word);
					break;
				case (CRAFTING_MATERIAL_START + 1):
					if (SWITCH == 0) {
						Defence.craftingItemsNum[itemPosition] = atoi(word);
						SWITCH++;
						retrieval--;
						itemPosition++;

					} 					else {
						Defence.BarterItemsNum[barterPosition] = atoi(word);
						SWITCH--;
						barterPosition++;
						retrieval = CRAFTING_MATERIAL_START - 1;
					}
					
					
					break;
				default:

					if (atoi(word) == 0) {
						if (SWITCH == 0) {
							Defence.craftingItems[itemPosition] = word;
							retrieval--;
							
							SWITCH++;
						} 					
						else {
							Defence.BarterItems[barterPosition] = word;
						
							SWITCH--;
						}
					} 					
					else {
						Defence.failed = COMMON_FAIL;
						ENCRYPT(DEFENCEDIR + name);
						return Defence;
					}

				}
				retrieval++;
				counter = 0;

				for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
					word[emptyCounter] = '\0';
				}

				file >> input;

			}
			// get info  < -

		} // if is open
		break;
	default: // all other fails
		Defence.failed = COMMON_FAIL;
		ErrorLog("Unknown Fail", "High");
		break;
	}

	file.close();
	ENCRYPT(DEFENCEDIR + name);
	return Defence;
}

// Needs updating for bartering ^
item get_Item(string name) {
	int length = 0;
	char input;
	int itemPosition = 0;
	int retrieval = 0;
	char word[WORD_SIZE];
	fstream file;
	int counter = 0;
	item ITEM;
	fstream FILE;

	


	ITEM.name = name;
	name = name + ".BITMF";

	// reset word
	for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
		word[emptyCounter] = '\0';
	}
	counter = 0;
	// reset word before reading item
	DECRYPT(ITEMDIR + name);
	switch (isFileGood((char*)name.c_str())) { // is the file passed usable
	case CHK_FAIL: // weapon fail state set to checksum fail
		ITEM.failed = CHK_FAIL;
		ErrorLog("Checksum Fail", "Low");
		break;
	case EXISTS_FAIL: // weapon fail state set to file not exists fail
		ITEM.failed = EXISTS_FAIL;
		ErrorLog("File Exists Fail", "Average");
		break;
	case GOOD: // file is usable start reading
		for (int i = 0; i < MAX_MATERIALS; i++) {
			ITEM.BarterItemsNum[i] = 0;
		
		}
		ITEM.failed = GOOD;
		FILE.open(ITEMDIR + (string)name, ios::in);
		if (FILE.is_open()) {


			FILE >> input;

			// get info ->
			while (input != 38) {

				while (input != 59 && input != 38) {
					word[counter] = input;
					counter++;

					FILE >> input;
				}
				// debugging and seeing each word >
				//cout << "WORD : " << word << "\n";

				switch (retrieval) {
				case 0:
					ITEM.value = atoi(word);
					break;
				default:
					ITEM.failed = COMMON_FAIL;
					return ITEM;
					break;
				}
				retrieval++;
				counter = 0;

				for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
					word[emptyCounter] = '\0';
				}

				FILE >> input;

			}
			// get info  < -

		} // if is open
		break;
	default: // all other fails
		ITEM.failed = COMMON_FAIL;
		ErrorLog("Unknown Fail", "High");
		break;
	}
	// Reset variables without resetting item count
	length = 0;
	input = ' ';
	retrieval = 0;
	word[WORD_SIZE];
	counter = 0;
	// Reset variables without resetting item count
	FILE.close();

	ENCRYPT(ITEMDIR + name);
	return ITEM;
}

potion get_Potion(string name) { // retrieves a potion from a file and returns it as an object

	int length = 0;
	char input;
	int itemPosition = 0;
	int retrieval = 0;
	char word[WORD_SIZE];
	fstream FILE;
	int counter = 0;
	potion ITEM;
#define CRAFTING_MATERIAL_START 2

	int barterPosition = 0;
	int SWITCH = 0;

	ITEM.name = name;
	name = name + ".BPTN";

	// reset word
	for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
		word[emptyCounter] = '\0';
	}
	counter = 0;
	// reset word before reading item
	DECRYPT(POTIONSDIR + name);
	switch (isFileGood((char*)name.c_str())) { // is the file passed usable
	case CHK_FAIL: // weapon fail state set to checksum fail
		ITEM.failed = CHK_FAIL;
		ErrorLog("Checksum Fail", "Low");
		break;
	case EXISTS_FAIL: // weapon fail state set to file not exists fail
		ITEM.failed = EXISTS_FAIL;
		ErrorLog("File Exists Fail", "Average");
		break;
	case GOOD: // file is usable start reading
		for (int i = 0; i < MAX_MATERIALS; i++) {
			ITEM.BarterItemsNum[i] = 0;

		}
		
		ITEM.failed = GOOD;
		FILE.open(POTIONSDIR + (string)name, ios::in);
		if (FILE.is_open()) {
			

			FILE >> input;

			// get info ->
			while (input != 38) {

				while (input != 59 && input != 38) {
					word[counter] = input;
					counter++;
					
					FILE >> input;
				}
				// debugging and seeing each word >
				//cout << "WORD : " << word << "\n";
				//cout << "Retreival : " << retrieval << "\n";
				switch (retrieval) {
				case 0:
					ITEM.value = atoi(word);
					break;
				case 1:
					ITEM.Power = atoi(word);
					break;
				case (CRAFTING_MATERIAL_START + 1):
					if (SWITCH == 0) {
						ITEM.craftingItemsNum[itemPosition] = atoi(word);
						SWITCH++;
						retrieval--;
						itemPosition++;

					}
					else {
						ITEM.BarterItemsNum[barterPosition] = atoi(word);
						SWITCH--;
						barterPosition++;
						retrieval = CRAFTING_MATERIAL_START - 1;
					}


					break;
				default:

					if (atoi(word) == 0) {
						if (SWITCH == 0) {
							ITEM.craftingItems[itemPosition] = word;
							retrieval--;

							SWITCH++;
						}
						else {
							ITEM.BarterItems[barterPosition] = word;

							SWITCH--;
						}
					}
					else {
						ITEM.failed = COMMON_FAIL;
						DECRYPT(POTIONSDIR + name);
						return ITEM;
					}
					break;
				}
					retrieval++;
					counter = 0;

					for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
						word[emptyCounter] = '\0';
					}

					FILE >> input;

				}
				// get info  < -

			} // if is open
			break;
	default: // all other fails
		ITEM.failed = COMMON_FAIL;
		ErrorLog("Unknown Fail", "High");
		break;
		}
		// Reset variables without resetting item count
		length = 0;
		input = ' ';
		retrieval = 0;
		word[WORD_SIZE];
		counter = 0;
		// Reset variables without resetting item count
		FILE.close();

		DECRYPT(POTIONSDIR + name);
		return ITEM;

}




void ErrorLog(string message, string Severity) {
	
		fstream f;
		time_t now = time(0);
		tm* time = gmtime(&now);
		f.open(ERRORLOG, ios::app);
	f << message << " | Severity : " << Severity << " 2021" << "/" << time->tm_mon << "/" << time->tm_mday << " " << (time->tm_hour) - 4 << ":" << time->tm_min << ":" << time->tm_sec << "EST" << endl;
		f.close();
	
}

spell get_Spell(string name) { // retrieves a spell from a file and returns it as an object
	spell Spell;
	// Item called scroll
	return Spell;
}



inventory* get_Inventory(string name) { // retrieves inventory from a file and returns it as an object
	inventory* Inventory = new inventory;
	for (int i = 0; i < MAX_ITEMS; i++) {
		Inventory->ItemCount[i] = 0;
	
	}
	int length = 0;
	char input;
	int itemPosition = 0;
	int retrieval = 0;
	char word[WORD_SIZE];
	fstream file;
	int counter = 0;
	int  type = '\0'; // I = item W = Weapon P = potion D = defence
	name = name + ".BINVF";
	// reset word
	for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
		word[emptyCounter] = '\0';
	}
	counter = 0;
	// reset word before reading item
	DECRYPT(INVENTORYDIR + name);
	switch (isFileGood((char*)name.c_str())) { // is the file passed usable
	case CHK_FAIL: // weapon fail state set to checksum fail
		Inventory->failed = CHK_FAIL;
		ErrorLog("Checksum Fail", "Low");
		break;
	case EXISTS_FAIL: // weapon fail state set to file not exists fail
		Inventory->failed = EXISTS_FAIL;
		ErrorLog("Exists Fail", "Average");
		break;
	case GOOD: // file is usable start reading

		Inventory->failed = GOOD;
		file.open(INVENTORYDIR + (string)name, ios::in);
		if (file.is_open()) {


			file >> input;
			//cout << input;
			// get info ->
			while (input != 38) {

				while (input != 59 && input != 38) {
					word[counter] = input;
					counter++;
					//cout << input;
					file >> input;

				}
				// debugging and seeing each word >
				//cout << word;
				//cout << "R : "<<retrieval;
				switch (retrieval) {
				case 0:

					if (strcmp(word, "Item") == 0) {
						type = 'I';
					} 					else if (strcmp(word, "Weapon") == 0) {
						type = 'W';
					} 					else if (strcmp(word, "Defence") == 0) {
						type = 'D';
					} 					else if (strcmp(word, "Potion") == 0) {
						type = 'P';
					}
					break;
				case 2:
					//cout << " here2 ";
					Inventory->ItemCount[itemPosition] = atoi(word);
					itemPosition++;
					retrieval = -1;
					break;
				case 1:


					if (atoi(word) == 0) {

						if (type == 'I') {
							item ITEM = get_Item(word);
							Inventory->Items[itemPosition] = ITEM;
							Inventory->itemsUsed++;
						} 						else if (type == 'W') {
							weapon Weapon = get_Weapon(word);
							Inventory->Weapons[itemPosition] = Weapon;
							Inventory->itemsUsed++;
						} 						else if (type == 'D') {
							defence shield = get_Defence(word);
							Inventory->Shields[itemPosition] = shield;
							Inventory->itemsUsed++;
						} 						else if (type == 'P') {
							potion POTION = get_Potion(word);
							Inventory->Potions[itemPosition] = POTION;
							Inventory->itemsUsed++;
						}

					} 					else {
						Inventory->failed = COMMON_FAIL;
						ErrorLog("Unknown Inventory type", "Average");
						ENCRYPT(INVENTORYDIR + name);
						return Inventory;
					}
					break;
				default:
					ErrorLog("Default Triggered in Inventory", "High");
					break;
				}
				retrieval++;
				counter = 0;

				for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
					word[emptyCounter] = '\0';
				}

				file >> input;

			}
			// get info  < -

		} // if is open
		break;
	default: // all other fails
		Inventory->failed = COMMON_FAIL;
		ErrorLog("Unknown Fail", "High");
		break;
	}
	file.close();
	ENCRYPT(INVENTORYDIR + name);
	return Inventory;
}



entity* get_User(string name) { // retrieves user information from a file and returns it as an object
	
	entity* User = new user;
	
	fstream userFile;
	User->race = name;
	User->INV = get_Inventory(name);
	name = name + ".BSURF";
	char WORD[WORD_SIZE];
	int caseNumber = 0;
	char readInput = '\0';
	int NEWCOUNTER = 0;
	
	for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
		WORD[emptyCounter] = '\0';
	}
	DECRYPT(USERDIR + name);
	switch (isFileGood((char*)name.c_str())) { // is the file passed usable
	case CHK_FAIL: // weapon fail state set to checksum fail
		User->failed = CHK_FAIL;
		ErrorLog("Checksum Fail", "Low");
		break;
	case EXISTS_FAIL: // weapon fail state set to file not exists fail
		User->failed = EXISTS_FAIL;
		ErrorLog("File Exists Fail", "Average");
		break;
	case GOOD: // file is usable start reading

		User->failed = GOOD;
		userFile.open(USERDIR + (string)name, ios::in);
		if (userFile.is_open()) {


			userFile >> readInput;

			// get info ->
			while (readInput != 38) {

				while (readInput != 59 && readInput != 38) {
					WORD[NEWCOUNTER] = readInput;
					NEWCOUNTER++;

					userFile >> readInput;
				}
				// debugging and seeing each word >
				//cout << "WORD : " << WORD << "\n";

				switch (caseNumber) {
				case 0:
					User->name = WORD;
					break;
				case 1:
					User->Weapon = get_Weapon(WORD);
					break;
				case 2:
					User->damage = atoi(WORD);
				case 3:
					//defence health level exp
					User->defence = atoi(WORD);
					break;
				case 4:
					User->health = atoi(WORD);
					break;
				case 5:
					User->level = atoi(WORD);
					break;
				case 6:
					User->currentexp = atoi(WORD);
					break;
				case 7:
					User->expmax = atoi(WORD);
					break;
				case 8:
					User->gold = atoi(WORD);
					break;
				case 9:
					User->Shield = get_Defence(WORD);
					break;
				case 10:
					User->Skills[0] = atoi(WORD);
					break;
				case 11:
					User->Skills[1] = atoi(WORD);
					break;
				case 12:
					User->Skills[2] = atoi(WORD);
					break;
				default:

					ErrorLog("Default triggered in get User", "High");
					break;
				}
				for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
					WORD[emptyCounter] = '\0';
				}
				caseNumber++;
				NEWCOUNTER = 0;
				userFile >> readInput;
			}
			// get info  < -

		} // if is open
		break;
	default: // all other fails
		User->failed = COMMON_FAIL;
		break;
	}
	for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
		WORD[emptyCounter] = '\0';
	}
	userFile.close();
	ENCRYPT(USERDIR + name);
	User->skillpoints = User->level - (User->Skills[0] + User->Skills[1] + User->Skills[2]);
	return User;
}

// data structures were getting so large that enemies and inventory need to be kept on the heap.
// Stress testing 50 enemies created made a memory increase from 920KB to 4MB then deleting them reduced memory back to 1.5MB
void cleanObj(entity* obj) { // removes an entity and its inventory from heap
	delete(obj->INV);
	delete(obj);
}
void cleanObj(list* list) {
	delete(list->names);
	delete(list);
}

enemy* get_Enemy(string name, int level) { // retrieves an enemy from a file and returns it as an object

	enemy* Enemy = new enemy;
	fstream enemy_File;
	Enemy->race = name;
	Enemy->INV = get_Inventory(name);
	name = name + ".BENF";
	char WORD[WORD_SIZE];
	int caseNumber = 0;
	char readInput = '\0';
	int NEWCOUNTER = 0;

	for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
		WORD[emptyCounter] = '\0';
	}
	DECRYPT(ENEMYDIR + name);
	switch (isFileGood((char*)name.c_str())) { // is the file passed usable
	case CHK_FAIL: // weapon fail state set to checksum fail
		Enemy->failed = CHK_FAIL;
		ErrorLog("Checksum Fail", "Low");
		break;
	case EXISTS_FAIL: // weapon fail state set to file not exists fail
		Enemy->failed = EXISTS_FAIL;
		ErrorLog("File Exists Fail", "Average");
		break;
	case GOOD: // file is usable start reading

		Enemy->failed = GOOD;
		enemy_File.open(ENEMYDIR + (string)name, ios::in);
		if (enemy_File.is_open()) {


			enemy_File >> readInput;

			// get info ->
			while (readInput != 38) {

				while (readInput != 59 && readInput != 38) {
					WORD[NEWCOUNTER] = readInput;
					NEWCOUNTER++;

					enemy_File >> readInput;
				}
				// debugging and seeing each word >
				//cout << "WORD : " << WORD << "\n";

				switch (caseNumber) {
				case 0:
					Enemy->name = WORD;
					break;
				case 1:
					Enemy->Weapon = get_Weapon(WORD);
					break;
				case 2:
					//defence health level exp
					Enemy->defence = (atoi(WORD) * level) / 2;
					break;
				case 3:
					Enemy->health = (atoi(WORD) * level) / 2;
					break;
				case 4:
					Enemy->level = level;
					break;
				case 5:
					Enemy->currentexp = (atoi(WORD) * level) / 2;
					break;
				case 6:
					Enemy->gold = (atoi(WORD) * level) / 2;
					break;
				case 7:
					Enemy->Shield = get_Defence(WORD);
					break;
				default:
					ErrorLog("Default Triggered in get enemy", "High");
					break;
				}
				for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
					WORD[emptyCounter] = '\0';
				}
				caseNumber++;
				NEWCOUNTER = 0;
				enemy_File >> readInput;
			}
			// get info  < -

		} // if is open
		break;
	default: // all other fails
		Enemy->failed = COMMON_FAIL;
		ErrorLog("Unknown Fail", "High");
		break;
	}
	for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
		WORD[emptyCounter] = '\0';
	}
	enemy_File.close();
	ENCRYPT(ENEMYDIR + name);
	return Enemy;
}


bool FileExists(string name) { // checks if file exists
	fstream f;
	f.open(name, ios::in);
	
	
	if (!f.is_open()) {
		return false;
		ErrorLog("File Doesnt Exist (FileExists)", "Unknown");
	} 	else {
		return true;
	}
}



int lengthOfFile(char* name) { // length of file in bytes ( used for checksum
	fstream file;
	char input;
	int counter = 0;
	file.open(name, ios::in);
	file >> input;
	while (input != '&') {
		counter++;
		file >> input;
	}
	counter++;
	file.close();
	return counter;
}


bool createFile(char* name) { // create file
	fstream file;
	file.open(name, ios::out);
	file.close();
	return FileExists(name);

}


bool createDirectory(char* name) { // create directory
	switch (_mkdir(name)) {
	case 0:
		return true;
		break;
	default:
		ErrorLog("Could not create Directory", "Unknown");
		return false;
	}
}

ErrorType isFileGood(char* name) { // does checking if file is good							NEEDS REVISION
	return GOOD;
#define INVENTORYDIR "./GameFiles/Inventory/"
#define USERDIR "./GameFiles/UserFiles/"
	int flag = 1;
	string exemptDirectories[] = { USERDIR,INVENTORYDIR,INVENTORYDIR,INVENTORYDIR,INVENTORYDIR,INVENTORYDIR,INVENTORYDIR };
	string exemptFiles[] = { "USER.BSURF","DarkElf.BINVF","USER.BINVF","BabyDragon.BINVF","Drough.BINVF","Elliott.BINVF","Orc.BINVF" };

	for (int exempt = 0; exempt < sizeof(exemptFiles) / sizeof(string); exempt++) { // temporary exempt files from checksum ( files that change frequently ) until i get a better method of doing checksum
		if (exemptFiles[exempt] == name) {
		
		
			string path = exemptDirectories[exempt] + name;
		
			if (FileExists(path) == 0) {
		
				return EXISTS_FAIL; // directory not exist fail
				ErrorLog("Exist Fail Triggered in isFileGood", "Unknown");
				flag++;
			} 			
			else {
			
				return GOOD;
			}
		}
	}

	/*if (flag == 1) {
	
		for (int i = 0; i < sizeof(checkSumNames) / sizeof(string); i++) {
		
			if (name == checkSumNames[i]) {
				string dec = Directories[i] + checkSumNames[i];
				cout << dec << endl;
				DECRYPT(dec);
				getc(stdin);
				if (getCheckSum(Directories[i] + checkSumNames[i]) == checkSums[i]) {
					ENCRYPT(dec);
					return GOOD;
				} 				
				else {
					ENCRYPT(dec);
					return CHK_FAIL;
					ErrorLog("Checksum Triggered in isFileGood " + checkSumNames[i] + " ", "Low");
				}
			}
		}
	}*/
}

bool removeDirectory(char* name) { // remove directory
	switch (_rmdir(name)) {
	case 0:
		return true;
		break;
	default:
		ErrorLog("Remove Directory Fail", "Unknown");
		return false;
	}
}


void printList(list* list, int type) {
	for (int i = 0; i < MAX_NUM_FILES; i++) {

		if (list->names[i] == "") {
			return;
		} 		else {
			if (type == 0) {
				cout << list->names[i] << endl;
			} 			else {
				cout << i + 1 << ". " << list->names[i] << endl;
			}
		}

	}
}
list* getListWeapons() {
	list* names = new list;
	fstream file;
	char input;
	int location = 0;
	int counter = 0;
	char word[WORD_SIZE];
	for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
		word[emptyCounter] = '\0';
	}
	file.open(WEAPONDIR + (string)"list.txt", ios::in);
	if (file.is_open()) {


		file >> input;

		// get info ->
		while (input != 38) {

			while (input != 59 && input != 38) {
			
				word[counter] = input;
				counter++;

				file >> input;
			}
			names->names[location] = word;
			location++;
			for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
				word[emptyCounter] = '\0';
			}
			counter = 0;

			file >> input;
		}
	}
	return names;
}
list* getListDefences() {
	list* names = new list;
	fstream file;
	char input;
	int location = 0;
	int counter = 0;
	char word[WORD_SIZE];
	for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
		word[emptyCounter] = '\0';
	}
	file.open(DEFENCEDIR + (string)"list.txt", ios::in);
	if (file.is_open()) {


		file >> input;

		// get info ->
		while (input != 38) {

			while (input != 59 && input != 38) {

				word[counter] = input;
				counter++;

				file >> input;
			}
			names->names[location] = word;
			location++;
			for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
				word[emptyCounter] = '\0';
			}
			counter = 0;

			file >> input;
		}
	}
	return names;
}
list* getListItems() {
	list* names = new list;
	fstream file;
	char input;
	int location = 0;
	int counter = 0;
	char word[WORD_SIZE];
	for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
		word[emptyCounter] = '\0';
	}
	file.open(ITEMDIR + (string)"list.txt", ios::in);
	if (file.is_open()) {


		file >> input;

		// get info ->
		while (input != 38) {

			while (input != 59 && input != 38) {

				word[counter] = input;
				counter++;

				file >> input;
			}
			names->names[location] = word;
			location++;
			for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
				word[emptyCounter] = '\0';
			}
			counter = 0;

			file >> input;
		}
	}
	return names;
}
list* getListPotions() {
	list* names = new list;
	fstream file;
	char input;
	int location = 0;
	int counter = 0;
	char word[WORD_SIZE];
	for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
		word[emptyCounter] = '\0';
	}
	file.open(POTIONSDIR + (string)"list.txt", ios::in);
	if (file.is_open()) {


		file >> input;

		// get info ->
		while (input != 38) {

			while (input != 59 && input != 38) {

				word[counter] = input;
				counter++;

				file >> input;
			}
			names->names[location] = word;
			location++;
			for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
				word[emptyCounter] = '\0';
			}
			counter = 0;

			file >> input;
		}
	}
	return names;
}
list* getListSpells() {
	list* names = new list;
	fstream file;
	char input;
	int location = 0;
	int counter = 0;
	char word[WORD_SIZE];
	for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
		word[emptyCounter] = '\0';
	}
	file.open(SPELLSDIR + (string)"list.txt", ios::in);
	if (file.is_open()) {


		file >> input;

		// get info ->
		while (input != 38) {

			while (input != 59 && input != 38) {

				word[counter] = input;
				counter++;

				file >> input;
			}
			names->names[location] = word;
			location++;
			for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
				word[emptyCounter] = '\0';
			}
			counter = 0;

			file >> input;
		}
	}
	return names;
}
list* getListEnemy() {
	list* names = new list;
	fstream file;
	char input;
	int location = 0;
	int counter = 0;
	char word[WORD_SIZE];
	for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
		word[emptyCounter] = '\0';
	}
	file.open(ENEMYDIR + (string)"list.txt", ios::in);
	if (file.is_open()) {


		file >> input;

		// get info ->
		while (input != 38) {

			while (input != 59 && input != 38) {

				word[counter] = input;
				counter++;

				file >> input;
			}
			names->names[location] = word;
			location++;
			for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
				word[emptyCounter] = '\0';
			}
			counter = 0;

			file >> input;
		}
	}
	return names;
}
bool Save(entity* Player) {
	fstream file;
	file.open(USERDIR + (string)"USER.BSURF", ios::out);
	if (file.is_open()) {
		file << Player->name << ";" << endl;
		file << Player->Weapon.name << ";" << endl;
		file << Player->damage << ";" << endl;
		file << Player->defence << ";" << endl;
		file << Player->health << ";" << endl;
		file << Player->level << ";" << endl;
		file << Player->currentexp << ";" << endl;
		file << Player->expmax << ";" << endl;
		file << Player->gold << ";" << endl;
		file << Player->Shield.name << ";";
		file << Player->Skills[0] << ";";
		file << Player->Skills[1] << ";";
		file << Player->Skills[2] << "&";
		file.close();
	} 	
	else {
		ErrorLog("File Did not open to save", "Severe");
		ENCRYPT(USERDIR + (string)"USER.BSURF");
		return false;
	}

	
	file.open(INVENTORYDIR + (string)"USER.BINVF", ios::out);
	int flag = 0;
	Player->INV->itemsUsed = 0;
	for (int i = 0; i < MAX_ITEMS; i++){
		if (Player->INV->Weapons[i].name != "" || Player->INV->Shields[i].name != "" || Player->INV->Potions[i].name != ""|| Player->INV->Items[i].name != "") {
			Player->INV->itemsUsed++;
		}
	
	}
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (Player->INV->Weapons[i].name != "") {
			file << "Weapon;" << endl;
			file << Player->INV->Weapons[i].name << ";" << endl;
			if (i == Player->INV->itemsUsed-1) {
				file << Player->INV->ItemCount[i] << "&" << endl;
			}
			else {
				file << Player->INV->ItemCount[i] << ";" << endl;
			}
			flag++;
		}
		if (Player->INV->Shields[i].name != "") {
			file << "Defence;" << endl;
			file << Player->INV->Shields[i].name << ";" << endl;
			if (i == Player->INV->itemsUsed - 1) {
				file << Player->INV->ItemCount[i] << "&" << endl;
			}
			else {
				file << Player->INV->ItemCount[i] << ";" << endl;
			}
			flag++;
		}
		if (Player->INV->Potions[i].name != "") {
			file << "Potion;" << endl;
			file << Player->INV->Potions[i].name << ";" << endl;
			if (i == Player->INV->itemsUsed - 1) {
				file << Player->INV->ItemCount[i] << "&" << endl;
			}
			else {
				file << Player->INV->ItemCount[i] << ";" << endl;
			}
			flag++;
		}
		if (Player->INV->Items[i].name != "") {
			file << "Item;" << endl;
			file << Player->INV->Items[i].name << ";" << endl;
			if (i == Player->INV->itemsUsed - 1) {
				file << Player->INV->ItemCount[i] << "&" << endl;
			}
			else {
				file << Player->INV->ItemCount[i] << ";" << endl;
			}
			flag++;
		}
		if (flag == 0) {
			file << "&";
		}
	}
	file.close();
	ENCRYPT(USERDIR + (string)"USER.BSURF");
	ENCRYPT(INVENTORYDIR + (string)"USER.BINVF");
	return true;

}