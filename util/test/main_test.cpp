#include "../util.h"
#include <iostream>
using namespace std;

bool TestdequePushPop() {
  deque<int> tmp(5);
  for (int i = 0; i < 10; i++)
    tmp.push_back(i);
  for (int i = 0; i < 10; i++)
    if (tmp.pop_front().get() != i)
      return false;
  return true;
}

bool TestdequeCopy() {
  deque<int> tmp(5);
  for (int i = 0; i < 10; i++)
    tmp.push_back(i);
  deque<int> tmp2(tmp);
  for (int i = 0; i < 10; i++)
    if (tmp2.pop_front().get() != tmp.pop_front().get())
      return false;
  return true;
}

bool TestdequeIndex() {
  deque<int> tmp(5);
  for (int i = 0; i < 10; i++)
	tmp.push_back(i);
  for (int i = 0; i < 10; i++)
	if (tmp[i] != i)
	  return false;
  return true;
}

int main() {
  cout << "test on TestdequePushPop: " << 
	  (TestdequePushPop() ? "OK" : "FAIL") << "\n";
  cout << "test on TestdequePushPop: " << 
	  (TestdequePushPop() ? "OK" : "FAIL") << "\n";
  cout << "test on TestdequeCopy: " << 
	  (TestdequeCopy() ? "OK" : "FAIL") << "\n";
  cout << "test on TestdequeIndex: " << 
	  (TestdequeIndex() ? "OK" : "FAIL") << "\n";
  return 0;
}
