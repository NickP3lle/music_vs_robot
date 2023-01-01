#include "playground.h"

Playground *Playground::instance = nullptr;

Playground::Playground() : damagePos(0) {
  initPlayer();
  reset();
}

void Playground::cleanUp() {
  if (instance != nullptr) {
    delete instance;
    instance = nullptr;
  }
}

void Playground::initPlayer() {
  for (auto &row : instance->player) {
    for (auto &col : row) {
      col = ptr<MusicInstruments>(nullptr);
    }
  }
}

void Playground::initEnemy() {
  for (auto &cols : instance->enemy) {
    for (auto &cell : cols) {
      cell = deque<RobotWTool>(2);
    }
  }
  std::cout << "Enemy initialized" << std::endl;
}

void Playground::reset() {
  for (u32 i = 0; i < ROWS; i++) {
    damage[i][0] = 0;
    damage[i][1] = 0;
    slowDown[i] = 0;
  }
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

// calcola il danno sulla colonna che gli passi per l'intera riga
void Playground::playerAttack(u32 col) {
  for (u32 i = 0; i < ROWS; i++) {
    damage[i][1] = 0; // controllo ogni volta se c'è un drum
    if (player[i][col].isPtr() &&
        !dynamic_cast<const Drum *>(&player[i][col].get()))
      damage[col][0] += player[i][col].get().attack();
    if (player[i][col].isPtr() &&
        dynamic_cast<const Drum *>(&player[i][col].get()))
      damage[col][1] += player[i][col].get().attack();
    if (player[i][col].isPtr() &&
        dynamic_cast<const Violin *>(&player[i][col].get()))
      slowDown[i] += 1;
    if (i > 0 && player[i - 1][col].isPtr() &&
        dynamic_cast<const Trumpet *>(&player[i - 1][col].get()))
      damage[i][0] += player[i - 1][col].get().attack();
    if (i < ROWS && player[i + 1][col].isPtr() &&
        dynamic_cast<const Trumpet *>(&player[i + 1][col].get()))
      damage[i][0] += player[i + 1][col].get().attack();
  }
}

// se c'è una pianta in questa cella e c'è almeno uno zombie, gli zombie
// attaccano la pianta, controlla tutte le righe
//
// NB se i danni non sono nulli allora tutti gli zombie sono morti
void Playground::enemyAttack(u32 col) {
  for (u32 row = 0; row < ROWS; row++) {
    if (player[row][col].isNone() || damage[row][0] > 0)
      return;
    iterRobot(row, col, [&damage = damage[row]](deque<RobotWTool> &d) {
      d.iter().map([&damage](RobotWTool &e) { damage[0] += e.attack(); });
    });
    player[row][col].get_mut().takeDamage(damage[row][0]);
    damage[row][0] = 0;
  }
}

// per ogni riga controlla se in questa colonna c'è un robot
// finchè damage[riga] > 0 e ci sono dei robot infligge del danno
// ai robot. Se il robot muore fa il pop dalla deque.
void Playground::damagePropagate(u32 col) {
  for (u32 row = 0; row < ROWS; row++) {
    if (damage[row][1] == 0)
      iterRobot(row, col, [&damage = damage[row]](deque<RobotWTool> &d) {
        while (damage[1] > 0 && d.len() > 0) {
          tmp = damage[1];
          if (d[0].takeDamage(tmp))
            d.pop_front();
        }
        while (d.len() > 0 && d[0].takeDamage(damage[0])) {
          d.pop_front(); // se il robot muore lo elimino
        }
      });
  }
}

// controlla se in questa cella c'è un robot
// se c'è un robot lo sposta
//
// c'è un buggino: un robot potrebbe schivare i danni
void Playground::moveRobots() {
  for (u32 row = 0; row < ROWS; row++) {
    for (u32 col = 0; col < COLUMNS; col++) {
      iterRobot(row, col, [row, col, this](deque<RobotWTool> &d) {
        if (d.len() > 0) {
          tmp =
              col - std::min(this->nearestPlayer(row, col),
                             d[0].move() % (FRAME_COLUMNS * COLUMNS) /
                                 (slowDown[row] > 0 ? slowDown[row]--, 4 : 1));
          this->enemy[row][tmp].push_back(d.pop_front().get());
        }
      });
    }
    damage[row][0] = 0;
  }
}

// controlla da qui alla colonna 0 dov'è il primo MusicInstrument
//
// potrei cambiare questa funzione per non far sovrapporre i robot
u32 Playground::nearestPlayer(u32 row, u32 col) const {
  for (u32 i = col; i > 0; i--) {
    if (player[row][i].isPtr()) {
      return i;
    }
  }
  return col;
}

void Playground::insertEnemy(u32 row, u32 difficulty) {
  enemy[row][FRAME_COLUMNS * COLUMNS - 1].push_back(RobotWTool(difficulty));
}

bool Playground::insertPlayer(u32 row, u32 col, const MusicInstruments *mi) {
  if (player[row][col].isPtr())
    return false;
  player[row][col] = ptr<MusicInstruments>(mi);
  return true;
}

std::ostream &Playground::print(std::ostream &os) const {
	std::cout << "_________________________________" << std::endl;
  for (u32 row = 0; row < ROWS; row++) {
    for (u32 col = 0; col < COLUMNS; col++) {
      if (player[row][col].isPtr())
        os << "M";
      else {
        os << " ";
      }
    }
	std::cout << "\n";
  }
	std::cout << "_________________________________" << std::endl;
  for (u32 row = 0; row < ROWS; row++) {
    for (u32 col = 0; col < FRAME_COLUMNS * COLUMNS; col++) {
      if (enemy[row][col].len() > 0)
        os << "R";
      else {
        os << " ";
      }
    }
    os << '\n';
  }
	std::cout << "_________________________________" << std::endl;
  return os;
}
