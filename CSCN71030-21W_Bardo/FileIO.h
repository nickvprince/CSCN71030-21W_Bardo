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
#include "Psecurity.h"
weapon get_Weapon(string name); // retrieves a weapon from a file and returns it as an object
defence get_Defence(string name); // retrieves a defence item from a file and returns it as an object
potion get_Potion(string name); // retrieves a potion from a file and returns it as an object
spell get_Spell(string name); // retrieves a spell from a file and returns it as an object
inventory* get_Inventory(string name); // retrieves inventory from a file and returns it as an object
entity* get_User(string name); // retrieves user information from a file and returns it as an object
enemy* get_Enemy(string name, int level); // retrieves an enemy from a file and returns it as an object
item get_Item(string name); // retrieves an item such as leather or copper
list* getListEnemy(); // gets a list of enemies from a file kept in the enemies directory
void cleanObj(entity* obj); // removes an enemy or user from heap
void cleanObj(list* list); // removes an object of type list from heap
bool FileExists(string name); // checks if file exists
int lengthOfFile(char* name); // length of file in bytes
bool createFile(char* name); // creates an empty file
bool createDirectory(char* name); // creates a directory
bool removeDirectory(char* name); // removes a directory
void ErrorLog(string message, string Severity); // outputs error message to file
ErrorType isFileGood(char* name); // Checks if a file is good using file exists and checksum

bool Save(entity* Player); // save game
list* getListWeapons(); // gets a list of weapons from a file found in the weapons directory
list* getListDefences();// gets a list of armour from a file found in the defence directory
list* getListItems();// gets a list of items from a file found in the items directory
list* getListPotions();// gets a list of potions from a file found in the potions directory
list* getListSpells();// gets a list of spells from a file found in the spells directory
void printList(list* list, int type); // prints a list either just the names (0) or in numberd format | 1., 2. (1)