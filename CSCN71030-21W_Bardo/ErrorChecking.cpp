#include <iostream>
#include <fstream>
#include "ErrorChecking.h"

using namespace std;
/*
* File Name : ErrorChecking.cpp
*
* Programmer : Danny Smith
* Class : Team Based Software Development CSCN71030-21W-SEC1-PROJECT 2
* Date : February 6, 2021
* Teacher : Dr. Elliott Coleshill
* Team : Dominic Pham, Thomas Horvath, Nicholas, Prince, Ali Syed
*
* Description :
*
*
* Version : 1.0
*
*
* History :
*	Verify functions defined and left empty
*	parityOnBlock renamed to Checksum
*   checksum completed comments need to be included
*	VerifyHiddenFile Completed
*	Set system only permissions removed
*/


#ifdef _WIN32
#include <Windows.h>
bool VerifyHiddenFile(char* name) { // verifies the file is hidden to the user
	DWORD word = GetFileAttributesA((LPCSTR)name);
	switch (word & FILE_ATTRIBUTE_HIDDEN) {
	case 0:
		return false;
		break;
	case 2:
		return true;
		break;
	default:
		return false;
	}
}
#endif

bool Checksum(string name, int size) { // verify size of file matches what its supposed to be
	fstream file;
	int length = 0;
	unsigned int sum = 0;
	char input = 'a';
	file.open(name, ios::in);
	if (file.is_open()) {
		while (length != 2000) {
			file >> input;
			if (input == '&') {
				break;
			}
			else if (input == ';') {
				//formatting printed doc
				//printf_s("\n");
			}
			else if (input == '*') {
				// formatting printed doc
				//printf_s(" ");
			}
			else {
				// to see doc printed
				//cout << input;
				sum += (int)input;
			}
			length++;
		}
		file.close();
		// to see checksum printed
		//printf_s("%d", (int)(sum % length));
		if (sum % length == size) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	return false; // incase fail unforseen
}

int getCheckSum(string name) {
	fstream file;
	int length = 0;
	unsigned int sum = 0;
	char input = 'a';
	file.open(name, ios::in);
	if (file.is_open()) {
		while (length != 2000) {
			file >> input;
			if (input == '&') {
				break;
			}
			else if (input == ';') {
				//formatting printed doc
				//printf_s("\n");
			}
			else if (input == '*') {
				// formatting printed doc
				//printf_s(" ");
			}
			else {
				// to see doc printed
				//cout << input;
				sum += (int)input;
			}
			length++;
		}
		file.close();
	}
	if (length == 0) {
		return 0;
	}
	else {
		return sum % length;
	}
}

bool VerifyAllFiles() { // runs CheckSum on all files to verify they are the proper size also verifies all files exist

	int checkSums[] = { 3, 5, 5 };
	string checkSumNames[] = { "IronSword.BWPF", "WoodBow.BWPF","IronShield.BAMF" };
	string Directories[] = { "./GameFiles/Weapons/","./GameFiles/Weapons/","./GameFiles/Armour/" };


	string ProtectedDir = { "ProtectedGameFiles" };
	bool failed = false;

	for (int dirs = 0; dirs < sizeof(Directories) / sizeof(string); dirs++) { // run through all directories
		string protectedName = "./" + ProtectedDir + Directories[dirs] + checkSumNames[dirs];
		string fileName = Directories[dirs] + checkSumNames[dirs];

		if (getCheckSum(protectedName) == 0 || getCheckSum(fileName) == 0) { // one of the files doesnt exist
			failed = true;
		}
		else if (getCheckSum(protectedName) == getCheckSum(fileName)) {

		}
		else if (getCheckSum(protectedName) != getCheckSum(fileName)) { // if they dont match copt protected file to usable file
			char input;
			remove((const char*)fileName.c_str());
			fstream outFile;
			fstream inFile;
			outFile.open(fileName, ios::out);
			inFile.open(protectedName, ios::in);
			inFile >> input;
			int count = 0;
			while (input != '&') {
				if (input == ';') {
					outFile << ";\n";
				}
				else {
					outFile << input;
				}
				count++; // if something goes wrong
				inFile >> input;
			}
			outFile << '&';
			inFile.close();
			outFile.close();
		}
		else {
			failed = true;
		}

		// run hidden file afterwards incase a file needs to be re made
		if (VerifyHiddenFile((char*)protectedName.c_str()) == 0) { // if not hidden

		
			HideFile((char*)protectedName.c_str(), 1);
		}
		if (VerifyHiddenFile((char*)fileName.c_str()) == 0) { // if hidden

		
			HideFile((char*)fileName.c_str(), 0);
		}
	}

	return failed;
}

#ifdef _WIN32 // only run in windows OS
#include <Windows.h>
void HideFile(string name, int system_Yes_No) { // hides a file from the user so its only visible to the system
	string new_Name;
	if (system_Yes_No == 1) {
		new_Name = "attrib +h +s ";
	}
	else if (system_Yes_No == 0) {
		ShowFile(name);
		new_Name = "attrib +h ";
	}
	new_Name = new_Name + name;
	system((const char*)new_Name.c_str());
}
void ShowFile(string name) { // hides a file from the user so its only visible to the system
	string new_Name;
	new_Name = "attrib -h -s ";
	new_Name = new_Name + name;
	system((const char*)new_Name.c_str());

}
#endif
