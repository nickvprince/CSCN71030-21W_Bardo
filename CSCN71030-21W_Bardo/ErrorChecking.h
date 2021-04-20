/*
* File Name : ErrorChecking.h
*
* Programmer : Danny Smith
* Class : Team Based Software Development CSCN71030-21W-SEC1-PROJECT 2
* Date : February 6, 2021
* Teacher : Dr. Elliott Coleshill
* Team : Dominic Pham, Thomas Horvath, Nicholas Prince, Ali Syed
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
* *	enum errortype added, checksum file list and amount started
*	rebuildFiles removed and incorperated into verifyAllFiles
*/
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
void ShowFile(string name); // unhides a file or directory from the system/user
#endif

int getCheckSum(string name); // returns the checksum of a given file