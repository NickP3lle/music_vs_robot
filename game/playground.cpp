#include "playground.h"

Playground *Playground::instance = nullptr;

std::vector<PlaygroundObserverInterface *> Playground::observers;

Playground::Playground() : damagePos(0) { reset(); }

void Playground::cleanUp() {
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
    notifyObservers();
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
        if (col > 3 && player[row][col - 4] && music(player[row][col - 4].get()) == THREE_C)
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
        std::for_each(&enemy[row][col * FRAME_COLUMNS], &enemy[row][(col + 1) * FRAME_COLUMNS + 1],
                      [&danni](deque<RobotWTool> &d) { d.iter([&danni](RobotWTool &e) { danni += e.attack(); }); });
        if (player[row][col].get_mut().takeDamage(danni))
            player[row][col] = nullptr;
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
            while (d.len() > 0 && d[0].takeDamage(damage[0]))
                d.pop_front(); // se il robot muore lo elimino
        });
    }
}

// controlla se in questa cella c'è un robot
// se c'è un robot lo sposta
// c'è un buggino: un robot potrebbe schivare i danni
void Playground::enemyMove() {
    u32 move_to = 0;
    for (u32 row = 0; row < ROWS; row++) {
        for (u32 col = 0; col < COLUMNS * FRAME_COLUMNS + 1; col++) {
            if (nearestPlayer(row, col) == 0)
                continue;
            while (enemy[row][col].len() > 0) {
                move_to = moveRobot(row, col, enemy[row][col][0]);
                notifyObservers(row, col);
                // controllo che il robot non si muova nella colonna dove si trovano
                // i danni, altrimenti li schiverebbe
                if (col / FRAME_COLUMNS > damagePos && move_to / FRAME_COLUMNS <= damagePos &&
                    (enemy[row][col][0].takeDamage(MusicInstruments::damages[row][1]) ||
                     enemy[row][col][0].takeDamage(MusicInstruments::damages[row][0]))) {
                    enemy[row][col].pop_front();
                    continue;
                }
                // enemy[row][moveRobot(row, col, enemy[row][col][0])].push_back(enemy[row][col].pop_front());
                auto robot = enemy[row][col].pop_front();
                enemy[row][move_to].push_back(robot);

                notifyObservers(row, move_to, robot.getRobot());
            }
        }
    }
}

// controlla da qui alla colonna 0 dov'è il primo MusicInstrument
// potrei cambiare questa funzione per non far sovrapporre i robot
u32 Playground::nearestPlayer(u32 row, u32 col) const {
    for (u32 i = 0; i <= col / FRAME_COLUMNS; i++)
        if (player[row][col / FRAME_COLUMNS - i]) {
            return i * FRAME_COLUMNS;
        }
    return col;
}

u32 Playground::moveRobot(u32 row, u32 col, RobotWTool &r) {
    /// @bug damages può diventare negativo
    return col - std::min(nearestPlayer(row, col), r.move() / COLUMNS / (MusicInstruments::damages[row][2]-- ? 2 : 1));
}

void Playground::enemyInsert(u32 row, u32 difficulty) {
    enemy[row][FRAME_COLUMNS * COLUMNS].push_back(RobotWTool(difficulty, difficulty / 2));
}

bool Playground::playerInsert(u32 row, u32 col, MusicInstruments *mi) {
    if (player[row][col] || !Cash::getInstance()->sub(mi->getCost())) { // se non c'è spazio o non
        return false;
    }
    player[row][col] = ptr<MusicInstruments>(mi->clone());
    notifyObservers(row, col, mi);
    return true;
}

bool Playground::playerLevelUp(u32 row, u32 col) {
    if (!player[row][col] && !Cash::getInstance()->sub((*player[row][col]).value()))
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

// void Playground::notifyObservers(Entity *entity) {
//     for (auto &obs : observers) {
//         obs->updatePlayground(entity);
//     }
// }

void Playground::notifyObservers(int row, int col, Entity *entity) {
    for (auto &obs : observers) {
        if (row == -1) {
            obs->updatePlayground(entity);
        } else {
            MusicInstruments *mi = dynamic_cast<MusicInstruments *>(entity);
            if (mi) {
                obs->updatePlaygroundMusic(row, col, mi);
            } else {
                obs->updatePlaygroundRobot(row, col, dynamic_cast<Robot *>(entity));
            }
        }
    }
}

void Playground::registerObserver(PlaygroundObserverInterface *obs) { observers.push_back(obs); }

/**
 * CleanUp e playerInsert notificano gli observer
 */