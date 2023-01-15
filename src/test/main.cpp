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

  // Test Playground
  Test("PlaygroundInsertEnemy", TestInsertEnemy);
  Test("PlaygroundInsertPlayer", TestInsertPlayer);
  Test("PlaygroundLose", TestLose);
  Test("PlaygroundPlayerAttack", TestPlayerAttack);
  // Test("PlaygroundEnemyAttack", TestEnemyAttack);
  // Test("PlaygroundPlayerLevelUp", TestPlayerLevelUp);
  // Test("PlaygroundDamagePropagate", TestDamagePropagate);
  //   Insert Player da segmentation fault, mi sembra un errore incomprensibile
  return 0;
}
