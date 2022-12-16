#include "cash.h"

Cash* Cash::instance = nullptr;

Cash* Cash::getInstance() {
	if (instance == nullptr) {
		instance = new Cash();
	}
	return instance;
}

Cash::Cash() {
	total = 0;
}

void Cash::add(u32 amount) {
	total += amount;
}

void Cash::sub(u32 amount) {
	total -= amount;
}

u32 Cash::getTotal() {
	return total;
}
