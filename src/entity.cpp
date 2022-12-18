#include "entity.h"

Entity::Entity(u32 health, u32 power) : health(health), power(power) {}

bool Entity::takeDamage(u32 &amount) {
    if (health > amount) {
        health -= amount;
        return false;
    }
    amount -= health;
    return true;
}

void Entity::updateHealth(u32 newHealth) { health = newHealth; }

void Entity::updatePower(u32 powerIncrease) { power += powerIncrease; }