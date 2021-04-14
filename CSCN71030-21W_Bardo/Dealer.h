/*
* File Name: Dealer.h
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

#define EMPTY 0x00000000CDCDCDCD

#include "OtherFuntions.h"

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdbool.h>

using namespace std;

class Dealer {
protected:
	string name;
	int balance;
public:
	Dealer();
	virtual void printDealerInfo() = 0;
	virtual string getName() = 0;
	virtual int getDealerBalance() = 0;
	virtual void buy(entity*) = 0;
	virtual void sell(entity*) = 0;
	virtual void barter(entity*) = 0;
	virtual string getDealerBuyChoice(entity*) = 0;
	virtual void printDealerOptions();
	virtual void printDealerHeader(entity*);
	virtual void getOptionChoice(Dealer*, entity*);
	virtual bool getItemStats(string, entity*) = 0;
};