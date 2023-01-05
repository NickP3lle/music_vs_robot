#include "main.h"
#include "../include.h"

// #include <sys/resource.h>
// might be cool to check memory usage
// next thing is going to be cpu usage

int main() {
  // Test Cash
  Test("CashGetInstance", TestCashGetInstance);
  Test("CashAdd", TestCashAdd);
  Test("CashSub", TestCashSub);
  std::cout << "\n";

  // Test Entity
  Test("EntityInit", TestEntityInit);
  Test("EntityTakeDamage", TestEntityTakeDamage);
  Test("EntityUpdateHealth", TestEntityUpdateHealth);
  Test("EntityUpdatePower", TestEntityUpdatePower);
  std::cout << "\n";

  // Test Playground
  Test("PlaygroundInsertEnemy", TestPlay::InsertEnemy);
  Test("PlaygroundInsertPlayer", TestPlay::InsertPlayer);
  Test("PlaygroundLose", TestPlay::Lose);
  Test("PlaygroundPlayerAttack", TestPlay::PlayerAttack);
  Test("PlaygroundMoveRobots", TestPlay::MoveRobots);
  return 0;
}
