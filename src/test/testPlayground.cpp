#include "main.h"

bool TestPlay::InsertEnemy() {
  get()->insertEnemy(0, 1);
  return true;
}

bool TestPlay::InsertPlayer() {
  Playground *tmp = get();
  if (!tmp->insertPlayer(0, 0, 1))
    return false;
  if (tmp->insertPlayer(0, 0, 1))
    return false;
  if (!tmp->insertPlayer(0, 1, 1))
    return false;
  return true;
}

bool TestPlay::Lose() {
  Playground *tmp = get();
  tmp->insertEnemy(2, 59);
  for (u32 i = 0; i < 50; i++)
    tmp->moveRobots();
  return tmp->lose();
}

bool TestPlay::PlayerAttack() {
  Playground *tmp = get();

  // row 1 -- three flutes
  tmp->insertPlayer(0, 0, 0);
  tmp->insertPlayer(0, 1, 0);
  tmp->insertPlayer(0, 2, 0);
  // row 2 -- empty
  // row 3 -- 1 trumpet (should do damage on 3 rows)
  tmp->insertPlayer(2, 0, 3);
  // row 4 -- 1 drum (should do damage for 3 more columns)
  tmp->insertPlayer(3, 0, 1);
  // row 5 -- 1 violin (should slow down the first enemy)
  tmp->insertPlayer(4, 0, 4);

  u32 i = 0;
  tmp->playerAttack(i++);
  if (tmp->damage[3][1] != music::New(1)->attack())
    return false;

  // check the other instruments
  for (; i < COLUMNS; i++)
    tmp->playerAttack(i);
  if (tmp->damage[0][0] != Flute().attack() * 3)
    return false;
  if (tmp->damage[1][0] != Trumpet().attack() ||
      tmp->damage[2][0] != Trumpet().attack() ||
      tmp->damage[3][0] != Trumpet().attack())
    return false;
  if (tmp->slowDown[4] == 0)
    return false;
  return true;
}
