#include "main.h"

// simplest possible implementation of Entity
// to test each method
class TestEntity : public Entity {
private:
  int hello;
public:
  void updateHealth(u32 h) { Entity::updateHealth(h); }
  void updatePower(u32 a) { Entity::updatePower(a); }

  TestEntity(u32 h, u32 p) : Entity(h, p), hello(9) {}

  bool takeDamage(u32 &d) override { return Entity::takeDamage(d); }

  u32 attack() const override { return Entity::attack(); }
};


bool TestEntityInit() {
  try {
    TestEntity e(100, 10);
  } catch (...) {
    return false;
  }
  if (TestEntity(100, 10).attack() != 10)
    return false;
  return true;
}

bool TestEntityTakeDamage() {
  TestEntity e(100, 10);
  u32 d = 50;
  if (e.takeDamage(d) || !d)
    return false;
  d = 50;
  if (!e.takeDamage(d))
    return false;
  return true;
}

bool TestEntityUpdateHealth() {
  TestEntity e(100, 10);
  e.updateHealth(50);
  u32 d(50);
  if (e.takeDamage(d))
    return true;
  return false;
}

bool TestEntityUpdatePower() {
  TestEntity e(100, 10);
  e.updatePower(50);
  if (e.attack() != 60)
	return false;
  return true;
}
