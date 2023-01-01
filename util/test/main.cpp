#include "main.h"

using namespace std;

int main() {
	Test("RandomInt", TestRandomInt);

	Test("dequePushPop", TestdequePushPop);
	Test("dequeCopy", TestdequeCopy);
	//Test("dequeAssign", TestdequeAssign);
	Test("dequeIndex", TestdequeIndex);
	Test("dequeIter", TestdequeIter);
	Test("dequeCollect", TestdequeCollect);

	Test("Iterator", TestIterator);
	Test("IteratorCopy", TestIteratorCopy);
	Test("IteratorAssign", TestIteratorAssign);
	Test("IteratorMap", TestIteratorMap);
	Test("IteratorFilter", TestIteratorFilter);
	Test("IteratorCollect", TestIteratorCollect);

  return 0;
}

// error on iterator filter: solved [&, new_ptr]
// error on deque collect: solved (anyhow)
