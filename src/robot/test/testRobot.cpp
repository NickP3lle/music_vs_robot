#include "main.h"

bool TestRobotAttack() {
  Robot robot = Robot(50, 50);
  return robot.attack() == 50;
}

bool TestRobotTakeDamage() {
  Robot robot = Robot(50, 50);
  tmp = 49;
  if (robot.takeDamage(tmp))
	  return false;
  if (robot.takeDamage(++tmp))
	  return true;
  return false;
}

bool TestRobotMove() {
  Robot robot = Robot(5, 5 /*, false, false */);
  if (robot.move() > 4 && robot.move() < 16) return true;
  return false;
}

bool TestDefenseRobotTakeDamage() {
  DefenseRobot robot = DefenseRobot(50, 50);
  tmp = 10000;
  if (robot.takeDamage(tmp) && tmp < 5000)
    return true;
  return false;
}

bool TestBigRobotInit() {
    BigRobot robot = BigRobot(50, 50);
  if (robot.move() != robot.Robot::move() / 4)
    return false;
  if (robot.attack() > 100 && robot.attack() < 50)
    return false;
  tmp = 49;
  if (robot.takeDamage(tmp))
    return false;
  tmp = 51;
  if (!robot.takeDamage(tmp) && tmp > 50)
	return false;
  return true;
}

bool TestRandomRobot() {
  Robot robot;
  for (u32 tmp = 50; tmp < 150; tmp++) {
    robot = randomRobot(tmp, tmp / 2);
    if (robot.attack() < tmp / 2 || robot.attack() > tmp * 2) {
      return false;
    }
    if (robot.move() < 4|| robot.move() > 16) {
      return false;
    }

    u32 d;
    for (int i = 0; i < tmp / 2; i++) {
      d = 1;
      if (robot.takeDamage(d)) {
        return false;
      }
    }
    for (int i = tmp / 2; i < tmp; i++) {
      d = 1;
      if (robot.takeDamage(d))
        return true;
    }
  }
  return false;
}

bool TestRobotWToolAttack() {
  for (u32 _ = 0; _ < 100; _++) {
    RobotWTool robot(50, 50);
    tmp = robot.attack();
    if (tmp < 50 || tmp > 100)
      return false;
  }
  return true;
}
