/*
* File Name: WeaponsDealer.h
*
* Programmer: Nicholas Prince
* Class: Team Based Software Development CSCN71030-21W-SEC1-PROJECT 2
* Date: March 22, 2021
* Teacher: Dr. Elliott Coleshill
* Team: Dominic Pham, Thomas Horvath, Danny Smith, Ali Syed
*
* Module: Economy
*
*/

#pragma once

#include "Dealer.h"

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class WeaponDealer : public Dealer {
public:
	WeaponDealer();
	void printDealerInfo()override;
	string getName()override;
	int getDealerBalance()override;
	void buy(entity*)override;
	void sell(entity*)override;
	void barter(entity*)override;
	string getDealerBuyChoice(entity*)override;
	void printDealerOptions()override;
	bool getItemStats(string, entity*)override;
};
