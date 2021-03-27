#pragma once

#define MAX_MATERIAL 8
#define MAX_WEAPON 4
#define MAX_SPELL 2
#include "item.h"

class inventory : public item {		// Inventory consists of an array for each item type
public:
	item material[MAX_MATERIAL];
	item weapon[MAX_WEAPON];
	item spell[MAX_SPELL];
};