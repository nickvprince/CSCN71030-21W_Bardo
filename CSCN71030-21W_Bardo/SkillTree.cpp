/*
* File Name: SkillTree.cpp
*
* Programmer: Nicholas Prince, Danny Smith
* Class: Team Based Software Development CSCN71030-21W-SEC1-PROJECT 2
* Date: March 22, 2021
* Teacher: Dr. Elliott Coleshill
* Team: Dominic Pham, Thomas Horvath, Ali Syed
*
* Module: Skill Tree
*
*/

//#include "OtherFunctions.h"
#include "SkillTree.h"
#include <iostream>
#define HEALTH_PERCENT 0.05
bool Skilltree(user* player) {

	int input = 0;

	cout << "--- Welcome to the Skill Tree ---" << endl << endl;

	while (true) {

		cout << "Would you like to: " << endl
			<< "1. Allocate Skill Points" << endl
			<< "2. Discard a Skill" << endl
			<< "3. Reset All Skills" << endl
			<< "4. View Skills" << endl
			<< "5. Exit." << endl
			<< "Enter : ";
		cin >> input;
		//checkUserInput();
		switch (input) {
		case 1:
			buySkill(player);
			break;
		case 2:
			resetSkill(player);
			break;
		case 3:
			resetAllSkills(player);
			break;
		case 4:
			printSkills(player);
			break;
		case 5:
			return true;
			break;
		default:
			cout << "Invalid input detected please select a valid skill...";// <- replace with press any key to continue function
			// ErrorLog("Default triggered in main skill tree", "Minimal");
			break;

		}
	}
}

void printSkills(user* player) {
	system("cls");
	cout << "You have " << player->skillpoints <<" available skill points." << endl << endl;
	cout << "1. Health " << player->Skills[0] << "\t\t Total Health : " << player->health << endl;
	cout << "2. Armour " << player->Skills[1] << "\t\t Total armour : " << player->defence << endl;
	cout << "3. Damage " << player->Skills[2] << "\t\t Total damage : " << player->damage << endl;
	cout << "4. Return" << endl << endl;
}

void buySkill(user* player) {

	int input = 0;

	while (true) {

		printSkills(player);

		if (player->skillpoints <= 0) { // if player has no skill points to spend
			cout << "You have no skill points to allocate. Press any button to return to main menu. . ."; // Replace this with the press button to continue helper function
			//system("cls");
			return;
		}

		cout << "Each skill point increases a stat by one." << endl
			<< "However, for health it increases by " << (HEALTH_PERCENT * 100) << "%... Choose wisely." << endl << endl;
		cout << "Enter : ";
		cin >> input;
		//checkUserInput();
		switch (input) {
		case 1:
			player->Skills[0]++;
			player->health = player->health * (1 + HEALTH_PERCENT);
			player->skillpoints--;
			break;
		case 2:
			player->Skills[1]++;
			player->defence++;
			player->skillpoints--;
			break;
		case 3:
			player->Skills[2]++;
			player->damage++;
			player->skillpoints--;
			break;
		case 4:
			return;
			break;
		default:
			cout << "Invalid input detected please select a valid skill...";// <- replace with press any key to continue function
			// ErrorLog("Default triggered in main skill tree", "Minimal");
			break;
		}
	}
	return;
}

void resetSkill(user* player) {

	int input = 0;
	bool noSkills[3] = { false };
	bool none = true;

	while (true) {
		// If the user has skills allocated.
		if (!checkSkillsEmpty(player)) {
			printSkills(player);

			cout << "Each skill point decreases a stat by one." << endl
				<< "However, for health it increases by " << (HEALTH_PERCENT * 100) << "%... Choose wisely." << endl << endl;

			cin >> input;
			//checkUserInput();
			switch (input) {
			case 1:
				player->Skills[0]--;
				player->health = player->health / (1 + HEALTH_PERCENT);
				player->skillpoints++;
				break;
			case 2:
				player->Skills[1]--;
				player->defence--;
				player->skillpoints++;
				break;
			case 3:
				player->Skills[2]--;
				player->damage--;
				player->skillpoints++;
				break;
			case 4:
				return;
				break;
			default:
				cout << "Invalid input detected please select a valid skill...";// <- replace with press any key to continue function
				// ErrorLog("Default triggered in main skill tree", "Minimal");
				break;
			}
		} else {
			cout << "You have no skill points allocated. Press any button to return to main menu. . ."; // Replace this with the press button to continue helper function
			return;
		}
	}
	return;
}

void resetAllSkills(user* player) {

	while (true) {

		cout << "Are you sure you want to reset all skills: " << endl
			<< "1. Yes " << endl
			<< "2. No " << endl
			<< "Enter : ";
		int choice = 0;
		cin >> choice;
		//checkUserInput();

		if (choice == 1) {
			int totalPoints = 0;
			int totalAllocated = 0;

			for (int i = 0; i < 3; i++) {
				totalAllocated += player->Skills[i];
			}

			totalPoints = totalAllocated + player->skillpoints;

			int count = player->Skills[0];
			for (int i = 0; i < count; i++) {
				player->Skills[0]--;
				player->health = player->health / (1 + HEALTH_PERCENT);
			}
			count = player->Skills[1];
			for (int i = 0; i < count; i++) {
				player->Skills[1]--;
				player->defence--;
			}
			count = player->Skills[2];
			for (int i = 0; i < count; i++) {
				player->damage--;
				player->skillpoints++;
			}

			for (int i = 0; i < 3; i++) {
				player->Skills[i] = 0;
			}


			player->skillpoints = totalPoints;
			// Press any key to continue("Skills have been reset");
			return;

		} else if (choice == 2) {
			// Press any key to continue("Skills have not been reset");
			return;
		} else {
			cin >> choice;
			//checkUserInput();
		}
	}
}

bool checkSkillsEmpty(user* player) {

	bool noSkills[3] = { false };
	bool none = true;

	for (int i = 0; i < 3; i++) {
		if (player->Skills[i] == 0) {
			noSkills[i] = true;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (noSkills[i] == false) {
			none = false;
		}
	}

	if (none == false) {
		return false;
	} 
	return true;
}