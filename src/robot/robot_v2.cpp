#include "robot.h"

bool Robot::tmp = false;

Robot::Robot(u32 max, u32 min, bool rich)
    : Entity(random_int(max, min), random_int(max, min)),
      speed(random_int(max, min)), value(random_int(max, min) * (rich ? 2 : 1)) {}

ptr<Robot> new_generic_Robot(u32 max, u32 min = 0) {
  switch (random_int(4)) {
  case 0:
    return ptr<Robot>(Robot(max, min, true));
  case 1:
    return ptr<Robot>(DefenseRobot(max, min));
  case 2:
    return ptr<Robot>(Robot(max, min)); // sarebbe un Robot ricco
  case 3:
    return ptr<Robot>(BigRobot(max, min));
  default:
    return ptr<Robot>(Robot(max, min));
  }
}

bool Robot::takeDamage(u32 &d) {
  tmp = Entity::takeDamage(d);
  if (tmp)
    Cash::getInstance()->add(value);
  return tmp;
}

u32 Robot::move() const {
  return speed;
}

// derivated classes

FastRobot::FastRobot(u32 max, u32 min) : Robot(max, min), sprint(true) {}

u32 FastRobot::move() const { return Robot::move() / 2 * 3; }

DefenseRobot::DefenseRobot(u32 max, u32 min) : Robot(max, min) {}

bool DefenseRobot::takeDamage(u32 &damage) {
  damage /= 2;
  return Robot::takeDamage(damage);
}

BigRobot::BigRobot(u32 max, u32 min) : Robot(max * 2, min * 2, true) {}

u32 BigRobot::move() const { return Robot::move() / 4; }

