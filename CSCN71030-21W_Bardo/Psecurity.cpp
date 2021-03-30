#include "PSecurity.h"

/*
* File Name : Security.cpp
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
*	Encrypt Decrypt function created
*   File modification functions added and left empty
*	Show File added
*	Hide File Completed
*
*
* Modifications to make :
*	- Un-Hardcode password
*
*/


void ENCRYPT(string name) { // encrypts a file using an object so objects dont need to be created in the game for functionality
	encrypt* Functionality = new encrypt;
	Functionality->encryptFile(name);
	delete(Functionality);
}
void DECRYPT(string name) { // decrypts a file using an object so objects dont need to be created in the game for functionality
	encrypt* Functionality = new encrypt;
	Functionality->decryptFile(name);
	delete(Functionality);
}

