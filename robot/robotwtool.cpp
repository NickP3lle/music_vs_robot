#include "robotwtool.h"

RobotWTool::RobotWTool(u32 max, u32 min) : robot(randomRobot(max, min)), tool(randomTool(max, min)) {}

RobotWTool::RobotWTool() : robot(nullptr), tool(nullptr) {}

RobotWTool::RobotWTool(const RobotWTool &r) {
    if (r.robot)
        robot = ptr_robot(r.robot->clone());
    if (r.tool)
        tool = ptr_tool(r.tool->clone());
}

RobotWTool &RobotWTool::operator=(const RobotWTool &r) {
    if (this != &r) {
        this->~RobotWTool();
        if (r.robot)
            robot = ptr_robot(r.robot->clone());
        if (r.tool)
            tool = ptr_tool(r.tool->clone());
    }
    return *this;
}

u32 RobotWTool::attack() { return robot->attack() + tool->attack(); }

bool RobotWTool::takeDamage(u32 &damage) {
    tool->takeDamage(damage);
    if (robot->takeDamage(damage)) {
        Cash::add(tool->value());
        return true;
    }
    return false;
}

u32 RobotWTool::move() { return robot->move() + tool->move(); }

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

Robot *RobotWTool::getRobot() const { return &*robot; }

bool RobotWTool::isAlive() const { return (bool)&*robot; }

std::string RobotWTool::saveData() {
    // funziona con get_mut() o devo usare getPtr per avere il polimorfismo?
    std::string tmp = "{\n \"name\": \"RobotWTool\",\n";
    tmp += robot->saveData() + ",\n" + tool->saveData() + "\n}";
    return tmp;
}

RobotWTool *RobotWTool::loadData(std::string data) {
    std::cout << data << std::endl;
    return nullptr;
}