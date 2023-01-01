#include "robot.h"

namespace {
u32 tmp;
}

// randomInt(max, min): max == min => max
Robot::Robot(u32 max, u32 min, bool fast, bool rich)
    : Entity(randomInt(max, min), randomInt(max, min)),
      speed((fast ? 2 : 1) * (randomInt(10) + 5)), // 5-15
      value((rich ? 2 : 1) * randomInt(max, min)) {}

u32 Robot::attack() const { return getPower(); }

bool Robot::takeDamage(u32 &damage) {
  tmp = Entity::takeDamage(damage);
  if (tmp)
    Cash::getInstance()->add(value);
  return tmp;
}

u32 Robot::move() const { return speed; }

DefenseRobot::DefenseRobot(u32 max, u32 min) : Robot(max, min) {}

bool DefenseRobot::takeDamage(u32 &damage) {
  damage /= 2;
  return Robot::takeDamage(damage);
}

BigRobot::BigRobot(u32 max, u32 min) : Robot(max * 2, max, false, true) {}

u32 BigRobot::move() const { return Robot::move() / 4; }

Robot randomRobot(u32 max, u32 min = 0) {
  tmp = randomInt(1000);
  if (tmp < 500)
    return Robot(max, min);
  if (tmp < 833)
    return Robot(max, min, true);
  if (tmp < 900)
    return Robot(max, min, false, true);
  if (tmp < 950)
    return Robot(max, min, true, true);
  if (tmp < 976)
    return DefenseRobot(max, min);
  else
    return BigRobot(max, min);
}
