#pragma once
#include "robotwtool.h"

RobotWTool::RobotWTool(u32 max, u32 min)
    : robot(randomRobot(max, min)), tool(randomTool(max, min)) {}

u32 RobotWTool::attack() {
	return robot.get().attack() + tool.get_mut().attack();
}

bool RobotWTool::takeDamage(u32 &damage) {
	tool.get_mut().takeDamage(damage);
	if (robot.get_mut().takeDamage(damage)) {
		Cash::getInstance()->add(tool.get_mut().value());
		return true;
	}
	return false;
}

u32 RobotWTool::move() {
	return robot.get().move() + tool.get_mut().move();
}
