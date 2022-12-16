#include "cash.h"

void Cash::add(u32 amount) {
	totalCash += amount;
}

bool Cash::remove(u32 amount) {
	if (totalCash >= amount) {
		totalCash -= amount;
		return true;
	} else {
		return false;
	}
}

double Cash::getTotal() {
	return totalCash;
}
