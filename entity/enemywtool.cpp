#include "enemywtool.h"

EnemyWTool::EnemyWTool(Enemy *en, Tool *to) : e(en), t(to) {}

bool EnemyWTool::isAlive() const { return e->getHealth() > 0; }

// this make EnemyWTool a factory
EnemyWTool::EnemyWTool(u32 min, u32 max)
    : EnemyWTool(getEnemy(min, max), getTool(min, max)) {}

void EnemyWTool::accept(VisitorInterface *visitor) const {
  e->accept(visitor);
  t->accept(visitor);
}

EnemyWTool *EnemyWTool::clone() const {
  return new EnemyWTool(e->clone(), t->clone());
}

u32 &EnemyWTool::getHealth() { return e->getHealth(); }

bool EnemyWTool::sufferDamage(DamageAbstract &damage) {
  t->sufferDamage(damage);
  if (e->sufferDamage(damage)) {
    Cash::add(t->value());
    return true;
  }
  return false;
}

DamageEnemy *EnemyWTool::attack() const {
  DamageEnemy *d = e->attack();
  *d = *d + t->attack();
  return d;
}

bool EnemyWTool::operator==(const EnemyWTool &other) const {
  return this->e == other.e && this->t == other.t;
}

u32 EnemyWTool::move() const { return e->move() + t->move(); }

Enemy *EnemyWTool::getEnemy(u32 min, u32 max) {
  u32 n = randomInt(1100);
  if (n < 330)
    return new Enemy(min, max);
  if (n < 500)
    return new Enemy(min, max, true);
  if (n < 700)
    return new Enemy(min, max, false, true);
  if (n < 900)
    return new Enemy(min, max, true, true);
  if (n < 1000)
    return new EnemyDefense(min, max);
  else
    return new EnemyBig(min, max);
}

Tool *EnemyWTool::getTool(u32 min, u32 max) {
  u32 n = randomInt(1000);
  if (n < 200)
    return new ToolWeapon(max, min);
  else if (n < 400)
    return new ToolArmor(max);
  else if (n < 600)
    return new ToolBoots(max);
  else if (n < 800)
    return new ToolRing(min);
  else
    return new Tool(-1);
}
