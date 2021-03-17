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
*	ReadMe File Created, IronSword weapon test file created
*
* Revision Ideas -
*	FileIO as threads to do the workload while other operations are running
*/



using namespace std;
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

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