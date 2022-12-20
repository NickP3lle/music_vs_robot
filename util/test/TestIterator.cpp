#include "../deque.h"
#include "../iterator.h"

typedef deque<int> D;
typedef Iterator<int> iter;

namespace {
int fun(const int &a) { return a + 1; }
} // namespace

bool TestIterator() {
  D d;
  d.push_back(1).push_back(2).push_back(3);
  std::cout << d << "\n";
  iter it = d.map(fun); // non ritorna il valorfe che gli passo
  std::cout << it << "\n";
  return true;
}
