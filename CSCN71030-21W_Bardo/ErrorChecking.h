#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stdbool.h>
#include <iostream>
#include <stdbool.h>

using namespace std;


#ifdef _WIN32
bool VerifyHiddenFile(char* name); // verifies the file is hidden to the user
#endif
bool Checksum(string name, int size); // verify size of file matches what its supposed to be
bool VerifyAllFiles(); // runs checksum on all files to verify they are the proper size also verifies all files exist
#ifdef _WIN32 // only run in windows OS
void HideFile(string name, int type); // hide file from user
void ShowFile(string name);
#endif

int getCheckSum(string name);