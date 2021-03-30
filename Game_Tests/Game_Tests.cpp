/*
* File Name : TESTS.cpp
*
* Programmer : Danny Smith
* Class : Team Based Software Development CSCN71030-21W-SEC1-PROJECT 2
* Date : February 12, 2021
* Teacher : Dr. Elliott Coleshill
* Team : Dominic Pham, Thomas Horvath, Nicholas, Prince, Ali Syed
*
* Description : TESTS.cpp will test the functionnality of all my files. Each file will get its own class
*
*
* Version : 1.0
*
*
* History :
*	Classes created and left empty
*
*/

#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FileIOTests
{
	//#include "PSecurity.h" // includes FileIO.h which includes >> objects.h && ErroChecking.h
	//#include "Psecurity.h"
	TEST_CLASS(Securitytests)
	{
	public:
		TEST_METHOD(EncryptFile) {

		}
		TEST_METHOD(DecryptFile) {

		}
		TEST_METHOD(HiddenFile_True) {

		}
		TEST_METHOD(HiddenFile_False) {

		}
		TEST_METHOD(encrypt_decrypt_100_times) {

		}

	};

	TEST_CLASS(FileIOtests)
	{
	public:
		TEST_METHOD(getWeapon_checkDamage) {

		}

		TEST_METHOD(getWeapon_checkName) {

		}
		TEST_METHOD(getWeapon_checkValue) {

		}
		TEST_METHOD(getWeapon_checkEquipped) {

		}
		TEST_METHOD(getWeapon_checkWeight) {

		}

		TEST_METHOD(getDefence_checkValue) {

		}
		TEST_METHOD(getDefence_checkName) {

		}
		TEST_METHOD(getDefence_checkDefence) {

		}
		TEST_METHOD(getDefence_checkEquipped) {

		}
		TEST_METHOD(getDefence_checkWeight) {

		}

		TEST_METHOD(getPotion_checkName) {

		}

		TEST_METHOD(getPotion_checkEffect) {

		}

		TEST_METHOD(getPotion_checkValue) {

		}

		TEST_METHOD(getPotion_checkWeight) {

		}

		TEST_METHOD(getSpell_checkName) {

		}
		TEST_METHOD(getSpell_checkType) {

		}
		TEST_METHOD(getSpell_checkDamage) {

		}
		TEST_METHOD(getSpell_checkValue) {

		}
		TEST_METHOD(getInventory) {

		}
		TEST_METHOD(getUser_checkHealth) {

		}
		TEST_METHOD(getUser_checkInventory) {

		}
		TEST_METHOD(getUser_checkDamage) {

		}
		TEST_METHOD(getUser_checkDefence) {

		}

		TEST_METHOD(getUser_checkArmor) {


		}

		TEST_METHOD(getUser_checkMoney) {

		}

		TEST_METHOD(getEnemy_Orc_checkHealth) {

		}
		TEST_METHOD(getEnemy_Orc_checkArmor) {

		}
		TEST_METHOD(getEnemy_Orc_checkDefence) {

		}
		TEST_METHOD(getEnemy_Orc_checkDroppables) {

		}
		TEST_METHOD(getEnemy_Orc_checkWeaponUsed) {

		}
		TEST_METHOD(getEnemy_Orc_checkName) {

		}
		TEST_METHOD(getEnemy_Orc_checkLevel) {

		}
		TEST_METHOD(FILE_exists_does) {

		}
		TEST_METHOD(FILE_exists_does_NOT) {

		}
		TEST_METHOD(FileLength_50byte_expected_10) {

		}
		TEST_METHOD(FileLength_50byte_expected_50) {

		}
		TEST_METHOD(FileLength_5000byte_expected_5000) {

		}
		TEST_METHOD(createFileDuplicate) {

		}
		TEST_METHOD(createNewFile) {

		}
		TEST_METHOD(createNewDirectory) {

		}
		TEST_METHOD(createDuplicateDirectory) {

		}
		TEST_METHOD(deleteDirectory) {

		}
		TEST_METHOD(deleteNonExistantDirectory) {

		}
	};

	TEST_CLASS(ErrorCheckingTests)
	{
	public:
		TEST_METHOD(NotHiddenCheckIfIs) {

		}
		TEST_METHOD(HiddenFileCheckIfNot) {

		}
		TEST_METHOD(HiddenFileCheckIfIs) {

		}
		TEST_METHOD(NotHiddenFileCheckIfNot) {

		}
		TEST_METHOD(BadParity) {

		}
		TEST_METHOD(GoodParity) {

		}
		TEST_METHOD(OneMissingFile) {

		}
		TEST_METHOD(TwoMissingFile) {

		}
		TEST_METHOD(MissingDirectory) {

		}
		TEST_METHOD(MissingAllFiles) {

		}
		TEST_METHOD(RebuildFiles) {

		}
		TEST_METHOD(FileExists_True) {

		}
		TEST_METHOD(FileExists_False) {

		}
		TEST_METHOD(checkSum_CorrectNumber) {

		}
		TEST_METHOD(checkSum_BadNumber) {

		}

	};

	TEST_CLASS(ObjectsTests)
	{
	public:
		TEST_METHOD(enemyGetDefence) {

		}
		TEST_METHOD(enemyGetArmor) {

		}
		TEST_METHOD(enemyGetHealth) {

		}
		TEST_METHOD(enemyGetLevel) {

		}
		TEST_METHOD(enemyGetWeapon) {

		}
	};




	//							NOTES BELOW




/*
* To test PSecurity.h Encrypt and Decrpyt functions...
* Copy private functions to public
* uncomment the /*'s below and copy into main.cpp
* output will print the encrypted version of helloO 5 times without line break
* then will line break and output should be -
* helloO
* helloO
* helloO
* helloO
* helloO
*/
// DEBUGGING
/*
encrypt* Encryption = new encrypt();
//Encryption->print_sbox();
printf_s("%c",Encryption->Encrypt('h'));
printf_s("%c", Encryption->Encrypt('e'));
printf_s("%c", Encryption->Encrypt('l'));
printf_s("%c", Encryption->Encrypt('l'));
printf_s("%c", Encryption->Encrypt('o'));
printf_s("%c", Encryption->Encrypt('O'));
printf_s("%c", Encryption->Encrypt('h'));
printf_s("%c", Encryption->Encrypt('e'));
printf_s("%c", Encryption->Encrypt('l'));
printf_s("%c", Encryption->Encrypt('l'));
printf_s("%c", Encryption->Encrypt('o'));
printf_s("%c", Encryption->Encrypt('O'));
printf_s("%c", Encryption->Encrypt('h'));
printf_s("%c", Encryption->Encrypt('e'));
printf_s("%c", Encryption->Encrypt('l'));
printf_s("%c", Encryption->Encrypt('l'));
printf_s("%c", Encryption->Encrypt('o'));
printf_s("%c", Encryption->Encrypt('O'));
printf_s("%c", Encryption->Encrypt('h'));
printf_s("%c", Encryption->Encrypt('e'));
printf_s("%c", Encryption->Encrypt('l'));
printf_s("%c", Encryption->Encrypt('l'));
printf_s("%c", Encryption->Encrypt('o'));
printf_s("%c", Encryption->Encrypt('O'));
Encryption->resetLocation();
printf_s("\n%c", Encryption->Decrypt('J'));
printf_s("%c", Encryption->Decrypt('m'));
printf_s("%c", Encryption->Decrypt('s'));
printf_s("%c", Encryption->Decrypt('A'));
printf_s("%c", Encryption->Decrypt('s'));
printf_s("%c", Encryption->Decrypt('6'));
printf_s("\n%c", Encryption->Decrypt('*'));
printf_s("%c", Encryption->Decrypt('o'));
printf_s("%c", Encryption->Decrypt('n'));
printf_s("%c", Encryption->Decrypt('m'));
printf_s("%c", Encryption->Decrypt('z'));
printf_s("%c", Encryption->Decrypt('Y'));
printf_s("\n%c", Encryption->Decrypt('('));
printf_s("%c", Encryption->Decrypt('7'));
printf_s("%c", Encryption->Decrypt(')'));
printf_s("%c", Encryption->Decrypt('*'));
printf_s("%c", Encryption->Decrypt(')'));
printf_s("%c", Encryption->Decrypt('O'));
printf_s("\n%c", Encryption->Decrypt('h'));
printf_s("%c", Encryption->Decrypt('G'));
printf_s("%c", Encryption->Decrypt('t'));
printf_s("%c", Encryption->Decrypt('s'));
printf_s("%c", Encryption->Decrypt('D'));
printf_s("%c", Encryption->Decrypt('S'));
*/
// DEBUGGING



}

namespace BattleTests {
	TEST_CLASS(testing)
	{
	public:
		TEST_METHOD(test) {

		}
	};
}

namespace EconomyTests {
	TEST_CLASS(testing)
	{
	public:
		TEST_METHOD(test) {

		}
	};
}

namespace CharacterCreation {
	TEST_CLASS(testing)
	{
	public:
		TEST_METHOD(test) {

		}
	};
}

namespace Skills {
	TEST_CLASS(testing)
	{
	public:
		TEST_METHOD(test) {

		}
	};
}

namespace Main {
	TEST_CLASS(testing)
	{
	public:
		TEST_METHOD(test) {

		}
	};
}