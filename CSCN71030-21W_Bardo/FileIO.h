/* Date : February 6, 2021
* Teacher : Dr.Elliot Coleshill
* Team : Dominic Pham, Thomas Horvath, Nicholas, Prince, Ali Syed
*
* Description :
	*
	*
	*Version : 1.0
	*
	*
	*History :
	*Functionality created but left empty
	* new file creation, length of file, file exists, and create directory functionality addedand completed
	* Testing Void pointer | FAILED
	* isFileGood added
*/

#include "Objects.h"
#include "ErrorChecking.h"

weapon get_Weapon(string name); // retrieves a weapon from a file and returns it as an object
defence get_Defence(string name); // retrieves a defence item from a file and returns it as an object
potion get_Potion(string name); // retrieves a potion from a file and returns it as an object
spell get_Spell(string name); // retrieves a spell from a file and returns it as an object
inventory* get_Inventory(string name); // retrieves inventory from a file and returns it as an object
user* get_User(string name); // retrieves user information from a file and returns it as an object
enemy* get_Enemy(string name,int level); // retrieves an enemy from a file and returns it as an object
item get_Item(string name); // retrieves an item such as leather or copper
void cleanObj(entity* obj); // removes an enemy or user from heap
void cleanObj(list* list);
bool FileExists(string name); // checks if file exists
int lengthOfFile(char* name); // length of file in bytes
bool createFile(char* name); // creates an empty file
bool createDirectory(char* name); // creates a directory
bool removeDirectory(char* name); // removes a directory
void ErrorLog(string message,string Severity); // outputs error message to file
ErrorType isFileGood(char* name); // Checks if a file is good using file exists and checksum

bool Save(entity* Player);
list* getListWeapons();
list* getListDefences();
list* getListItems();
list* getListPotions();
list* getListSpells();
void printList(list* list, int type);