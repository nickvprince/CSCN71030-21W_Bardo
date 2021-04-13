/*
* File Name : Main.cpp
*
* Programmer : Ali Syed
* Class : Team Based Software Development CSCN71030-21W-SEC1-PROJECT 2
* Date : April 3, 2021
* Teacher : Dr. Elliott Coleshill
* Team : Dominic Pham, Thomas Horvath, Nicholas, Prince, Danny Smith

*/
#include "FileIO.h"
#pragma once

int startMenu();
user* newGame();
void printStats(user* Player);
void setStats(user* Player);
user* manualSetStats(user* Player);
user* selectStarterWeapon(user* Player);
user* selectStarterShield(user* Player);
void setRace(user* Player);
bool loadScreen(user* Player);
bool defaultStat(user* Player);
bool defaultConfirmation();
void humanStats();
void elfStats();
void dwarfStats();
user* startIO(user* Player);
bool valueCheck(const string& value);