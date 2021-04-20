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

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <windows.h>
#include "seeInventory.h"

void credits();
void credits1();
void credits2();
void credits3();
void credits4();
void credits5();

void printOptions();

int main(int argc, char* argv[]) {
	credits();

	//DECRYPT("./GameFiles/UserFiles/User.BSURF");
	//ENCRYPT("./GameFiles/Inventory/User.BINVF");
	entity* Player = new user;
	if (argc == 1) {
		Player = startIO(Player);
	}
	if (argc >= 2)
	{
		string cmdInput = argv[1];
		if (cmdInput == "0") {
			Player = newGame();
		} else if (cmdInput == "1")
		{
			Player = get_User("USER");

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
		//printStats(Player);
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
			if (Crafting(Player) == false) {
				ErrorLog("Crafting failed", "Severe");
			}
			break;
		case 52: // 4
			if (Skilltree(Player) == false) {
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
		case 55:
			credits();
			break;
		default:
			break;

		}

	}
}
void credits() {
	credits1();
	credits2();
	credits3();
	credits4();
	credits5();
}
void credits1() {

	int slash = 92;

	system("cls");

	cout << "  _____           _      _    _     ____                _       " << endl
		<< " |  __ " << (char)slash << "         (_)    | |  | |   |  _ " << (char)slash << "              | |      " << endl
		<< " | |__) | __ ___  _  ___| | _| |_  | |_) | __ _ _ __ __| | ___  " << endl
		<< " |  ___/ '__/ _ " << (char)slash << "| |/ _ " << (char)slash << " |/ / __| |  _ < / _` | '__/ _` |/ _ " << (char)slash << " " << endl
		<< " | |   | | | (_) | |  __/   <| |_  | |_) | (_| | | | (_| | (_) |" << endl
		<< " |_|   |_|  " << (char)slash << "___/| |" << (char)slash << "___|_|=" << (char)slash << "_"  << "" << (char)slash << "__| |____/ " << (char)slash << "__,_|_|  " << (char)slash << "__,_|" << (char)slash << "___/ " << endl
		<< "                _/ |                                            " << endl
		<< "               |__/                                             " << endl << endl;

	Sleep(3500);
	cout << "What is Projekt Bardo?" << endl;
	Sleep(2000);
	cout << "Console-Based RPG game" << endl;
	Sleep(2000);
	cout << "There Are 6 Modules" << endl << endl;
	Sleep(2000);
	cout << "The Game Includes:" << endl;
	Sleep(1250);
	cout << "\tTurn Based Battle" << endl;
	Sleep(1250);
	cout << "\tA Skill Tree" << endl;
	Sleep(1250);
	cout << "\tAn Economy" << endl;
	Sleep(1250);
	cout << "\tThe Ability to Craft Items" << endl;
	Sleep(1250);
	cout << "\tCharacter Creation and Personalization" << endl;
	Sleep(1250);
	cout << "\tFile IO Dependancy" << endl;
	Sleep(1250);
	cout << "\tMultiple Items And Weapons" << endl << endl;
	Sleep(750);
	pressAnyButtonToContinue("");
	return;

}
void credits2() {
	int slash = 92;
	system("cls");
	cout << "  _______       ___" << endl;
	cout << " |__   __|      | |" << endl;
	cout << "    | | ___  ___| |__ __" << endl;
	cout << "    | |/ _ " << (char)slash << "/ __| __/ __| " << endl;
	cout << "    | |  __/" << (char)slash << "__ " << (char)slash << " |_" << (char)slash << "__ " << (char)slash << " " << endl;
	cout << "    |_|" << (char)slash << "___||___/" << (char)slash << "__|___/ " << endl << endl;
	Sleep(2500);
	cout << "Total number of tests: 55" << endl;
	Sleep(1500);
	cout << "Passed tests: 49" << endl;
	Sleep(1500);
	cout << "Failed tests: 6" << endl;
	Sleep(1500);
	cout << "Pass rate: 89.10%" << endl;
	Sleep(1500);
	cout << "Fail rate: 10.90%" << endl << endl;
	Sleep(750);
	pressAnyButtonToContinue("");
	return;
}
void credits3()
{
	int i = 91;
	printf("  _____                             \n");
	printf(" |_   _|                            \n");
	printf("   | |  ___ ___ _   _  ___  ___     \n");
	printf("   | | / __/ __| | | |/ _ %c/ __|    \n", i);
	printf("  _| |_%c__ %c__ %c |_| |  __/%c__ %c    \n", i, i, i, i, i);
	printf(" |_____|___/___/%c__,_|%c___||___/    \n", i, i);

	printf("\nThe main issues were as follows:\n");
	printf("1. The player would heal when the enemies would attack them. \nThis was due to the damage value being less than the defence stat of the player and the damage going into the negatives.\n\n");
	printf("2. Get weapons had poorly formatted data files which led to cascading issues.\n\n");
	printf("3. Get defence did not increment a variable that was cruicial to its function. \n\n");
	printf("4. Merge errors that led us to take much more time than needed for integration.\n\n");
	printf("5. As seen earlier we had 2219 errors after merging which had to be sorted out but they turned out to be mostly include errors.\n");

	pressAnyButtonToContinue("");
	system("cls");

	printf("  _____                           ______ _              _ \n");
	printf(" |_   _|                         |  ____(_)            | |\n");
	printf("   | |  ___ ___ _   _  ___  ___  | |__   ___  _____  __| |\n");
	printf("   | | / __/ __| | | |/ _ %c/ __| |  __| | %c %c/ / _ %c/ _` |\n", i, i, i, i);
	printf("  _| |_%c__ %c__ %c |_| |  __/%c__ %c | |    | |>  <  __/ (_| |\n", i, i, i, i, i);
	printf(" |_____|___/___/%c__,_|%c___||___/ |_|    |_/_/%c_%c___|%c__,_|\n", i, i, i, i, i);

	printf("\nIn the end everything ended up passing.\n\n");
	printf("To fix these we had an excessively 11 and a half hour call re-analyzing algorithms and fixing and merging all that was left.\n\n\n");

	pressAnyButtonToContinue("");

}
void credits4() {
}
void credits5() {
	system("cls");
	int Slash = 92;
	cout << "  _____       _                     _   _               ______         _" << endl;
	cout << " |_   _|     | |                   | | (_)             |  ____|       | |                      "<<endl;
	cout << "   | |  _ __ | |_ ___ _ __ ___  ___| |_ _ _ __   __ _  | |__ ___  __ _| |_ _   _ _ __ ___  ___ " << endl;
	cout << "   | | | '_ "<<(char)Slash<<"| __/ _ " << (char)Slash << " '__/ _ " << (char)Slash << "/ __| __| | '_ " << (char)Slash << " / _` | |  __/ _ " << (char)Slash << "/ _` | __| | | | '__/ _ " << (char)Slash << "/ __|" << endl;
	cout << "  _| |_| | | | ||  __/ | |  __/" << (char)Slash << "__ " << (char)Slash << " |_| | | | | (_| | | | |  __/ (_| | |_| |_| | | |  __/" << (char)Slash << "__ " << (char)Slash << "" << endl;
	cout << " |_____|_| |_|" << (char)Slash << "__" << (char)Slash << "___|_|  " << (char)Slash << "___||___/" << (char)Slash << "__|_|_| |_|" << (char)Slash << "__, | |_|  " << (char)Slash << "___|" << (char)Slash << "__,_|" << (char)Slash << "__|" << (char)Slash << "__,_|_|  " << (char)Slash << "___||___/" << endl;
	cout << "                                                 __/ |                                         " << endl;
	cout << "                                                |___/                                          " << endl;
	Sleep(2000);
	cout << " - Encryption" << endl << endl;
	cout << "\t`#;9,;#<;z%;Ipwn;p$9.$nuO;!;8;1ir?rgs;Xk)^#,$um;?;!&" << endl;
	cout << "\t45; " << "20; " << "90; " << "15; " << "Gold; " << "Platinum; " << "3; " << "1; " << "Leather; " << "Magnesium; " << "2; " << "3&" << endl << endl;
	Sleep(2000);
	cout << " - Error detection in file IO" << endl << endl;
	Sleep(2000);
	cout << " - Error Log" << endl<<endl;
	Sleep(2000);
	cout << " - Difficulty Scaled on level" << endl << endl;
	Sleep(2000);
	cout << " - Rich economy built in" << endl << endl;
	//Sleep(2000);
	//cout << "Fun Facts" << endl<<"--------------------------------" <<endl<< endl;
	//Sleep(2000);
	//cout << " - Over 59 game files used" << endl << endl;
	//Sleep(2000);
	//cout << " - 23 CPP files" << endl << endl;
	//Sleep(2000);
	//cout << " - Over 6000 lines of code" << endl << endl;
	pressAnyButtonToContinue("");
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
	cout << "7. Project Details\n";
	cout << "Enter : ";
}

