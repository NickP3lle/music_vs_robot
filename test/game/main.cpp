#include "main.h"

// #include <sys/resource.h>
// might be cool to check memory usage
// next thing is going to be cpu usage

int main() {
  // Test Cash
  //  Test("CashGetInstance", TestCashGetInstance); // GetInstance() is private
  Test("CashAdd", TestCashAdd);
  Test("CashSub", TestCashSub);
  std::cout << "\n";

  // Test Playground
  Test("PlaygroundInsertEnemy", TestInsertEnemy);
  Test("PlaygroundInsertPlayer", TestInsertPlayer);
  Test("PlaygroundLose", TestLose);
  Test("PlaygroundPlayerAttack", TestPlayerAttack);
  Test("PlaygroundEnemyAttack", TestEnemyAttack);
  return 0;
}
