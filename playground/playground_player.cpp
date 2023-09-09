#include "playground_player.h"

bool PlaygroundPlayer::insert(u32 r, u32 c, const PlayerAbstract &p) {
    if (!isEmpty(r, c) || !Cash::getInstance()->sub(p.getCost())) {
        return false;
    }
    this->player[r][c] = &p;
    notifyObservers(r, c);
    return true;
}

bool PlaygroundPlayer::remove(u32 r, u32 c) {
    if (isEmpty(r, c)) {
        return false;
    }
    this->player[r][c] = nullptr;
    notifyObservers(r, c);
    return true;
}

bool PlaygroundPlayer::isEmpty(u32 r, u32 c) const { return !this->player[r][c]; }

bool PlaygroundPlayer::levelUp(u32 r, u32 c) {
    if (isEmpty(r, c) || !Cash::getInstance()->sub(get(r, c).getCost())) {
        return false;
    }
    get(r, c).levelUp();
    // notify the level
    notifyObservers(r, c);
    return true;
}

PlayerAbstract &PlaygroundPlayer::get(u32 r, u32 c) {
    if (isEmpty(r, c)) {
        throw std::out_of_range("PlaygroundPlayer::get");
    }
    return *this->player[r][c];
}

const PlayerAbstract &PlaygroundPlayer::get(u32 r, u32 c) const {
    if (isEmpty(r, c)) {
        throw std::out_of_range("PlaygroundPlayer::get const");
    }
    return *this->player[r][c];
}

void PlaygroundPlayer::attack(PlaygroundDamage &pd) const {
    pd.clear();
    for (u32 r = 0; r < ROWS; r++) {
        for (u32 c = 0; c < COLS - 1; c++) {
            DamagePlayer *d;
            if (!isEmpty(r, c)) {
                d = get(r, c).attack();
                pd.insert(r, c, *d);
                delete d;
            }

            // ThreeRow attack the row above and below
            if (r > 0 && !isEmpty(r - 1, c) && dynamic_cast<const ThreeRow *>(&get(r - 1, c))) {
                d = get(r - 1, c).attack();
                pd.insert(r, c, *d);
                delete d;
            }
            if (r < ROWS - 1 && !isEmpty(r + 1, c) && dynamic_cast<const ThreeRow *>(&get(r + 1, c))) {
                d = get(r + 1, c).attack();
                pd.insert(r, c, *d);
                delete d;
            }
        }
    }
}

void PlaygroundPlayer::notifyObservers(u32 r, u32 c) const {
    if (isEmpty(r, c)) {
        obs.iter([&](auto o) { o->update(r, c, nullptr); });
    } else {
        obs.iter([&](auto o) { o->update(r, c, &this->get(r, c)); });
    }
}

std::string PlaygroundPlayer::toString() const {
    std::string data;
    data += "\"Playground\": [\n";
    for (u32 i = 0; i < ROWS; i++) {
        for (u32 j = 0; j < COLS - 1; j++) {
            if (!isEmpty(i, j)) {
                // std::cout << "saving" << std::endl;
                data += player[i][j]->toString();
            } else {
                data += "null";
            }
            if (j != COLS - 2 || i != ROWS - 1) {
                data += ",\n";
            }
        }
    }
    data += "\n]";
    return data;
}

DataManagerInterface *PlaygroundPlayer::fromString(std::string data) {
    // NB: è brutto ma fromString non è statica perchè è virtuale e non posso
    // chiamarla senza uno strumento musicale
    std::string tmp;
    // std::cout << data << std::endl;
    Sample *fluteTmp = new Sample();
    for (u32 i = 0; i < ROWS; i++) {
        for (u32 j = 0; j < COLS - 1; j++) {
            size_t nullPos = data.find("null");
            size_t bracePos = data.find("{");
            if (nullPos < bracePos) {
                data.erase(nullPos, 5);
            } else {
                tmp = data.substr(bracePos, data.find("}") - bracePos + 1);
                data.erase(bracePos, data.find("}") - bracePos + 1);
                PlayerAbstract *ptr = fluteTmp->PlayerAbstract::fromString(tmp);
                if (ptr) {
                    load(i, j, ptr);
                }
            }
        }
    }
    return this;
}

void PlaygroundPlayer::load(u32 row, u32 col, PlayerAbstract *player) {
    this->player[row][col] = player;
    notifyObservers(row, col);
}