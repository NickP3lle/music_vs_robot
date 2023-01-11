#include "main.h"

bool TestDequePushPop() {
  deque<int> tmp(5);
  for (int i = 0; i < 10; i++)
    tmp.push_back(i);
  for (int i = 0; i < 10; i++)
    if (tmp.len() > 0 && tmp.pop_front() != i)
      return false;
  return true;
}

bool TestDequeRemove() {
  deque<int> tmp(5);
  for (int i = 0; i < 10; i++)
    tmp.push_back(i);
  for (int i = 0; i < 10; i++)
    tmp.remove(tmp.len() % 2 ? tmp.len() - 1 : 0);
  return tmp.len() == 0;
}

bool TestDequeCopy() {
  deque<int> tmp(5);
  for (int i = 0; i < 10; i++)
    tmp.push_back(i);
  deque<int> tmp2(tmp);
  deque<int> tmp3 = tmp;
  for (int i = 0; i < 10; i++) {
    int aux = tmp.pop_front();
    if (tmp2.pop_front() != aux || tmp3.pop_front() != aux)
      return false;
  }
  return true;
}

bool TestDequeIndex() {
  deque<int> tmp(5);
  for (int i = 0; i < 10; i++)
    tmp.push_back(i);
  for (int i = 0; i < 10; i++)
    if (tmp[i] != i)
      return false;
  return true;
}

bool TestDequeIter() {
  deque<int> tmp(5);
  for (int i = 0; i < 10; i++)
    tmp.push_back(i);
  bool flag = true;
  tmp.iter([](int &x) { x *= 2; });
  tmp.iter([&flag](int &x) mutable {
    if (x % 2)
      flag = false;
  });
  return flag;
}
