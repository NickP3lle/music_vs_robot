#include "main.h"

bool TestPlay::InsertEnemy() {
  get()->insertEnemy(0, 1);
  return true;
}

bool TestPlay::InsertPlayer() {
  Drum tmp = Drum();
  if (!get()->insertPlayer(0, 0, &tmp))
    return false;
  if (!Get()->insertPlayer(0, 1, &tmp))
    return false;
  return (!Get()->insertPlayer(0, 0, &tmp));
}

bool TestPlay::Lose() {
  get()->insertEnemy(0, 100);
  while (!Get()->lose())
    Get()->moveRobots();
  return true;
}

bool TestPlay::PlayerAttack() {
  Playground *tmp = get();

  // row 1 -- three flutes
  MusicInstruments *mi = new Flute();
  tmp->insertPlayer(0, 0, mi);
  tmp->insertPlayer(0, 1, mi);
  tmp->insertPlayer(0, 2, mi);
  // row 2 -- empty
  // row 3 -- 1 trumpet (should do damage on 3 rows)
  *mi = Trumpet();
  tmp->insertPlayer(2, 0, mi);
  // row 4 -- 1 drum (should do damage for 3 more columns)
  *mi = Drum();
  tmp->insertPlayer(3, 0, mi);
  // row 5 -- 1 violin (should slow down the first enemy)
  *mi = Violin();
  tmp->insertPlayer(4, 0, mi);

  u32 i = 0;
  // check drum
  for (; i < 3; i++)
    tmp->playerAttack(i++);
  std::cout << "\n";
  for (u32 j = 0; j < ROWS; j++)
    std::cout << tmp->damage[j][0] << " " << tmp->damage[j][1] << " "
              << tmp->slowDown[i] << std::endl;
  std::cout << Drum().attack() << std::endl;
  // check the other instruments
  for (; i < COLUMNS; i++)
    tmp->playerAttack(i);
  if (tmp->damage[0][1] != Flute().attack() * 3 ||
      tmp->damage[1][1] != Trumpet().attack() ||
      tmp->damage[2][0] != Trumpet().attack() ||
      tmp->damage[3][0] != Trumpet().attack() || tmp->slowDown[1] != 0)
    return false;
  return true;
}

bool TestPlay::MoveRobots() {
  get()->insertEnemy(0, 1);
  Get()->insertPlayer(0, 9, new Drum());
  for (u32 i = 0; i < 70; i++)
    Get()->moveRobots();
  return !Get()->lose();
}
