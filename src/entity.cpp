#include "entity.h"

Entity::Entity(u32 health, u32 power) : health(health), power(power) {}

u32 &Entity::getHealth() { return health; }

u32 &Entity::getPower() { return power; }

// Perchè vengono restituiti per riferimento?