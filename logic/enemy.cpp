#include "enemy.h"

Enemy::Enemy(u32 min, u32 max, bool isFast, bool isRich)
    : h(randomInt(max, min)), a(randomInt(max, min)),
      s(randomInt(max, min) * (1 + isFast)),
      v(randomInt(max, min) * (1 + isRich)) {}

DamageEnemy *Enemy::attack() const { return new DamageEnemy(a); }

u32 Enemy::move() const { return s; }

void Enemy::accept(VisitorGUI *v) const { v->visitEnemy(); }

Enemy *Enemy::clone() const { return new Enemy(*this); }

EnemyDefense::EnemyDefense(u32 min, u32 max) : Enemy(min, max) {}

bool EnemyDefense::sufferDamage(DamageAbstract *d) {
  d->getDamage() /= 2;
  if (d->getDamage() > getHealth()) {
    getHealth() = 0;
    return true;
  } else {
    getHealth() -= d->getDamage();
    return false;
  }
}

void EnemyDefense::accept(VisitorGUI *v) const { v->visitEnemyDefense(); }

EnemyDefense *EnemyDefense::clone() const { return new EnemyDefense(*this); }

EnemyBig::EnemyBig(u32 min, u32 max) : Enemy(min * 2, max * 2, false, true) {}

u32 EnemyBig::move() const { return Enemy::move() / 2; }

void EnemyBig::accept(VisitorGUI *v) const { v->visitEnemyBig(); }

EnemyBig *EnemyBig::clone() const { return new EnemyBig(*this); }
