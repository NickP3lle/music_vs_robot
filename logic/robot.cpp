#include "robot.h"

Robot::Robot(u32 min, u32 max, bool isFast, bool isRich)
    : Entity(randomInt(max, min)), a(randomInt(max, min)),
      s(randomInt(max, min) * (1 + isFast)),
      v(randomInt(max, min) * (1 + isRich)) {}

bool Robot::sufferDamage(Damage *d) {
  if (d->getDamage() > getHealth()) {
    getHealth() = 0;
    return true;
  } else {
    getHealth() -= d->getDamage();
    return false;
  }
}

DamageRobot *Robot::attack() const { return new DamageRobot(a); }

u32 Robot::move() const { return s; }

void Robot::accept(VisitorGUI *v) const { v->visitRobot(); }

Robot *Robot::clone() const { return new Robot(*this); }

RobotDefense::RobotDefense(u32 min, u32 max) : Robot(min, max) {}

bool RobotDefense::sufferDamage(Damage *d) {
  d->getDamage() /= 2;
  if (d->getDamage() > getHealth()) {
    getHealth() = 0;
    return true;
  } else {
    getHealth() -= d->getDamage();
    return false;
  }
}

void RobotDefense::accept(VisitorGUI *v) const { v->visitRobotDefense(); }

RobotDefense *RobotDefense::clone() const { return new RobotDefense(*this); }

RobotBig::RobotBig(u32 min, u32 max) : Robot(min * 2, max * 2, false, true) {}

u32 RobotBig::move() const { return Robot::move() / 2; }

void RobotBig::accept(VisitorGUI *v) const { v->visitRobotBig(); }

RobotBig *RobotBig::clone() const { return new RobotBig(*this); }
