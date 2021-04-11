
#include "SkillTree.h"
#include <iostream>
int input = 0;
bool Skilltree(user& player) {
	while(true) {
		if (player.skillpoints <= 0) { // if player has no skill points to spend
			cout << "You have no skill points to allocate... press any button to return to main menu..."; // Replace this with the press button to continue helper function
			// press any key to continue
		}
		print_options(player);
		// clear Buffer here
		input = getc(stdin); // Needs to be fixed to check for a char or string input
		switch (input) {
		case 49:
			player.Skills[0]++;
			break;
		case 50:
			player.Skills[1]++;
			break;
		case 51:
			player.Skills[2]++;
			break;
		case 52:
			return true;
			break;
		default:
			cout << "Invalid input detected please select a valid skill...";
			// ErrorLog("Default triggered in main skill tree", "Minimal");
			break;

		}
	}
	return true;
}

void print_options(user& player) {
	system("cls");
	cout << "Welcome to skill tree. Each skill point increases a buff by one.\n However, for health it increases by 5%... Choose wisely." << endl << endl;
	cout << "You have " << player.skillpoints <<" points choose a skill to allocate a point..." << endl << endl;
	cout << "1. Health " << player.Skills[0] << "\t\t Total Health : " << player.health << endl;
	cout << "2. Armour " << player.Skills[1] << "\t\t Total armour : " << player.defence << endl;
	cout << "3. Damage " << player.Skills[2] << "\t\t Total damage : " << player.damage << endl;
	cout << "4. Return";
	cout << "\nEnter: ";
}