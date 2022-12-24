#include "main.h"

bool TestdequePushPop() {
  deque<int> tmp(5);
  for (int i = 0; i < 10; i++)
    tmp.push_back(i);
  for (int i = 0; i < 10; i++)
    if (tmp.len() > 0 && tmp.pop_front().get() != i)
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

bool TestdequeAssign() {
  deque<int> tmp(5);
  for (int i = 0; i < 10; i++)
    tmp.push_back(i);
  deque<int> tmp2 = tmp;
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

bool TestdequeIter() {
  deque<int> tmp(5);
  for (int i = 0; i < 10; i++)
    tmp.push_back(i);
  if (tmp.len() != tmp.iter().len())
    return false;
  return true;
}

bool TestdequeCollect() {
  deque<int> tmp(5);
  for (int i = 0; i < 10; i++)
    tmp.push_back(i);
  tmp.iter()
      .filter([](int a) { return a % 2 == 0; }) // 0 2 4 6 8
      .map([](int *a) { *a *= 2; }) 	// 0 4 8 12 16
      .collect<deque<int*>>();
  for (int i = 0; i < tmp.len(); i++)
	  if (tmp[i] % 2 == 0 && tmp[i] != i * 2)
      return false;
  return true;
}
