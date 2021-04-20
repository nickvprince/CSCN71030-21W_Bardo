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
entity* newGame();
void printStats(entity* Player);
entity* setStats(entity* Player);
entity* manualSetStats(entity* Player);
entity* selectStarterWeapon(entity* Player);
entity* selectStarterShield(entity* Player);
void setRace(entity* Player);
bool loadScreen(entity* Player);
bool defaultStat(entity* Player);
bool defaultConfirmation();
void humanStats();
void elfStats();
void dwarfStats();
entity* startIO(entity* Player);
bool valueCheck(const string& value);