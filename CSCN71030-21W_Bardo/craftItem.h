
#pragma once

// Definitions for crafting requirements based on recipe
#define BLACK_POWDER(a,b,c) (a >= 6 && b >= 1 && c >= 1)	// Saltpetre : Charcoal : Sulfur
#define FLASH_POWDER(a,b,c) (a >= 4 && b >= 2 && c >= 3)	// Magnesium : Charcoal : Sulfur
#define FLASH_SPELL(a,b) (a >= 3 && b >= 1)					// Flash Powder : Black Powder
#define SWORD(a,b) (a >= 1 && b >= 10)						// Wood : Iron Ore
#define WAR_HAMMER(a,b) (a >= 3 && b >= 5)					// Wood : Iron Ore
#define MUSKET(a,b) (a >= 3 && b >= 15)						// Wood : Iron Ore

// List of crafting recipes for craftable items
#define R_SWORD "Wood(1) and Iron Ore(10)"
#define R_WAR_HAMMER "Wood(3) and Iron Ore(5)"
#define R_MUSKET "Wood(3) and Iron Ore(15)"
#define R_BLACK_POWDER "Saltpetre(6), Charcoal(1), and Sulfur(1)"
#define R_FLASH_POWDER "Saltpetre(4), Charcoal(2), and Sulfur(3)"
#define R_FLASH_SPELL "Flash Powder(3) and Black Powder(1)"

#include "inventory.h"
void craftItem(inventory* i);