#pragma once
#include <iostream>
#include <time.h>
#include <stdio.h>
#include "entity.h"
using namespace std;

#define BASE_DMG 5

class entity
{
public:
	int health;
	int damage;
	int blockval;
	int defense;
	int level;
	int runCon;
	int exp;
	int expmax;
	int burnCon;
	string name;

	virtual int attack(entity& entity, int damage) = 0;
	virtual void choice(entity& player, entity& enemy) = 0;
	virtual int getDmg() = 0;
	virtual int block(entity& player) = 0;
};