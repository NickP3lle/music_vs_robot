#include "playground.h"

Playground *Playground::instance = nullptr;

Playground::Playground() : damagePos(0) { reset(); }

void Playground::cleanUp() {
  if (instance != nullptr) {
    delete instance;
    instance = nullptr;
  }
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
  for (u32 i = 0; i < ROWS; i++)
    if (enemy[i][0].len() > 0)
      return true;
  return false;
}

// calcola il danno sulla colonna che gli passi per l'intera riga
void Playground::playerAttack(u32 col) {
  for (u32 i = 0; i < ROWS; i++) {
    if (!player[i][col])
      continue;
    if (dynamic_cast<const Drum *>(&*player[i][col]))
      damage[i][1] += (*player[i][col]).attack();
    else
      damage[i][0] += (*player[i][col]).attack();
    if (dynamic_cast<const Trumpet *>(&*player[i][col])) {
      if (i > 0)
        damage[i - 1][0] += (*player[i][col]).attack();
      if (i < ROWS - 1)
        damage[i + 1][0] += (*player[i][col]).attack();
    }
    if (dynamic_cast<const Violin *>(&*player[i][col]))
      slowDown[i]++;
    if (col > 3 && dynamic_cast<const Drum *>(&*player[i][col - 4]))
      std::cout << "Harddo", damage[i][1] += (*player[i][col - 4]).attack();
  }
}

// se c'è una pianta in questa cella e c'è almeno uno zombie, gli zombie
// attaccano la pianta, controlla tutte le righe
// NB se i danni non sono nulli allora tutti gli zombie sono morti
void Playground::enemyAttack(u32 col) {
  for (u32 row = 0; row < ROWS; row++) {
    if (!player[row][col] || damage[row][0] > 0)
      return;
    u32 danni = 0;
    iterRobot(row, col, [&danni](deque<RobotWTool> &d) {
      d.iter([&danni](RobotWTool &e) { danni += e.attack(); });
    });
    player[row][col].get_mut().takeDamage(danni);
  }
}

// per ogni riga controlla se in questa colonna c'è un robot
// finchè damage[riga] > 0 e ci sono dei robot infligge del danno
// ai robot. Se il robot muore fa il pop dalla deque.
void Playground::damagePropagate(u32 col) {
  for (u32 row = 0; row < ROWS; row++) {
    iterRobot(row, col, [&damage = damage[row]](deque<RobotWTool> &d) {
      if (damage[1] > 0)
        for (u32 i = 0; i < d.len(); i++) {
          u32 tmp = damage[1];
          if (d[i].takeDamage(tmp))
            d.remove(i--);
        }
      while (d.len() > 0 && d[0].takeDamage(damage[0])) {
        d.pop_front(); // se il robot muore lo elimino
      }
    });
  }
}

// controlla se in questa cella c'è un robot
// se c'è un robot lo sposta
// c'è un buggino: un robot potrebbe schivare i danni
void Playground::moveRobots() {
  for (u32 row = 0; row < ROWS; row++) {
    for (u32 col = 0; col < COLUMNS * FRAME_COLUMNS; col++) {
      if (nearestPlayer(row, col) == 0)
        continue;
      while (enemy[row][col].len() > 0)
        enemy[row][moveRobot(row, col, enemy[row][col][0])].push_back(
            enemy[row][col].pop_front());
    }
  }
}

// controlla da qui alla colonna 0 dov'è il primo MusicInstrument
// potrei cambiare questa funzione per non far sovrapporre i robot
u32 Playground::nearestPlayer(u32 row, u32 col) const {
  for (int i = 0; i <= col / FRAME_COLUMNS; i++)
    if (player[row][col / FRAME_COLUMNS - i]) {
      return i * FRAME_COLUMNS;
    }
  return col;
}

u32 Playground::moveRobot(u32 row, u32 col, RobotWTool &r) {
  return col - std::min(nearestPlayer(row, col),
                        r.move() / COLUMNS / (slowDown[row]-- ? 2 : 1));
}

void Playground::insertEnemy(u32 row, u32 difficulty) {
  enemy[row][FRAME_COLUMNS * COLUMNS - 1].push_back(RobotWTool(difficulty));
}

bool Playground::insertPlayer(u32 row, u32 col, u32 mi_id) {
  if (player[row][col])
    return false;
  player[row][col] = ptr<MusicInstruments>(music::New(mi_id));
  return true;
}

std::ostream &Playground::print(std::ostream &os) const {
  os << "_________________________________" << std::endl;
  for (u32 row = 0; row < ROWS; row++) {
    for (u32 col = 0; col < COLUMNS; col++) {
      if (dynamic_cast<const Flute *>(&*player[row][col]))
        os << "F";
      else if (dynamic_cast<const Trumpet *>(&*player[row][col]))
        os << "T";
      else if (dynamic_cast<const Drum *>(&*player[row][col]))
        os << "D";
      else if (dynamic_cast<const Violin *>(&*player[row][col]))
        os << "V";
      else if (dynamic_cast<const Saxophone *>(&*player[row][col]))
        os << "S";
      else
        os << " ";
    }
    os << "\n";
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
