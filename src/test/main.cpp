#include "main.h"
#include "../include.h"

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

  // Test Playground
  Test("PlaygroundInsertEnemy", TestPlay::InsertEnemy);
  Test("PlaygroundInsertPlayer", TestPlay::InsertPlayer);
  Test("PlaygroundLose", TestPlay::Lose);
  Test("PlaygroundNearestPlayer", TestPlay::NearestPlayer);
  return 0;
}
