#include "../robot.h"

bool TestRobotInit() {
  Robot robot = Robot(50, false);
  if (!(robot.attack() < 50) || !(robot.move() < 50)) return false;
  u32 j;
  for (int i = 0; i < 51; i++) {
    j = 1;
    if (robot.takeDamage(j) && Cash::getInstance()->getTotal() < 50)
      return true;
  }
  return false;
}

int main() {
	std::cout << "TestRobotInit: " << (TestRobotInit() ? "Passed" : "Failed") << "\n";
	return 0;
}
