#include "cash.h"
#include <iostream>

u32 cash::money = 0;

void cash::in(u32 income) {
	money += income;
}

bool cash::out(u32 cost) {
	if (money < cost) return false;
	money -= cost;
	std::cerr << "these much money has been spend " << cost << "\n";
	std::cerr << "you've got these much: " << money << "\n";
	return true;
}

u32 cash::get_money() {
	return money;
}
