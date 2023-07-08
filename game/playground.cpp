#include "playground.h"

Playground *Playground::instance = nullptr;

std::vector<PlaygroundObserverInterface *> Playground::observers;

Playground::Playground() : damagePos(0) { reset(); }

void Playground::cleanUp() {
  if (instance != nullptr) {
    delete instance;
    instance = nullptr;

    for (auto &obs : observers) {
      obs->clearPlayground();
    }
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
    if (player[row][col] != nullptr) {
      if (dynamic_cast<const Drum *>(&*player[row][col]))
        MusicInstruments::damages[row][1] += player[row][col]->attack();
      player[row][col]->attack(row);
    }

    if (col > 3 && player[row][col - 4] &&
        dynamic_cast<const Drum *>(&*player[row][col - 4]))
      MusicInstruments::damages[row][1] -= player[row][col - 4]->attack();
  }
}

// se c'è una pianta in questa cella e c'è almeno uno zombie, gli zombie
// attaccano la pianta, controlla tutte le righe
// NB se i danni non sono nulli allora tutti gli zombie sono morti
void Playground::enemyAttack(u32 col) {
  for (u32 row = 0; row < ROWS; row++) {
    if (isEmpty(row, col))
      return;

    u32 danni = 0;
    col = col * FRAME_COLUMNS + 1;
    for (; col < col + FRAME_COLUMNS; col++)
      enemy[row][col].iter([&danni](auto &e) { danni += e.attack(); });

    if (player[row][col]->takeDamage(danni)) {
      player[row][col] = nullptr;     // it is killed
      notifyMusicObservers(row, col); // notify the observers
    }

    // notifyMusicObservers deletes the images of the robots
    col -= FRAME_COLUMNS;
    for (; col < col + FRAME_COLUMNS - 1; col++)
      enemy[row][col].iter([row, col](auto &e) {
        Playground::notifyRobotObservers(row, col, e.getRobot());
      });
  }
}

// per ogni riga controlla se in questa colonna c'è un robot
// finchè damage[riga] > 0 e ci sono dei robot infligge del danno
// ai robot. Se il robot muore fa il pop dalla deque.
void Playground::damagePropagate(u32 col) {
  for (u32 row = 0; row < ROWS; row++) {
    iterRobot(row, col, [&damage = MusicInstruments::damages[row]](auto &d) {
      if (damage[1] > 0)
        // cannot use iter because we need to remove elements
        for (u32 i = 0; i < d.len(); i++) {
          u32 tmp = damage[1];
          if (d[i].takeDamage(tmp))
            d.remove(i--);
        }
      while (damage[0] && d.len() > 0 && d[0].takeDamage(damage[0]))
        d.pop_front(); // se il robot muore lo elimino
    });
    notifyRobotObservers(row, col);
    if (!isEmpty(row, col))
      notifyMusicObservers(row, col, &*player[row][col]);
    iterRobot(row, col, [row, col](auto &d) {
      d.iter([row, col](auto &e) {
        notifyRobotObservers(row, col, e.getRobot());
      });
    });
  }
}

// controlla se in questa cella c'è un robot
// se c'è un robot lo sposta
bool Playground::enemyMove() {
  u32 move_to = 0;
  for (u32 row = 0; row < ROWS; row++) {
    for (u32 col = 1; col < COLUMNS * FRAME_COLUMNS + 1; col++) {
      u32 np = nearestPlayer(row, col);

      // check if the robots can actually move
      if (np / FRAME_COLUMNS >= col / FRAME_COLUMNS) {
        col += FRAME_COLUMNS - 1;
        continue;
      }

      u32 i = 0;
      while (enemy[row][col].len() > i) {
		  std::cout << "begin move" << std::endl;

        // this ain't good, we should not check if the robot is alive here
        if (!enemy[row][col][i].isAlive()) {
          enemy[row][col].remove(i);
          notifyRobotObservers(row, col / FRAME_COLUMNS);
          continue;
        }

		std::cout << "move 1" << std::endl;

        move_to = enemy[row][col][i].move() / COLUMNS;
        if (MusicInstruments::damages[row][2] > 0) {
          move_to /= 2;
          MusicInstruments::damages[row][2]--;
        }

		std::cout << "move 2" << std::endl;

        move_to = std::max(col - move_to, np);

        if (move_to == col) {
          i++;
          continue;
        }

        notifyRobotObservers(row, col / FRAME_COLUMNS);

		std::cout << "move 3" << std::endl;

        // controllo che il robot non si muova nella colonna dove si trovano
        // i danni, altrimenti li schiverebbe
        if (col / FRAME_COLUMNS > damagePos &&
            move_to / FRAME_COLUMNS <= damagePos &&
            (enemy[row][col][i].takeDamage(MusicInstruments::damages[row][1]) ||
             enemy[row][col][i].takeDamage(
                 MusicInstruments::damages[row][0]))) {
          enemy[row][col].remove(i--);
          continue;
        }

		std::cout << "move 4" << std::endl;

        if (move_to == 0) {
          for (auto &obs : observers)
            obs->notifyEndGame();
          return true;
        }


		std::cout << "remove" << std::endl;
        auto robot = enemy[row][col].remove(i--);
		std::cout << "push_back" << std::endl;
        enemy[row][move_to].push_back(robot);
		std::cout << "end_pushback" << std::endl;

        notifyRobotObservers(row, move_to / FRAME_COLUMNS, robot.getRobot());
      }
    }
  }
  return false;
}

// controlla da qui alla colonna 0 dov'è il primo MusicInstrument
// potrei cambiare questa funzione per non far sovrapporre i robot
u32 Playground::nearestPlayer(u32 row, u32 col) const {
  col--;
  for (u32 i = 0; i <= col / FRAME_COLUMNS; i++)
    if (player[row][col / FRAME_COLUMNS - i])
      return (i + 1) * FRAME_COLUMNS;

  return 0;
}

void Playground::enemyInsert(u32 row, u32 difficulty) {
  auto robot = RobotWTool(difficulty, difficulty / 2);
  enemy[row][COLUMNS * FRAME_COLUMNS].push_back(robot);
  notifyRobotObservers(row, COLUMNS - 1, robot.getRobot());
}

bool Playground::isEmpty(u32 row, u32 col) const { return !player[row][col]; }

const MusicInstruments *Playground::playerGet(u32 row, u32 col) const {
  return &*player[row][col];
}

void Playground::playerRemove(u32 row, u32 col) {
  if (isEmpty(row, col))
    return;
  player[row][col] = nullptr;
  notifyMusicObservers(row, col);
}

bool Playground::playerInsert(u32 row, u32 col, MusicInstruments *mi) {
  if (player[row][col] ||
      !Cash::sub(mi->getCost())) { // se non c'è spazio o non
    return false;
  }
  player[row][col] = std::unique_ptr<MusicInstruments>(mi->clone());
  notifyMusicObservers(row, col, mi);
  return true;
}

bool Playground::playerLevelUp(u32 row, u32 col) {
  if (!player[row][col] || !Cash::sub((*player[row][col]).value()))
    return false;
  player[row][col]->levelUp();
  notifyMusicObservers(row, col, &*player[row][col]);
  return true;
}

void Playground::notifyMusicObservers(int row, int col, MusicInstruments *mi) {
  for (auto &obs : observers) {
    obs->updatePlaygroundMusic(row, col, mi);
  }
}

void Playground::notifyRobotObservers(int row, int col, Robot *r) {
  for (auto &obs : observers) {
    obs->updatePlaygroundRobot(row, col, r);
  }
}

void Playground::registerObserver(PlaygroundObserverInterface *obs) {
  observers.push_back(obs);
}

// opens the file "p
Playground::~Playground() {}

void Playground::battle() {
  getInstance()->reset(); // reset damage
  for (u32 i = 0; i < COLUMNS; i++) {
    std::cout << "1" << std::endl;
    instance->playerAttack(i);
    std::cout << "2" << std::endl;
    instance->damagePropagate(i);
    std::cout << "3" << std::endl;
    //    instance->enemyAttack(i);
    if (instance->enemyMove())
      return;
    std::cout << "4" << std::endl;
    instance->enemyInsert(randomInt(3, 1), 40);
    std::cout << "5" << std::endl;
    for (u32 j = 0; j < FRAME_COLUMNS; j++)
      instance->damagePos++;
  }
  Timer::oneSecond();
  std::cout << "time: " << Timer::get() << std::endl;
}
