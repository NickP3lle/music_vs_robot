#include "Robot.h"

namespace {
ptr<Tool> new_none() { return ptr<Tool>(nullptr); }

ptr<Tool> new_weapon(u32 max, u32 min = 0) {
  return ptr<Tool>(weapon(random_int(max, min), random_int(max, min)));
}

ptr<Tool> new_shield(u32 max, u32 min = 0) {
  return ptr<Tool>(shield(random_int(max, min)));
}

ptr<Tool> new_speed(u32 max, u32 min = 0) {
  return ptr<Tool>(speed(random_int(max, min), random_int(max, min)));
}

ptr<Tool> new_ring(u32 max, u32 min = 0) {
  return ptr<Tool>(ring(random_int(max, min), random_int(max, min)));
}

ptr<Tool> newTool(u32 max, u32 min = 0) {
  switch (random_int(5)) {
  case 0:
    return new_none();
  case 1:
    return new_ring(max, min);
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

Robot::Robot(u32 max, u32 min)
    : Entity(random_int(max, min), random_int(max, min)),
      speed(random_int(max, min)), value(random_int(max, min)),
      good(newTool(max, min)) {}

ptr<Robot> new_generic_Robot(u32 max, u32 min = 0) {
  switch (random_int(4)) {
  case 0:
    return ptr<Robot>(FastRobot(max, min));
  case 1:
    return ptr<Robot>(DefenseRobot(max, min));
  case 2:
    return ptr<Robot>(RichRobot(max, min));
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

RichRobot::RichRobot(u32 max, u32 min) : Robot(max, min) {}

BigRobot::BigRobot(u32 max, u32 min) : Robot(max * 2, min * 2) {}

u32 BigRobot::move() const { return Robot::move() / 4; }
