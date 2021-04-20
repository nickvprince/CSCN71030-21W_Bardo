/*
* File Name : PSecurity.h
*
* Programmer : Danny Smith
* Class : Team Based Software Development CSCN71030-21W-SEC1-PROJECT 2
* Date : February 6, 2021
* Teacher : Dr. Elliot Coleshill
* Team : Dominic Pham, Thomas Horvath, Nicholas, Prince, Ali Syed
*
* Description : Used for security purposes of data storage and retrieval including an encryption and decryption protocol
*
*
* Version : 1.0
*
*
* History :
* encrypt class created
* Functioned planned out yet to be implemented
* Keys :*,&,; removed for file formatting
* Encrypt_file and Decrypt_file now makes temp file deletes original and renames new file to original name
* show file added
* setReadOnly removed I felt this was a little far since the user cant find the file already and its encrypted so it wont add any extra security worth the performance drop
* SetsystemOnlyPermissions removed see reason above ^
*
* Suggestions : Un-Hardcode password
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>


using namespace std;


void ENCRYPT(string name); // encrypts entire file
void DECRYPT(string name); // decrypts entire file


/*
* The object encrypt class is near a AES encryption algorithem designed by Danny Smith
* The object has private functionality to encrypt and decrypt a single char, print the s-box used in encrypting and initialization of the s-box
* KEY defines the password used for encryption and decryption
* Public functionality includes encryption and decryption of an entire file
*/
class encrypt {
public:
#define KEY "Cihper!kcblk@3976" // hardcoded password for encryption and decryption

	int location = 0; // location in the password matched with input for encryption and decryption
	char characters[89] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9','0','!','@','#','$','%','^','(',')','{','}','[',']',':','"',',','.','<','>','/','?','~','`','-','_','+','=','\n' };
	char sbox[sizeof(characters)][sizeof(characters)]; // array of every iteration of the characters array

	void print_sbox() { // displays the s-box to the screen for debugging
		for (int counter = 0; counter < sizeof(characters); counter++) { // for y
			for (int counter2 = 0; counter2 < sizeof(characters); counter2++) { // for x
				printf_s("%c", sbox[counter][counter2]);
			} // for x
			printf_s("\n");
		} // for y

	} // print_sbox

	void init_sbox() { // initalize the s-box with the iterations of characters
		int charat = 0; // for flipping back to zero when the password length is exceeded
		for (int counter = 0; counter < sizeof(characters); counter++) { // for y
			for (int ycounter = 0; ycounter < sizeof(characters); ycounter++) { // for x
				if (ycounter + charat > sizeof(characters)) { // if characters array length exceeded start again at beginning of array
					sbox[ycounter][counter] = characters[(ycounter + charat) - sizeof(characters)];
				} 				else {
					sbox[ycounter][counter] = characters[ycounter + charat];
				}

			} // xcounter
			charat++;
		} // ycounter
	} // init sbox

	char Decrypt(const char input) {
		if (input == '*' | input == '&' | input == ';') { // if a EOL or EOF or space char skip
			return input;
		}
		int ylocation = 0; // ycoordinate in sbox for retrieving character
		int xlocation = 0; // xcoordinate in sbox for retrieving character
		for (int counter = 0; counter < sizeof(characters); counter++) { // search for key in password in first y column
			if (KEY[location] == sbox[0][counter]) {

				ylocation = counter;
				counter += 2000; // end loop once found
			}
		}
		for (int counter = 0; counter < sizeof(characters); counter++) { // search for input char in password y column on the x-axis
			if (sbox[counter][ylocation] == input) {
				xlocation = counter;
				counter += 2000; // end loop once found
			}

		}

		location++; // increment the location to move to the next part of the password
		if (location > sizeof(KEY)) { // reset location back to zero if KEY length is exceeded
			resetLocation();
		}

		return sbox[0][xlocation]; // return decrypted char
	}

	char Encrypt(const char input) {
		if (input == '*' | input == '&' | input == ';') { // if a EOL or EOF or space char skip
			return input;
		}
		int xcoord = 0; // xcoordinate in sbox for retrieving character
		int ycoord = 0; // ycoordinate in sbox for retrieving character
		for (int counter = 0; counter < sizeof(characters); counter++) { // search for input char in the first row of the box
			if (input == sbox[counter][0]) {
				xcoord = counter;
			}
			if (KEY[location] == sbox[0][counter]) { // search for passkey char in the first column 
				ycoord = counter;
			}
		}

		location++; // increment location of the passkey 
		if (location > sizeof(KEY)) { // reset to zero is KEY is exceeded
			resetLocation();
		}

		return sbox[ycoord][xcoord]; // return encrypted char

	}
	void resetLocation() { // set private location variable to 0
		location = 0;
	}
public:

	encrypt() { // initializer to setup the s-box for encryption and decryption purposes
		init_sbox();
	}

	void encryptFile(string name) { // encrypt / decrypt files are only function left public so single chars cant be encrypted and decypted reducing the likelihood of a brute force attack
		fstream file;
		fstream File2;


		string name2 = name + "2";
		File2.open(name2, ios::out);
		file.open(name, ios::in);
		char input;
		char encryptedChar;
		file >> input;
		while (input != '&') {
			encryptedChar = Encrypt(input);
			File2 << encryptedChar;
			file >> input;
		}
		file.close();
		File2 << '&';
		File2.close();
		remove((const char*)name.c_str());
		rename((const char*)name2.c_str(), (const char*)name.c_str());
	}

	void decryptFile(string name) { // encrypt / decrypt files are only function left public so single chars cant be encrypted and decypted reducing the likelihood of a brute force attack
		resetLocation();
		fstream file;
		fstream File2;
		string name2 = name + "2";
		file.open(name, ios::in);
		File2.open(name2, ios::out);
		char input;
		char decryptedChar;
		file >> input;
		while (input != '&') {
			decryptedChar = Decrypt(input);
			if (decryptedChar == ';') {
				File2 << ';' << '\n';
			} 			else {
				File2 << decryptedChar;
			}
			file >> input;
		}
		file.close();
		File2 << '&';
		File2.close();
		remove((const char*)name.c_str());
		rename((const char*)name2.c_str(), (const char*)name.c_str());
	}

}; // encrypt class


