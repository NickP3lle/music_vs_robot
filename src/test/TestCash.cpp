#include "../cash.cpp"

bool TestCashGetInstance() {
	if (Cash::getInstance() == NULL) {
		return false;
	}
	return true;
}

bool TestCashAdd() {
	Cash::getInstance()->add(100);
	if (Cash::getInstance()->getTotal() != 100) {
		return false;
	}
	return true;
}

bool TestCashSub() {
	Cash::getInstance()->sub(50);
	if (Cash::getInstance()->getTotal() != 50) {
		return false;
	}
	return true;
}
