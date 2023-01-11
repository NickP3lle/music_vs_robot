#include "robot.h"

namespace {
u32 tmp;
}

// randomInt(max, min): max == min => max
Robot::Robot(u32 max, u32 min, bool fast, bool rich)
    : Entity(randomInt(max, min), randomInt(max, min)),
      speed((fast ? 2 : 1) * (randomInt(32, 20))), // i robot si muovono una
                                                   // volta per ogni colonna =>
                                                   // questo numero dovrebbe
                                                   // essere un multiplo del
                                                   // numero di colonne
                                                   // tra 20 e 32
      value((rich ? 2 : 1) * randomInt(max, min)) {}

bool Robot::takeDamage(u32 &damage) {
  tmp = Entity::takeDamage(damage);
  if (tmp)
    Cash::getInstance()->add(value);
  return tmp;
}

u32 Robot::move() const { return speed; }

Robot *Robot::clone() const { return new Robot(*this); }

DefenseRobot::DefenseRobot(u32 max, u32 min) : Robot(max, min) {}

bool DefenseRobot::takeDamage(u32 &damage) {
  damage /= 2;
  return Robot::takeDamage(damage);
}

DefenseRobot *DefenseRobot::clone() const { return new DefenseRobot(*this); }

BigRobot::BigRobot(u32 max, u32 min) : Robot(max * 2, max, false, true) {}

u32 BigRobot::move() const { return Robot::move() / 4; }

BigRobot *BigRobot::clone() const { return new BigRobot(*this); }

Robot *randomRobot(u32 max, u32 min = 0) {
  tmp = randomInt(1000);
  if (tmp < 500)
    return new Robot(max, min);
  if (tmp < 833)
    return new Robot(max, min, true);
  if (tmp < 900)
    return new Robot(max, min, false, true);
  if (tmp < 950)
    return new Robot(max, min, true, true);
  if (tmp < 976)
    return new DefenseRobot(max, min);
  else
    return new BigRobot(max, min);
}
