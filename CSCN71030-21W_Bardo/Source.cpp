#define _CRT_SECURE_NO_WARNINGS
/*
* File Name : Main.cpp
*
* Programmer : Danny Smith
* Class : Team Based Software Development CSCN71030-21W-SEC1-PROJECT 2
* Date : February 6, 2021
* Teacher : Dr. Elliott Coleshill
* Team : Dominic Pham, Thomas Horvath, Nicholas, Prince, Ali Syed
*
* Description : Main.cpp used to test the functionality of file IO
*
*
* Version : 1.0
*
*
* History :
*    ReadMe File Created, IronSword weapon test file created
*
* Revision Ideas -
*    FileIO as threads to do the workload while other operations are running
*/



using namespace std;
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include "BattleModule.h"


// temp
bool skillMain(entity* Player);
bool crafting(entity* player);
bool shopMain(entity* Player);

bool shopMain(entity* Player) {
	return false;
}
bool crafting(entity* player) {
	return false;
}
bool skillMain(entity* Player) {
	return false;
}
// temp




void printOptions();
int main(int argc, char* argv[]) {

	entity* Player = new user;
	if (argc == 1) {
		Player = startIO(Player);
	}
	if (argc >= 2)
	{
		string cmdInput = argv[1];
		if (cmdInput == "0") {
			Player = newGame();
		}         else if (cmdInput == "1")
		{
			Player = get_User("User");

			bool checkLoader = loadScreen(Player);
			if (checkLoader == false)
			{
				Player = newGame();
			}


		}
	}


	int choice = 0;
	// <- INIT

	while (true) {
		system("cls");
		printStats(Player);
		printOptions();
		while ((getchar()) != '\n');
		choice = getc(stdin);
		switch (choice) {
		case 49: // 1
			if (battleMain(*Player) == false) {
				ErrorLog("Battle Fail", "Severe");
			}
			break;
		case 50: // 2
			if (shopMain(Player) == false) {
				ErrorLog("Shop failed", "Severe");
			}
			break;
		case 51: // 3
			if (crafting(Player) == false) {
				ErrorLog("Crafting failed", "Severe");
			}
			break;
		case 52: // 4
			if (skillMain(Player) == false) {
				ErrorLog("Skill Main failed", "Severe");
			}
			break;
		case 53:
			if (Save(Player) == false) {
				ErrorLog("Save Error", "Severe");
			}
			break;
		case 54: // 5
			if (Save(Player) == false) {
				ErrorLog("Save Error", "Severe");
			}
			exit(0);
			break;
		default:
			break;

		}
		while ((getchar()) != '\n');
	}

}


void printOptions() {
	cout << "Welcome to the Bardo home town please choose an option\n";
	cout << "-------------------------------------------------------\n";
	cout << endl;
	cout << "1. Battle\n";
	cout << "2. Shop\n";
	cout << "3. Forge\n";
	cout << "4. Skill tree\n";
	cout << "5. Save Game\n";
	cout << "6. Exit\n";
	cout << "Enter : ";
}

