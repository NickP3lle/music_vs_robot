#include "robotwtool.h"

RobotWTool::RobotWTool(u32 max, u32 min) : robot(randomRobot(max, min)), tool(randomTool(max, min)) {}

RobotWTool::RobotWTool() : robot(nullptr), tool(nullptr) {}

u32 RobotWTool::attack() { return robot.get().attack() + tool.get_mut().attack(); }

bool RobotWTool::takeDamage(u32 &damage) {
    tool.get_mut().takeDamage(damage);
    if (robot.get_mut().takeDamage(damage)) {
        Cash::getInstance()->add(tool.get().value());
        return true;
    }
    return false;
}

u32 RobotWTool::move() { return robot.get().move() + tool.get_mut().move(); }

// this function generate a random robot
Robot *RobotWTool::randomRobot(u32 max, u32 min = 0) {
    u32 tmp = randomInt(110);
    if (tmp < 33)
        return new Robot(max, min);
    if (tmp < 50)
        return new Robot(max, min, true);
    if (tmp < 70)
        return new Robot(max, min, false, true);
    if (tmp < 90)
        return new Robot(max, min, true, true);
    if (tmp < 100)
        return new DefenseRobot(max, min);
    else
        return new BigRobot(max, min);
}

// this function generate a random tool
Tool *RobotWTool::randomTool(u32 max, u32 min) {
    switch (randomInt(5)) {
    case 0:
        return new Weapon(max, min);
    case 1:
        return new Armor(max);
    case 2:
        return new Boots(max, min);
    case 3:
        return new Ring(max, min);
    default:
        return new Tool(-1); // nessun oggetto
    }
    return new Tool(-1); // nessun oggetto
}

Robot *RobotWTool::getRobot() const { return robot.getPtr(); }