#include "enemy.h"

Enemy::Enemy(u32 min, u32 max, bool isFast, bool isRich)
    : h(randomInt(max, min)), a(randomInt(max, min)),
      s(randomInt(ROBOT_MAX_SPEED, ROBOT_MIN_SPEED) * (1 + isFast)),
      v(randomInt(max, min) * (1 + isRich)) {}

u32 &Enemy::getHealth() { return h; }

DamageEnemy *Enemy::attack() const { return new DamageEnemy(a); }

u32 Enemy::move() const { return s; }

void Enemy::accept(VisitorInterface *v) const { v->visitEnemy(); }

Enemy *Enemy::clone() const { return new Enemy(*this); }

EnemyDefense::EnemyDefense(u32 min, u32 max) : Enemy(min, max) {}

bool EnemyDefense::sufferDamage(DamageAbstract &d) {
  d / 2; // doesn't look good, though DamageAbstract is abstract
  u32 damage = d.damage();
  if (damage > getHealth()) {
    getHealth() = 0;
    return true;
  } else {
    getHealth() -= damage;
    return false;
  }
}

void EnemyDefense::accept(VisitorInterface *v) const { v->visitEnemyDefense(); }

EnemyDefense *EnemyDefense::clone() const { return new EnemyDefense(*this); }

EnemyBig::EnemyBig(u32 min, u32 max) : Enemy(min * 2, max * 2, false, true) {}

u32 EnemyBig::move() const { return Enemy::move() / 2; }

void EnemyBig::accept(VisitorInterface *v) const { v->visitEnemyBig(); }

EnemyBig *EnemyBig::clone() const { return new EnemyBig(*this); }
