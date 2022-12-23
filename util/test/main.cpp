#include "main.h"

using namespace std;

int main() {
	Test("dequePushPop", TestdequePushPop);
	Test("dequeCopy", TestdequeCopy);
	Test("dequeIndex", TestdequeIndex);

	Test("RandomInt", TestRandomInt);

	Test("Iterator", TestIterator);
	Test("IteratorCopy", TestIteratorCopy);
	Test("IteratorAssign", TestIteratorAssign);
	Test("IteratorMap", TestIteratorMap);
	Test("IteratorFilter", TestIteratorFilter);
	Test("IteratorCollect", TestIteratorCollect);

	Test("dequeIter", TestdequeIter);
	Test("dequeCollect", TestdequeCollect);
  return 0;
}
