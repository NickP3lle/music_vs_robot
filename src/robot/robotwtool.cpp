#pragma once
#include "robotwtool.h"

RobotWTool::RobotWTool(u32 max, u32 min)
    : Robot(randomRobot(max, min)), Tool(randomTool(max, min)) {}

u32 RobotWTool::attack() {
	return Robot::attack() + Tool::attack();
}

bool RobotWTool::takeDamage(u32 &damage) {
	Tool::takeDamage(damage);
	if (Robot::takeDamage(damage)) {
		Cash::getInstance()->add(Tool::value());
		return true;
	}
	return false;
}

u32 RobotWTool::move() {
	return Robot::move() + Tool::move();
}

u32 RobotWTool::attack() const { return 0; }
u32 RobotWTool::move() const { return 0; }
