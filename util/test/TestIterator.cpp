#include "main.h"
#include <vector>

typedef Iterator<int> iter;

bool TestIterator() {
  iter it(new int[3]{1, 2, 3}, 3);
  for (int i = 0; i < it.len(); i++)
    if (it[i] != i + 1)
      return false;
  return true;
}

bool TestIteratorCopy() {
  iter it(new int[3]{1, 2, 3}, 3);
  iter it2(it);
  for (int i = 0; i < it.len(); i++)
    if (it[i] != it2[i])
      return false;
  it[0] = 0;
  if (it[0] == it2[0])
    return false;
  return true;
}

bool TestIteratorAssign() {
  iter it(new int[3]{1, 2, 3}, 3);
  iter it2(new int[3]{4, 5, 6}, 3);
  it2 = it;
  for (int i = 0; i < it.len(); i++)
    if (it[i] != it2[i])
      return false;
  it[0] = 0;
  if (it[0] == it2[0])
    return false;
  return true;
}

// we might have a problem with the iterator
bool TestIteratorMap() {
  const iter it(new int[3]{1, 2, 3}, 3);
  iter it3(it);
  iter it2 = it.map([](int &a) { a *= 2; });
  for (int i = 0; i < it.len(); i++)
    if (it2[i] != it3[i] && it2[i] != it[i])
      return false;
  return true;
}

// we might have a problem with the iterator
bool TestIteratorFilter() {
  iter it(new int[]{1, 2, 3}, 3);
  Iterator<int *> it2 = it.filter([](int &a) { return a % 2 == 0; });
  if (it2.len() != 1)
    return false;
  if (*it2[0] != 2)
    return false;
  return true;
}

bool TestIteratorCollect() {
  iter it(new int[]{1, 2, 3}, 3);
  std::vector<int> v = it.collect<std::vector<int>>();
  if (v.size() != 3)
    return false;
  for (int i = 0; i < v.size(); i++)
    if (v[i] != i + 1)
      return false;
  return true;
}
