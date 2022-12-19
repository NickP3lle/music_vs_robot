#include "../robotwtool.cpp"

using namespace std;

bool TestRobotInit() {
  try {
    Robot robot = Robot(50);
  } catch (...) {
    return false;
  }
  return true;
}

bool TestRobotAttack() {
  Robot robot = Robot(50);
  u32 damage = robot.attack();
  return damage >= 0 && damage <= 50;
}

bool TestRobotTakeDamage() {
  Robot robot = Robot(50);
  u32 j;
  for (int i = 0; i < 51; i++) {
    j = 1;
    if (robot.takeDamage(j) && Cash::getInstance()->getTotal() < 50)
      return true;
  }
  return false;
}

bool TestRobotMove() {
  Robot robot = Robot(50);
  u32 speed = robot.move();
  return speed >= 0 && speed <= 50;
}

bool TestDefenseRobotTakeDamage() {
  DefenseRobot robot = DefenseRobot(50);
  tmp = 10000;
  if (robot.takeDamage(tmp) && tmp < 5000)
    return true;
  return false;
}

bool TestBigRobotInit() {
  try {
    BigRobot robot = BigRobot(50);
  } catch (...) {
    return false;
  }
  BigRobot robot = BigRobot(50);
  if (robot.move() * 4 == robot.Robot::move())
    return true;
  if (robot.attack() > 50)
    return true;
  tmp = 50;
  if (robot.takeDamage(tmp))
    return false;
  return true;
}

bool TestRandomRobot() {
  Robot robot;
  for (u32 tmp = 50; tmp < 150; tmp++) {
    robot = randomRobot(tmp, tmp / 2);
    if (robot.attack() < tmp / 2 || robot.attack() > tmp * 2) {
      cerr << "tmp: " << tmp << " attack: " << robot.attack() << "\n";
      return false;
    }
    if (robot.move() < tmp / 2 || robot.move() > tmp * 2) {
      cerr << "TestRandom Robot Move failed\n";
      return false;
    }

    u32 d;
    for (int i = 0; i < tmp / 2; i++) {
      d = 1;
      if (robot.takeDamage(d)) {
        cerr << "TestRandom Robot TakeDamage failed\n";
        return false;
      }
    }
    for (int i = tmp / 2; i < tmp; i++) {
      d = 1;
      if (robot.takeDamage(d))
        return true;
    }
  }
  cerr << "TestRandom Robot TakeDamage failed\n";
  return false;
}

bool TestRobotWToolInit() {
  try {
    RobotWTool robot(50, 50);
  } catch (...) {
    return false;
  }
  return true;
}

bool TestRobotWToolAttack() {
  for (u32 _ = 0; _ < 100; _++) {
    RobotWTool robot(50, 25);
    u32 damage = robot.attack();
    if (damage < 25 || damage > 100)
      return false;
  }
  return true;
}
