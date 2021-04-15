#include "battle.h"

void levelUp(entity& player)
{
	player.level++;
	player.damage += 5;
	player.health += 15;
	player.defence += 3;
	cout << "\n-------------------------------------------------\n";
	cout << "You have leveled up!" << endl << "You are now level: " << player.level << endl;
	cout << "Your damage has incereased to: " << player.damage << endl;
	cout << "Your health has incereased to: " << player.health << endl;
	cout << "Your defense has incereased to: " << player.defence << endl;
	cout << "Your left with: " << player.currentexp << " exp. The amount of exp to get to the next level is now: " << player.expmax << endl;
	cout << "-------------------------------------------------\n";
	player.skillpoints++;
}


