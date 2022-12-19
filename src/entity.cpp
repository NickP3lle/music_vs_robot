#include "entity.h"

Entity::Entity(u32 health, u32 power) : health(health), power(power) {}

// pure abstract
bool Entity::takeDamage(u32 &amount) {
    if (health > amount) {
        health -= amount;
        return false;
    }
    amount -= health;
    return true;
}

// pure abstract
u32 Entity::attack() const { return power; }

void Entity::updateHealth(u32 newHealth) { health = newHealth; }

void Entity::updatePower(u32 powerIncrease) { power += powerIncrease; }
