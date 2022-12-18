#include "../cash.cpp"

bool TestCash() {
	if (Cash::getInstance()->getTotal() != 0) {
		return false;
	}
	Cash::getInstance()->add(100);
	if (Cash::getInstance()->getTotal() != 100) {
		return false;
	}
	Cash::getInstance()->sub(50);
	if (Cash::getInstance()->getTotal() != 50) {
		return false;
	}
	return true;
}

