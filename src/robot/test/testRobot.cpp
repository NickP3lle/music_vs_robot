#include "main.h"

bool TestRobotAttack() {
  Robot robot = Robot(50, 50);
  return robot.attack() == 50;
}

bool TestRobotTakeDamage() {
  Robot robot = Robot(50, 50);
  u32 tmp;
  tmp = 49;
  if (robot.takeDamage(tmp))
    return false;
  if (robot.takeDamage(++tmp))
    return true;
  return false;
}

bool TestRobotMove() {
  Robot robot = Robot(5, 5 /*, false, false */);
  if (robot.move() < 20 && robot.move() > 32)
    return false;
  robot = Robot(5, 5, true);
  if (robot.move() < 40 && robot.move() > 64)
    return false;
  return true;
}

bool TestDefenseRobotTakeDamage() {
  DefenseRobot robot = DefenseRobot(50, 50);
  u32 tmp;
  tmp = 10000;
  if (robot.takeDamage(tmp) && tmp < 5000)
    return true;
  return false;
}

bool TestBigRobotInit() {
  BigRobot robot = BigRobot(50, 50);
  u32 tmp;
  if (robot.move() != robot.Robot::move() / 2)
    return true;
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

// per testare questa funzione, il metodo randomRobot dovrebbe essere pubblico
/*
bool TestRandomRobot() {
  Robot *robot;
  for (u32 tmp = 50; tmp < 1500; tmp++) {
    robot = RobotWTool::randomRobot(tmp, tmp / 2);
    if (robot->attack() < tmp / 2 || robot->attack() > tmp * 2) {
      std::cout << "on attack()";
      return false;
    }
    if (robot->move() < 10 || robot->move() > 64) {
      return false;
    }

    u32 d;
    for (int i = 0; i < tmp / 4 - 1; i++) {
      d = 2;
      if (robot->takeDamage(d)) {
        std::cout << "take damage";
        return false;
      }
    }
    delete robot;
  }
  return true;
}
*/

bool TestRobotWToolAttack() {
  u32 tmp;
  for (u32 _ = 0; _ < 100; _++) {
    RobotWTool robot(50, 50);
    tmp = robot.attack();
    if (tmp < 50 || tmp > 100)
      return false;
  }
  return true;
}
