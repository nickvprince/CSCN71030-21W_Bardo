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
#include "Psecurity.h"



// temp
bool skillMain(entity& Player);
bool crafting(entity& player);
bool shopMain(entity& Player);
bool menu(entity& Player);
bool menu(entity& Player) {
    return false;
}
bool shopMain(entity& Player) {
    return false;
}
bool crafting(entity& player) {
    return false;
}
bool skillMain(entity& Player) {
    return false;
}
// temp



void printOptions();
int main() {
    
    // INIT ->
    user* Player = get_User("User");
    int choice = 0;
    // <- INIT

    while (true) {
        system("cls");
        printOptions();
        choice = getc(stdin);
        switch (choice) {
        case 49: // 1
            if (menu(*Player) == false) {
                ErrorLog("Check sum error", "Low spfgnwepifgn");
            }
            break;
        case 50: // 2
            if (shopMain(*Player) == false) {
                ErrorLog("Shop failed", "Severe");
            }
            break;
        case 51: // 3
            if (crafting(*Player) == false) {
                ErrorLog("Crafting failed", "Severe");
            }
            break;
        case 52: // 4
            if (skillMain(*Player) == false) {
                ErrorLog("Skill Main failed", "Severe");
            }
            break;
        case 53: // 5
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
    cout << "5. Exit\n";
    cout << "Enter : ";
}