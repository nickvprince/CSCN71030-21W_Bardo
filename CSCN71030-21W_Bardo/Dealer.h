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

#include "Objects.h"

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string>

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
	virtual void buy(user*, string) = 0;
	virtual void sell(inventory*, string) = 0;
	virtual void listDealerItems() = 0;
	virtual void printDealerOptions();
	virtual void printDealerHeader();
	virtual void getOptionChoice(Dealer*, user*);
};
 