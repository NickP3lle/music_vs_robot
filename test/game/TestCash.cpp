#include "main.h"

/// Cash needs not to be private to be tested
// bool TestCashGetInstance() {
// 	if (Cash::getInstance() == NULL) {
// 		return false;
// 	}
// 	return true;
// }

bool TestCashAdd() {
  Cash::cleanUp();
  Cash::add(100);
  //  std::cout << Cash::get() << std::endl;
  if (Cash::get() != 100) {
    return false;
  }
  return true;
}

bool TestCashSub() {
  Cash::cleanUp();
  Cash::add(100);
  Cash::sub(50);
  //  std::cout << Cash::get() << std::endl;
  if (Cash::get() != 50) {
    return false;
  }
  return true;
}
