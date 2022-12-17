#include "Robot.h"
// TODO: Robot::Robot(u32 d), forse va riscritto

namespace {
ptr<Tool> new_none(u32 d) { return ptr<Tool>(nullptr); }

ptr<Tool> new_weapon(u32 d) {
  return ptr<Tool>(weapon(random_int(d), random_int(d)));
}

ptr<Tool> new_shield(u32 d) { return ptr<Tool>(shield(random_int(d))); }

ptr<Tool> new_speed(u32 d) {
  return ptr<Tool>(speed(random_int(d), random_int(d)));
}

ptr<Tool> new_ring(u32 d) {
  return ptr<Tool>(ring(random_int(d), random_int(d)));
}

ptr<Tool> newTool(u32 d) {
  switch (random_int(5)) {
  case 0:
    return new_none(d);
  case 1:
    return new_ring(d);
  case 2:
    return new_shield(d);
  case 3:
    return new_speed(d);
  default:
    return new_weapon(d);
  }
}
} // namespace

Robot::Robot(const std::vector<u32> &i)
    : Entity(i[0], i[1]), speed(i[2]), value(i[3]), good(newTool(i[4])) {}

Robot::Robot(u32 d)
    : Entity(random_int(d), random_int(d)), speed(random_int(d)),
      value(random_int(d)), good(newTool(d)) {}

void Robot::destroyed() const { Cash::getInstance()->Cash::add(value); }

ptr<Robot> new_generic_Robot(u32 d) {
  switch (random_int(4)) {
  case 0:
    return ptr<Robot>(FastRobot(d));
  case 1:
    return ptr<Robot>(DefenseRobot(d));
  case 2:
    return ptr<Robot>(RichRobot(d));
  case 3:
    return ptr<Robot>(BigRobot(d));
  default:
    return ptr<Robot>(Robot(d));
  }
}

u32 Robot::attack() const {
  return (good.isPtr() ? good.get().attack() : 0) + Entity::attack();
}

bool Robot::takedamage(u32 &d) {
  if (good.isPtr() && good.get_mut().take_damage(d))
    good.free();
  return Entity::takedamage(d);
}

u32 Robot::move() const {
  return (good.isPtr() ? good.get().move() : 0) + speed;
}

// derivated classes

FastRobot::FastRobot(u32 d) : Robot(d), sprint(true) {}

u32 FastRobot::move() const { return Robot::move() / 2 * 3; }

DefenseRobot::DefenseRobot(u32 d) : Robot(d) {}

bool DefenseRobot::takedamage(u32 &damage) {
  damage /= 2;
  return Robot::takedamage(damage);
}

RichRobot::RichRobot(u32 d) : Robot(d) {}

BigRobot::BigRobot(u32 d)
    : Robot({random_int(d), random_int(d), random_int(d), random_int(d * 2),
             random_int(d * 2)}) {}

void BigRobot::destroyed() const { Cash::getInstance()->Cash::add(value * 2); }

u32 BigRobot::move() const { return Robot::move() / 2; }

u32 BigRobot::attack() const { return Robot::attack() * 2; }

bool BigRobot::takedamage(u32 &damage) {
  u32 d = damage;
  bool tmp = Robot::takedamage(d);
  if (d)
    damage -= (damage - d) * 2;
  return tmp;
}
