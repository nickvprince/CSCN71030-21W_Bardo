
using namespace std;
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include "SkillTree.h"
void printOptions();
int main() {
    int choice = 0;

    // INIT ->
    user* Player = new user();
    Player->health = 1000;
    Player->skillpoints = 4;
    Skilltree(Player);
    // <- INIT
    while (true) {
        system("cls");
        
        printOptions();
        choice = getc(stdin);
     
        switch (choice) {
        case 48: // = int 0
            break;
        case 49: // = int 1
            exit(0);
        case 50:
            // test
            break;
        case 51:
            //test 2
            break;
        case 52:
            //test 3
            break;
		case 53:
			//test 4
			break;
        default:
            cout << choice;
            break;

        }
        while ((getchar()) != '\n');
    }
}
void printOptions() {
    cout << "Welcome to the Bardo home town please choose an option\n";
    cout << "-------------------------------------------------------\n";
    cout << endl;
    cout << "1. Exit\n";
    cout << "Enter : ";
}