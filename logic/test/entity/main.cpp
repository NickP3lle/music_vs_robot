#include "test_enemy.h"
#include "test_enemywtool.h"
#include "test_player.h"
#include "test_tool.h"

int main() {
  Test("Tool isBroken: ", Test_Tool_isBroken);
  Test("Tool attack: ", Test_Tool_attack);
  Test("Tool move: ", Test_Tool_move);
  Test("Tool value: ", Test_Tool_value);

  Test("ToolWeapon attack: ", Test_ToolWeapon_attack);
  Test("ToolWeapon sufferDamage: ", Test_ToolWeapon_sufferDamage);

  Test("ToolArmor sufferDamage: ", Test_ToolArmor_sufferDamage);

  Test("ToolBoots sufferDamage: ", Test_ToolBoots_sufferDamage);
  Test("ToolBoots move: ", Test_ToolBoots_move);

  Test("ToolRing valueInRange: ", Test_ToolRing_valueInRange);
  std::cout << "\n";

  Test("Enemy attack: ", Test_Enemy_attack);
  Test("Enemy move: ", Test_Enemy_move);
  Test("Enemy accept: ", Test_Enemy_accept);

  Test("EnemyDefense sufferDamage: ", Test_EnemyDefense_sufferDamage);

  Test("EnemyBig move: ", Test_EnemyBig_move);
  std::cout << "\n";

  Test("EnemyWTool attack: ", Test_EnemyWTool_attack);
  Test("EnemyWTool move: ", Test_EnemyWTool_move);
  std::cout << "\n";

  Test("Sample toString: ", Test_Sample_toString);
  Test("Sample attack: ", Test_Sample_attack);
  Test("Sample levelUp: ", Test_Sample_levelUp);
  Test("Sample getCost: ", Test_Sample_getCost);

  Test("ThreeColumn toString: ", Test_ThreeColumn_toString);
  Test("ThreeColumn attack: ", Test_ThreeColumn_attack);
  Test("ThreeColumn levelUp: ", Test_ThreeColumn_levelUp);
  Test("ThreeColumn getCost: ", Test_ThreeColumn_getCost);

  Test("DoubleLife toString: ", Test_DoubleLife_toString);
  Test("DoubleLife attack: ", Test_DoubleLife_attack);
  Test("DoubleLife sufferDamage: ", Test_DoubleLife_sufferDamage);
  Test("DoubleLife levelUp: ", Test_DoubleLife_levelUp);
  Test("DoubleLife getCost: ", Test_DoubleLife_getCost);

  Test("ThreeRow toString: ", Test_ThreeRow_toString);
  Test("ThreeRow attack: ", Test_ThreeRow_attack);
  Test("ThreeRow levelUp: ", Test_ThreeRow_levelUp);
  Test("ThreeRow getCost: ", Test_ThreeRow_getCost);

  Test("SlowDown toString: ", Test_SlowDown_toString);
  Test("SlowDown attack: ", Test_SlowDown_attack);
  Test("SlowDown levelUp: ", Test_SlowDown_levelUp);
  Test("SlowDown getCost: ", Test_SlowDown_getCost);
  return 0;
}
