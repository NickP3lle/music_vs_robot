#include <iostream>
#include "../deque.h"
using namespace std;

bool Testdeque() {
	deque<int> tmp(5);
	for (int i=0; i<10; i++)
		tmp.push_back(i);
	for (int i=0; i<10; i++)
		if (tmp.pop_front().unwrap() != i)
			return false;
	return true;
}

int main() {
	if (Testdeque())
		cout << "test on Testdeque(): passed\n";
	else cout << "test on Testdeque(): failed\n";
}


