#define _CRT_SECURE_NO_WARNINGS
#include "FileIO.h"
#include <fstream>
#include <iostream>
#include <direct.h>



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
* Version : 1.1
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


#define WEAPONDIR "./GameFiles/Weapons/"
#define DEFENCEDIR "./GameFiles/Armour/"
#define ITEMDIR "./GameFiles/Items/"
#define INVENTORYDIR "./GameFiles/Inventory/"
#define ENEMYDIR "./GameFiles/Enemy/"
#define WORD_SIZE 15

// used in file verification
int checkSums[] = { 3, 5, 5, 0,0,1,1,2 };
string checkSumNames[] = { "IronSword.BWPF", "WoodBow.BWPF","IronShield.BAMF", "Copper.BITMF", "Leather.BITMF","Iron.BITMF", "Orc.BINVF","Orc.BENF" };
string Directories[] = { WEAPONDIR,WEAPONDIR,DEFENCEDIR, ITEMDIR,ITEMDIR ,ITEMDIR, INVENTORYDIR,ENEMYDIR };

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

	name = name + ".BWPF";

	switch (isFileGood((char*)name.c_str())) { // is the file passed usable
	case CHK_FAIL: // weapon fail state set to checksum fail
		Weapon.failed = CHK_FAIL;
		break;
	case EXISTS_FAIL: // weapon fail state set to file not exists fail
		Weapon.failed = EXISTS_FAIL;
		break;
	case GOOD: // file is usable start reading

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

					Weapon.craftingItemsNum[itemPosition] = atoi(word);
					itemPosition++;
					retrieval = CRAFTING_MATERIAL_START - 1;
					break;
				default:

					if (atoi(word) == 0) {
						Weapon.craftingItems[itemPosition] = word;
					}
					else {
						Weapon.failed = COMMON_FAIL;
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
		break;
	}

	file.close();
	return Weapon;
} // just takes in name of file not the dir



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
	Defence.name = name;
	name = name + ".BAMF";

	switch (isFileGood((char*)name.c_str())) { // is the file passed usable
	case CHK_FAIL: // weapon fail state set to checksum fail
		Defence.failed = CHK_FAIL;
		break;
	case EXISTS_FAIL: // weapon fail state set to file not exists fail
		Defence.failed = EXISTS_FAIL;
		break;
	case GOOD: // file is usable start reading

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

					Defence.craftingItemsNum[itemPosition] = atoi(word);
					itemPosition++;
					retrieval = CRAFTING_MATERIAL_START - 1;
					break;
				default:

					if (atoi(word) == 0) {
						Defence.craftingItems[itemPosition] = word;
					}
					else {
						Defence.failed = COMMON_FAIL;
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
		break;
	}

	file.close();
	return Defence;
}

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

	switch (isFileGood((char*)name.c_str())) { // is the file passed usable
	case CHK_FAIL: // weapon fail state set to checksum fail
		ITEM.failed = CHK_FAIL;
		break;
	case EXISTS_FAIL: // weapon fail state set to file not exists fail
		ITEM.failed = EXISTS_FAIL;
		break;
	case GOOD: // file is usable start reading

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


	return ITEM;
}

potion get_Potion(string name) { // retrieves a potion from a file and returns it as an object
	potion Potion;
	return Potion;
}



spell get_Spell(string name) { // retrieves a spell from a file and returns it as an object
	spell Spell;
	return Spell;
}



inventory* get_Inventory(string name) { // retrieves inventory from a file and returns it as an object
	inventory* Inventory = new inventory;
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
	switch (isFileGood((char*)name.c_str())) { // is the file passed usable
	case CHK_FAIL: // weapon fail state set to checksum fail
		Inventory->failed = CHK_FAIL;
		break;
	case EXISTS_FAIL: // weapon fail state set to file not exists fail
		Inventory->failed = EXISTS_FAIL;
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
					}
					else if (strcmp(word, "Weapon") == 0) {
						type = 'W';
					}
					else if (strcmp(word, "Defence") == 0) {
						type = 'D';
					}
					else if (strcmp(word, "Potion") == 0) {
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
						}
						else if (type == 'W') {
							weapon Weapon = get_Weapon(word);
							Inventory->Weapons[itemPosition] = Weapon;
							Inventory->itemsUsed++;
						}
						else if (type == 'D') {
							defence shield = get_Defence(word);
							Inventory->Shields[itemPosition] = shield;
							Inventory->itemsUsed++;
						}
						else if (type == 'P') {
							potion POTION = get_Potion(word);
							Inventory->Potions[itemPosition] = POTION;
							Inventory->itemsUsed++;
						}

					}
					else {
						Inventory->failed = COMMON_FAIL;
						return Inventory;
					}
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
		break;
	}
	file.close();
	return Inventory;
}



user* get_User(string name) { // retrieves user information from a file and returns it as an object
	user* User = new user;
	int length = 0;
	char input;
	int itemPosition = 0;
	int retrieval = 0;
	char word[WORD_SIZE];
	fstream file;
	int counter = 0;


	name = name + ".BSURF";

	switch (isFileGood((char*)name.c_str())) { // is the file passed usable
	case CHK_FAIL: // weapon fail state set to checksum fail
		User->failed = CHK_FAIL;
		break;
	case EXISTS_FAIL: // weapon fail state set to file not exists fail
		User->failed = EXISTS_FAIL;
		break;
	case GOOD: // file is usable start reading

		User->failed = GOOD;
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
					break;
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					break;
				case 7:
					break;
				case 8:
					break;
				case 9:
					break;
				case 10:
					break;
				case 11:
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
		User->failed = COMMON_FAIL;
		break;
	}

	file.close();
	return User;
}
void remove_Enemy(enemy* orc) { // removes an enemy and its inventory from heap

	delete(orc->Droppables);

	delete(orc);

}
// data structures were getting so large that enemies and inventory need to be kept on the heap.
// Stress testing 50 enemies created made a memory increase from 920KB to 4MB then deleting them reduced memory back to 1.5MB
enemy* get_Enemy(string name) { // retrieves an enemy from a file and returns it as an object

	enemy* Enemy = new enemy;
	fstream enemy_File;
	Enemy->race = name;
	Enemy->Droppables = get_Inventory(name);
	name = name + ".BENF";
	char WORD[WORD_SIZE];
	int caseNumber = 0;
	char readInput = '\0';
	int NEWCOUNTER = 0;

	for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
		WORD[emptyCounter] = '\0';
	}
	switch (isFileGood((char*)name.c_str())) { // is the file passed usable
	case CHK_FAIL: // weapon fail state set to checksum fail
		Enemy->failed = CHK_FAIL;
		break;
	case EXISTS_FAIL: // weapon fail state set to file not exists fail
		Enemy->failed = EXISTS_FAIL;
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
					Enemy->defence = atoi(WORD);
					break;
				case 3:
					Enemy->health = atoi(WORD);
					break;
				case 4:
					Enemy->level = atoi(WORD);
					break;
				case 5:
					Enemy->exp = atoi(WORD);
					break;
				case 6:
					Enemy->Shield = get_Defence(WORD);
					break;
				default:
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
		break;
	}
	for (int emptyCounter = 0; emptyCounter < WORD_SIZE; emptyCounter++) {
		WORD[emptyCounter] = '\0';
	}
	enemy_File.close();

	return Enemy;
}



void write_User_To_File(string name) { // writes user information to their files

}


bool FileExists(string name) { // checks if file exists
	fstream f;
	f.open(name, ios::in);
	f.close();
	if (!file) {
		return false;
	}
	else {
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
		return false;
	}
}

ErrorType isFileGood(char* name) { // does checking if file is good
	return GOOD;
	string exemptDirectories[] = { "./GameFiles/Inventory/","./GameFiles/Inventory/","./GameFiles/UserFiles/","./GameFiles/UserFiles/","./GameFiles/UserFiles/" };
	string exemptFiles[] = { "UserIN.BINVF","UserOUT.BINVF","Settings.BSET","USER.BSURF","UserData.BDF" };
	for (int exempt = 0; exempt < sizeof(exemptFiles) / sizeof(string); exempt++) { // temporary exempt files from checksum ( files that change frequently ) until i get a better method of doing checksum
		if (exemptFiles[exempt] == name) {
			string path = exemptDirectories[exempt] + name;
			if (FileExists(path) == 0) {
				return EXISTS_FAIL; // directory not exist fail
			}
			else {
				return GOOD;
			}
		}
	}



	int found = 0; // used to see if the file was found in the hardcoded list

	for (int counter = 0; counter < sizeof(checkSumNames); counter++) {
		if (checkSumNames[counter] == name) { // if name provided is found in the hardcoded file list
			found++;
			string path = Directories[counter] + name;
			if (FileExists(path) == 0) {
				return EXISTS_FAIL; // directory not exist fail
			}
			else if (Checksum(path, checkSums[counter]) == 0) { // if checksum is wrong from that identified at the top of the file
				return CHK_FAIL;
			}

		}

	}
	if (found == 1) { // found the file and didnt fail
		return GOOD;
	}
	else if (found == 0) { // didnt find the file
		return EXISTS_FAIL;
	}
	else { // something went wrong return common error
		return COMMON_FAIL;
	}
	return COMMON_FAIL; // just in case code breaks
}

bool removeDirectory(char* name) { // remove directory
	switch (_rmdir(name)) {
	case 0:
		return true;
		break;
	default:
		return false;
	}
}



