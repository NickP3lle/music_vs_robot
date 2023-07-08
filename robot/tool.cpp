#include "tool.h"

// cannot be bigger than 5, though it can be smaller
Tool::Tool(int d) : durability(d > 0 ? randomInt(d) % 5 + 1 : -1) {}

bool Tool::isBroken() const { return durability == 0; }

u32 Tool::attack() { return 0; }

bool Tool::takeDamage(u32 &damage) {
    if (durability > 1)
        durability--;
    return durability > 0;
}

u32 Tool::move() { return 0; }

u32 Tool::value() const { return 0; }

Tool *Tool::clone() const { return new Tool(*this); }

Weapon::Weapon(u32 max, u32 min) : Tool(max), damage(randomInt(max, min)) {}

u32 Weapon::attack() {
    if (isBroken())
        return 0;
    Weapon::takeDamage(damage);
    return damage;
}

bool Weapon::takeDamage(u32 &damage) { return false; }

Weapon *Weapon::clone() const { return new Weapon(*this); }

Armor::Armor(u32 max) : Tool(max) {}

bool Armor::takeDamage(u32 &damage) {
    if (Tool::isBroken())
        return true;
    damage = 0;
    return Tool::takeDamage(damage);
}

Armor *Armor::clone() const { return new Armor(*this); }

Boots::Boots(u32 max, u32 min) : Tool(max % 10), speed(randomInt(max, min)) {}

bool Boots::takeDamage(u32 &damage) { return false; }

u32 Boots::move() {
    if (Tool::isBroken())
        return 0;
    Tool::takeDamage(speed);
    return speed;
}

Boots *Boots::clone() const { return new Boots(*this); }

Ring::Ring(u32 max, u32 min) : Tool(-1), cash(randomInt(max, min)) {}

u32 Ring::value() const { return cash; }

Ring *Ring::clone() const { return new Ring(*this); }

std::string Tool::saveData() {
    std::string jsonString = "\"Tool\": {\n";
    jsonString += "\"durability\": " + std::to_string(durability) + "\n}";
    return jsonString;
}

// Se sono da fare bisogna fare le savedata anche pr i vari tool