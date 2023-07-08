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
    Playground::notifyRobotObservers(row, col);
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
  }
}

// controlla se in questa cella c'è un robot
// se c'è un robot lo sposta
bool Playground::enemyMove() {
  for (u32 row = 0; row < ROWS; row++) {
    for (u32 col = 1; col < COLUMNS * FRAME_COLUMNS + 1; col++) {

      int np = nearestPlayer(row, col);
      std::cout << "np: " << np
                << " isEmpty: " << isEmpty(row, col / FRAME_COLUMNS)
                << std::endl;
      if (np == 0) {
        col += FRAME_COLUMNS;
        continue;
      }

      int move_to = 0;
      u32 i = 0;
      while (enemy[row][col].len() > i) {
        std::cout << "begin move" << std::endl;

        // this ain't good, we should not check if the robot is alive here
        // debug
        std::cout << "len: " << enemy[row][col].len() << " i: " << i
                  << std::endl;
        if (!enemy[row][col][i].isAlive()) {
          std::cout << "move remove" << std::endl;
          enemy[row][col].pop(i);
          std::cout << "remove" << std::endl;
        }

        std::cout << "move 1" << std::endl;

        move_to = enemy[row][col][i].move() / COLUMNS;
        if (MusicInstruments::damages[row][2] > 0) {
          move_to /= 2;
          MusicInstruments::damages[row][2]--;
        }

        move_to = col - std::min(move_to, np);

        std::cout << "col - move_to: " << col - move_to << std::endl;
        if (move_to == (int)col) {
          i++;
          continue;
        }

        if (move_to == 0) {
          for (auto &obs : observers)
            obs->notifyEndGame();
          return true;
        }

        enemy[row][move_to].push_back(enemy[row][col].remove(i));
      }
    }
    for (u32 col = 0; col < COLUMNS; col++)
      notifyRobotObservers(row, col);
  }
  return false;
}

// a partire da col, ritorna di quante queue si può spostare il robot
// notiamo che col > 0, in effetti se col == 0 il giocatore avrebbe già perso
u32 Playground::nearestPlayer(u32 row, u32 col) const {
  col--;

  if (player[row][col / FRAME_COLUMNS])
    return 0;
  for (u32 i = 0; i <= col / FRAME_COLUMNS; i++)
    if (player[row][col / FRAME_COLUMNS - i])
      return (i - 1) * FRAME_COLUMNS + col % FRAME_COLUMNS + 1;

  return col + 1;
}

void Playground::enemyInsert(u32 row, u32 difficulty) {
  auto robot = RobotWTool(difficulty, difficulty / 2);
  enemy[row][COLUMNS * FRAME_COLUMNS].push_back(robot);
}

bool Playground::isEmpty(u32 row, u32 col) const { return !player[row][col]; }

const MusicInstruments *Playground::playerGet(u32 row, u32 col) const {
  return &*player[row][col];
}

deque<const RobotWTool *> Playground::enemyGet(u32 row, u32 col) const {
  deque<const RobotWTool *> ret;
  for (u32 i = col * FRAME_COLUMNS; i < (col + 1) * FRAME_COLUMNS; i++)
    for (u32 j = 0; j < enemy[row][i].len(); j++)
      ret.push_back(&enemy[row][i][j]);
  return ret;
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
  notifyMusicObservers(row, col);
  return true;
}

bool Playground::playerLevelUp(u32 row, u32 col) {
  if (!player[row][col] || !Cash::sub((*player[row][col]).value()))
    return false;
  player[row][col]->levelUp();
  notifyMusicObservers(row, col);
  return true;
}

void Playground::notifyMusicObservers(int row, int col) {
  MusicInstruments *mi = nullptr;
  if (!getInstance()->isEmpty(row, col))
    mi = &*instance->player[row][col];
  for (auto &obs : observers) {
    obs->updatePlaygroundMusic(row, col, mi);
  }
}

void Playground::notifyRobotObservers(int row, int col) {
  for (auto &obs : observers) {
    // delete the previous robots
    obs->updatePlaygroundRobot(row, col);

    // insert the music instruments
    obs->updatePlaygroundMusic(row, col);
  }

  getInstance()->enemyGet(row, col).iter(
      [obs = instance->observers, row, col](const RobotWTool *r) {
        for (auto &ob : obs)
          ob->updatePlaygroundRobot(row, col, r->getRobot());
      });
}

void Playground::registerObserver(PlaygroundObserverInterface *obs) {
  observers.push_back(obs);
}

// opens the file "p
Playground::~Playground() {}

void Playground::battle() {
  getInstance()->reset(); // reset damage
  for (u32 i = 0; i < COLUMNS; i++) {
    instance->playerAttack(i);
    std::cout << "1" << std::endl;
    std::cout << "2" << std::endl;
    instance->damagePropagate(i);
    std::cout << "3" << std::endl;
    std::cout << "4" << std::endl;
    instance->enemyAttack(i);
    std::cout << "5" << std::endl;
    for (u32 j = 0; j < FRAME_COLUMNS; j++)
      instance->damagePos++;
  }
  if (instance->enemyMove())
    return;
  instance->enemyInsert(randomInt(3, 1), 40);
  Timer::oneSecond();
  std::cout << "time: " << Timer::get() << std::endl;
}
