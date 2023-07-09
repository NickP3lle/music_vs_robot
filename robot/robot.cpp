#include "robot.h"

// randomInt(max, min): max == min => max
Robot::Robot(u32 max, u32 min, bool fast, bool rich)
    : Entity(randomInt(max, min), randomInt(max, min)),
      speed((fast ? 2 : 1) * (randomInt(ROBOT_MAX_SPEED, ROBOT_MIN_SPEED))), value((rich ? 2 : 1) * randomInt(max, min)) {}

bool Robot::takeDamage(u32 &damage) {
    if (Entity::getHealth() > damage) {
        Entity::getHealth() -= damage;
        damage = 0;
        return false;
    }
    Cash::add(value);
    damage -= Entity::getHealth();
    return true;
}

u32 Robot::attack() const { return const_cast<Robot *>(this)->Entity::getPower(); }

u32 Robot::move() const { return speed; }

Robot *Robot::clone() const { return new Robot(*this); }

DefenseRobot::DefenseRobot(u32 max, u32 min) : Robot(max, min) {}

bool DefenseRobot::takeDamage(u32 &damage) {
    damage /= 2;
    return Robot::takeDamage(damage);
}

DefenseRobot *DefenseRobot::clone() const { return new DefenseRobot(*this); }

BigRobot::BigRobot(u32 max, u32 min) : Robot(max * 2, min * 2, false, true) {}

u32 BigRobot::move() const { return Robot::move() / 2; }

BigRobot *BigRobot::clone() const { return new BigRobot(*this); }

void Robot::accept(EntityVisitorInterface &visitor) const { visitor.visitRobot(); }

std::string Robot::saveData() const {
    std::string tmp;
    if (typeid(*this) == typeid(Robot)) {
        tmp += "\"Robot\": {\n";
    } else if (typeid(*this) == typeid(DefenseRobot)) {
        tmp += "\"DefenseRobot\": {\n";
    } else if (typeid(*this) == typeid(BigRobot)) {
        tmp += "\"BigRobot\": {\n";
    } else {
        throw std::runtime_error("Errore nel salvataggio dei dati");
    }
    tmp += Entity::saveData() + ",\n";
    tmp += "\"speed\": " + std::to_string(speed) + ",\n";
    tmp += "\"value\": " + std::to_string(value);
    tmp += "\n}";
    return tmp;
}

Robot *Robot::loadData(std::string data) {
    std::cout << data << std::endl;
    return nullptr;
}