#include "entity.h"

Entity::Entity(u32 health, u32 power):
	health(health), power(power) {}

bool Entity::take_damage(u32& amount) {
	if (health > amount) {
		health -= amount;
		return false;
	}
	amount -= health;
	return true;
}
