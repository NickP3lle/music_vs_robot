#include "playground.h"

Playground *Playground::instance = nullptr;

Playground::Playground() : damagePos(0) { reset(); }

void Playground::cleanUp() {
  if (instance != nullptr) {
    delete instance;
    instance = nullptr;
  }
}

void Playground::reset() { MusicInstruments::resetDamages(); }

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
  u32 row = 0;
  for (; row < ROWS; row++) {
    if (player[row][col]) {
      // if (dynamic_cast<const Drum *>(&player[row][col].get()))
      if (music(player[row][col].get()) == THREE_C)
        MusicInstruments::damages[row][1] += player[row][col].get().attack();
      player[row][col].get().attack(row);
    }
    if (col > 3 && player[row][col - 4] &&
        music(player[row][col - 4].get()) == THREE_C)
      MusicInstruments::damages[row][1] -= player[row][col - 4].get().attack();
  }
}

// se c'è una pianta in questa cella e c'è almeno uno zombie, gli zombie
// attaccano la pianta, controlla tutte le righe
// NB se i danni non sono nulli allora tutti gli zombie sono morti
void Playground::enemyAttack(u32 col) {
  for (u32 row = 0; row < ROWS; row++) {
    if (!player[row][col] || MusicInstruments::damages[row][0] > 0)
      continue;
    u32 danni = 0;
    iterRobot(row, col, [&danni](auto &d) {
      d.iter([&danni](auto &e) { danni += e.attack(); });
    });
    player[row][col].get_mut().takeDamage(danni);
  }
}

// per ogni riga controlla se in questa colonna c'è un robot
// finchè damage[riga] > 0 e ci sono dei robot infligge del danno
// ai robot. Se il robot muore fa il pop dalla deque.
void Playground::damagePropagate(u32 col) {
  for (u32 row = 0; row < ROWS; row++) {
    iterRobot(row, col, [&damage = MusicInstruments::damages[row]](auto &d) {
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
  u32 move_to = 0;
  for (u32 row = 0; row < ROWS; row++) {
    for (u32 col = 0; col < COLUMNS * FRAME_COLUMNS; col++) {
      if (nearestPlayer(row, col) == 0)
        continue;
      while (enemy[row][col].len() > 0) {
        move_to = moveRobot(row, col, enemy[row][col][0]);
        // controllo che il robot non si muova nella colonna dove si trovano
        // i danni, altrimenti li schiverebbe
        if (col / FRAME_COLUMNS > damagePos &&
            move_to / FRAME_COLUMNS <= damagePos &&
            (enemy[row][col][0].takeDamage(MusicInstruments::damages[row][1]) ||
             enemy[row][col][0].takeDamage(
                 MusicInstruments::damages[row][0]))) {
          enemy[row][col].pop_front();
          continue;
        }
        enemy[row][moveRobot(row, col, enemy[row][col][0])].push_back(
            enemy[row][col].pop_front());
      }
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
                        r.move() / COLUMNS /
                            (MusicInstruments::damages[row][2]-- ? 2 : 1));
}

void Playground::insertEnemy(u32 row, u32 difficulty) {
  enemy[row][FRAME_COLUMNS * COLUMNS - 1].push_back(
      RobotWTool(difficulty, difficulty / 2));
}

bool Playground::insertPlayer(u32 row, u32 col, music mi_id) {
  MusicInstruments *mi = music::New(mi_id);
  if (player[row][col] ||
      !Cash::getInstance()->sub(mi->getCost())) { // se non c'è spazio o non
    delete mi;
    return false;
  }
  player[row][col] = ptr<MusicInstruments>(mi);
  return true;
}

bool Playground::playerLevelUp(u32 row, u32 col) {
  if (!player[row][col] &&
      !Cash::getInstance()->sub((*player[row][col]).value()))
    return false;
  player[row][col].get_mut().levelUp();
  return true;
}

std::ostream &Playground::print(std::ostream &os) const {
  for (u32 row = 0; row < ROWS; row++) {
    for (u32 col = 0; col < COLUMNS; col++) {
      if (!player[row][col])
        os << " ";
      else
        player[row][col].get().print(os);
    }
  }
  return os;
}
