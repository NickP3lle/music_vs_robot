#include "TestCash.cpp"
#include "TestEntity.cpp"
#include "../../util/util.h"

using namespace std;

int main() {
  // Test Cash
  Test("CashGetInstance", TestCashGetInstance);
  Test("CashAdd", TestCashAdd);
  Test("CashSub", TestCashSub);

  // Test Entity
  Test("EntityInit", TestEntityInit);
  Test("EntityTakeDamage", TestEntityTakeDamage);
  Test("EntityUpdateHealth", TestEntityUpdateHealth);
  Test("EntityUpdatePower", TestEntityUpdatePower);

  // TODO Test Playground
  return 0;
}
