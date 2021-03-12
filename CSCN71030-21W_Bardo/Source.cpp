
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
        //system("cls");
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
        default:
            cout << choice;
            break;

        }
    }
}
void printOptions() {
    cout << "Welcome to the Bardo home town please choose an option\n";
    cout << "-------------------------------------------------------\n";
    cout << endl;
    cout << "1. Exit\n";
    cout << "Enter : ";
}