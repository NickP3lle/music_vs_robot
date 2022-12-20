#include "../util.h"
#include "Testdeque.cpp"
#include "Testindependetfn.cpp"
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	Test("dequePushPop", TestdequePushPop);
	Test("dequeCopy", TestdequeCopy);
	Test("dequeIndex", TestdequeIndex);

	Test("RandomInt", TestRandomInt);
  return 0;
}
