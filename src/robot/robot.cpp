#include "robot.h"

namespace {
ptr<Tool> new_none() { return ptr<Tool>(nullptr); }

ptr<Tool> new_weapon(u32 max, u32 min = 0) {
  return ptr<Tool>(Weapon(random_int(max, min), random_int(max, min)));
}

ptr<Tool> new_shield(u32 max, u32 min = 0) {
  return ptr<Tool>(Shield(random_int(max, min)));
}

ptr<Tool> new_speed(u32 max, u32 min = 0) {
  return ptr<Tool>(Speed(max, min));
}

/*
ptr<Tool> new_ring(u32 max, u32 min = 0) {
  return ptr<Tool>(Ring(max, min));
}
*/

ptr<Tool> newTool(u32 max, u32 min = 0) {
  switch (random_int(5)) {
  case 0:
    return new_none();
 // case 1:
 //   return new_ring(max, min);
  case 2:
    return new_shield(max, min);
  case 3:
    return new_speed(max, min);
  default:
    return new_weapon(max, min);
  }
}
} // namespace

bool Robot::tmp = false;

Robot::Robot(u32 max, u32 min, bool rich)
    : Entity(random_int(max, min), random_int(max, min)),
      speed(random_int(max, min)), value(random_int(max, min) * (rich ? 2 : 1)),
      good(ptr<Tool>(newTool(max, min))) {}

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

u32 Robot::attack() const {
  return (good.isPtr() ? good.get().attack() : 0) + Entity::attack();
}

bool Robot::takeDamage(u32 &d) {
  if (good.isPtr() && good.get_mut().takeDamage(d))
    good.free();
  tmp = Entity::takeDamage(d);
  if (tmp)
    Cash::getInstance()->add(value);
  return tmp;
}

u32 Robot::move() const {
  return (good.isPtr() ? good.get().move() : 0) + speed;
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
