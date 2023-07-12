#include "main.h"

int main() {
  Test("deque push back: ", Test_deque_push_back);
  Test("deque pop front: ", Test_deque_pop_front);
  Test("deque remove: ", Test_deque_remove);
  Test("deque remove index: ", Test_deque_remove_index);
  Test("deque access operator: ", Test_deque_access_operator);
  Test("deque size: ", Test_deque_size);
  Test("deque iter: ", Test_deque_iter);
  Test("deque filter: ", Test_deque_filter);
  return 0;
}
