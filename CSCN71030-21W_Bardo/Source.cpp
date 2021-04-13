/*
* File Name : Main.cpp
*
* Programmer : Thomas Horvath
* Class : Team Based Software Development CSCN71030-21W-SEC1-PROJECT 2
* Date : April 1, 2021
* Teacher : Dr. Elliott Coleshill
* Team : Dominic Pham, Danny Smith, Nicholas, Prince, Ali Syed
*
* Description : Main.cpp used to test the functionality of the Battle Module
*
* Version : 1.0
*/



using namespace std;
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include "BattleModule.h"

void printOptions();
int main() {
    int choice = 0;

    // INIT ->


    // <- INIT
   

    while (true) {
        system("cls");
        printOptions();
        choice = getc(stdin);
        switch (choice) {
        case 49: // 1
            battleMain();
            break;
        case 50: // 2
            break;
        case 51: // 3
            break;
        case 52: // 4
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