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

#include "FileIO.h"


// temp
bool skillMain(entity* Player);
bool crafting(entity* player);
bool shopMain(entity* Player);
bool menu(entity* Player);

bool menu(entity* Player) {
    return false;
}
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



#define SPELLSDIR "./GameFiles/Potions/"
#define POTIONSDIR "./GameFiles/Spells/"
#define WEAPONDIR "./GameFiles/Weapons/"
#define DEFENCEDIR "./GameFiles/Armour/"
#define ITEMDIR "./GameFiles/Items/"
#define INVENTORYDIR "./GameFiles/Inventory/"
#define ENEMYDIR "./GameFiles/Enemy/"
#define USERDIR "./GameFiles/UserFiles/"
#define WORD_SIZE 15
void printOptions();
int main() { 
   /* THIS IS USED TO BULK ENCRYPT AND DECRYPT FILES
    string checkSumNames[] = { "WoodSword.BWPF","WoodAxe.BWPF","WoodMace.BWPF","WoodBow.BWPF","IronSword.BWPF","IronAxe.BWPF","IronMace.BWPF","IronBow.BWPF","GoldSword.BWPF","GoldAxe.BWPF","GoldMace.BWPF","GoldBow.BWPF","PlatinumStaff.BWPF","BabyDragon.BINVF","DarkElf.BINVF","Drough.BINVF","Elliott.BINVF","Orc.BINVF","Copper.BITMF","Gold.BITMF","Iron.BITMF","Leather.BITMF","Magnesium.BITMF","Paper.BITMF","Platinum.BITMF","Silver.BITMF","Water.BITMF","BabyDragon.BENF","DarkElf.BENF","Drough.BENF","Elliott.BENF","Orc.BENF","GoldArmour.BAMF","GoldShield.BAMF","IronArmour.BAMF","IronShield.BAMF","WoodShield.BAMF","WoodArmour.BAMF","PlatinumShield.BAMF","PlatinumArmour.BAMF" };
    string Directories[] = { WEAPONDIR,WEAPONDIR,WEAPONDIR ,WEAPONDIR ,WEAPONDIR ,WEAPONDIR ,WEAPONDIR ,WEAPONDIR ,WEAPONDIR ,WEAPONDIR ,WEAPONDIR ,WEAPONDIR ,WEAPONDIR,INVENTORYDIR ,INVENTORYDIR ,INVENTORYDIR ,INVENTORYDIR ,INVENTORYDIR,ITEMDIR,ITEMDIR,ITEMDIR,ITEMDIR,ITEMDIR,ITEMDIR,ITEMDIR,ITEMDIR,ITEMDIR,ENEMYDIR,ENEMYDIR,ENEMYDIR,ENEMYDIR,ENEMYDIR,DEFENCEDIR,DEFENCEDIR,DEFENCEDIR,DEFENCEDIR,DEFENCEDIR,DEFENCEDIR,DEFENCEDIR,DEFENCEDIR };
    for (int i = 0; i < sizeof(Directories) / sizeof(string); i++) {
        string name = Directories[i] + checkSumNames[i];
        ENCRYPT(name);
    }
    */
   
    user* Player = get_User("User");
    cout <<Player->INV[0].Shields[0].BarterItems[0];
    int choice = 0;
    // <- INIT

    while (true) {
        system("cls");
        printOptions();
        choice = getc(stdin);
        switch (choice) {
        case 49: // 1
            if (menu(Player) == false) {
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

