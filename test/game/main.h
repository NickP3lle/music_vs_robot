#ifndef MAIN_H
#define MAIN_H
#include "../../game/cash.h"
#include "../../game/entity.h"
#include "../../game/include.h"
#include "../../game/playground.h"
#include "../../game/timer.h"

// bool TestCashGetInstance(); // GetInstance() is private
bool TestCashAdd();
bool TestCashSub();

bool TestInsertEnemy();
bool TestInsertPlayer();
bool TestLose();
bool TestPlayerAttack();
bool TestMoveRobots();
bool TestEnemyAttack();

bool TestTimer();

#endif
