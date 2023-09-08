#include "main.h"

bool Test_deque_push_back() {
  deque<int> d;
  d.push_back(1);
  d.push_back(2);
  d.push_back(3);
  return d.size() == 3 && d[0] == 1 && d[1] == 2 && d[2] == 3;
}

bool Test_deque_pop_front() {
  deque<int> d;
  d.push_back(1);
  d.push_back(2);
  d.push_back(3);
  int frontElement = d.pop_front();
  return frontElement == 1 && d.size() == 2 && d[0] == 2 && d[1] == 3;
}

bool Test_deque_remove() {
  deque<int> d;
  d.push_back(1);
  d.push_back(2);
  d.push_back(3);
  d.push_back(4);
  bool removed = d.remove(3);
  return removed && d.size() == 3 && d[0] == 2 && d[1] == 1 && d[2] == 4;
}

bool Test_deque_remove_index() {
  deque<int> d;
  d.push_back(1);
  d.push_back(2);
  d.push_back(3);
  int removedElement = d.remove((u32)1); // without the cast it's ambiguous
  return removedElement == 2 && d.size() == 2 && d[0] == 1 && d[1] == 3;
}

bool Test_deque_access_operator() {
  deque<int> d;
  d.push_back(1);
  d.push_back(2);
  d.push_back(3);
  int element = d[1];
  return element == 2;
}

bool Test_deque_size() {
  deque<int> d;
  d.push_back(1);
  d.push_back(2);
  d.push_back(3);
  return d.size() == 3;
}

bool Test_deque_iter() {
  deque<int> d;
  d.push_back(1);
  d.push_back(2);
  d.push_back(3);

  int sum = 0;
  d.iter([&sum](const int &e) { sum += e; });

  return sum == 6;
}

bool Test_deque_filter() {
  deque<int> d;
  d.push_back(1);
  d.push_back(2);
  d.push_back(3);
  d.push_back(4);
  d.push_back(5);

  deque<int *> filteredDeque = d.filter([](int &e) { return e % 2 == 0; });

  return filteredDeque.size() == 2 && *filteredDeque[0] == 2 &&
         *filteredDeque[1] == 4;
}
