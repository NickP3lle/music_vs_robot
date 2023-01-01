#include "main.h"

bool TestPlay::InsertEnemy() {
  get()->insertEnemy(0, 1);
  return true;
}

bool TestPlay::InsertPlayer() {
  Drum tmp = Drum();
  get()->insertPlayer(0, 0, &tmp);
  return true;
}

bool TestPlay::Lose() {
  get()->insertEnemy(0, 100);
  while (!Get()->lose())
    Get()->moveRobots();
  return true;
}

bool TestPlay::NearestPlayer() {
  get()->insertEnemy(0, 1);
  Get()->insertPlayer(0, 9, new Drum());
  for (u32 i = 0; i < 70; i++) {
	Get()->print(std::cout);
    Get()->moveRobots();
  }
  return !Get()->lose();
}
