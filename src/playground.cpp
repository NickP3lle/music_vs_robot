#include "playground.h"

Playground *Playground::instance = nullptr;

Playground::Playground() : damagePos(0) {
  initPlayer();
  initEnemy();
  reset();
}

void Playground::initPlayer() {
  for (auto &row : instance->player) {
    for (auto &col : row) {
      col = ptr<MusicInstruments>();
    }
  }
}

void Playground::initEnemy() {
  for (auto &row : instance->enemy) {
    for (auto &col : row) {
      col = deque<RobotWTool>(2);
    }
  }
}

void Playground::reset() {
	std::for_each(&damage[0], &damage[0] + ROWS, [](u32 &d) { d = 0; });
}

Playground *Playground::getInstance() {
  if (instance == nullptr) {
    instance = new Playground();
  }
  return instance;
}

// controlla che non ci siano zombie nelle celle più a sinistra
bool Playground::lose() const {
  bool lose = false;
  std::for_each(&enemy[0], &enemy[ROWS],
                [&lose](const deque<RobotWTool>(&d)[FRAME_COLUMNS * COLUMNS]) {
                  if (d[0].len() > 0) {
                    lose = true;
                  }
                });
  return lose;
}

void Playground::attack(u32 colonna) {
  playerAttack(colonna);
  damagePropagate(colonna);
  enemyAttack(colonna);
}

// calcola il danno sulla colonna che gli passi per l'intera riga
void Playground::playerAttack(u32 col) {
  for (u32 i = 0; i < ROWS; i++) {
    if (player[i][col].isPtr())
      damage[col] += player[i][col].get().attack();
    if (i > 0 && player[i - 1][col].isPtr() /* dyanmic cast */)
      damage[col] += player[i - 1][col].get().attack();
    if (i < ROWS - 1 && player[i + 1][col].isPtr() /* dyanmic cast */)
      damage[col] += player[i + 1][col].get().attack();
  }
}

// se c'è una pianta in questa cella e c'è almeno uno zombie, gli zombie
// attaccano la pianta, controlla tutte le righe
//
// NB se i danni non sono nulli allora tutti gli zombie sono morti
void Playground::enemyAttack(u32 col) {
  for (u32 row = 0; row < ROWS; row++) {
    if (player[row][col].isNone() || damage[row] > 0)
      return;
    iterRobot(row, col, [&damage = damage[row]](deque<RobotWTool> &d) {
      d.iter().map([&damage](Entity &e) { damage += e.attack(); });
    });
    player[row][col].get_mut().takeDamage(damage[row]);
    damage[row] = 0;
  }
}

// per ogni riga controlla se in questa colonna c'è un robot
// finchè damage[riga] > 0 e ci sono dei robot infligge del danno
// ai robot. Se il robot muore fa il pop dalla deque.
void Playground::damagePropagate(u32 col) {
  for (u32 row = 0; row < ROWS; row++) {
    if (damage[row] == 0)
      return;
    iterRobot(row, col, [&damage = damage[row]](deque<RobotWTool> &d) {
      // finchè ci sono robot e ci sono danni
      while (d.len() > 0 && d[0].takeDamage(damage)) {
        d.pop_front(); // se il robot muore lo elimino
      }
    });
  }
}

// controlla se in questa cella c'è un robot
// se c'è un robot lo sposta
void Playground::moveRobots() {
  for (u32 row = 0; row < ROWS; row++) {
    for (u32 col = 0; col < COLUMNS; col++) {
      iterRobot(row, col, [row, col, this](deque<RobotWTool> &d) {
        if (d.len() > 0) {
          this->damage[row] =
              col - std::min(this->nearestPlayer(row, col),
                             d[0].move() % (FRAME_COLUMNS * COLUMNS));
          this->enemy[row][this->damage[row]].push_back(d.pop_front().get());
        }
      });
    }
    damage[row] = 0;
  }
}

// controlla da qui alla colonna 0 dov'è il primo MusicInstrument
u32 Playground::nearestPlayer(u32 row, u32 col) const {
  for (u32 i = col; i > 0; i--) {
    if (player[row][i].isPtr()) {
      return i;
    }
  }
  return INT_MAX;
}
