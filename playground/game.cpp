#include "game.h"

Game *Game::instance = nullptr;

Game *Game::getInstance() {
    if (instance == nullptr) {
        instance = new Game();
    }
    return instance;
}

void Game::cleanUp() {
    if (instance) {
        // TODO FIXUP: when notify is after delete, it crashes
        notifyClearGame();
        delete instance;
        instance = nullptr;
    }
}

bool Game::insert(u32 r, u32 c, const PlayerAbstract &p) { return PlaygroundPlayer::insert(r, c, p); }

bool Game::remove(u32 r, u32 c) { return PlaygroundPlayer::remove(r, c); }

bool Game::isEmpty(u32 r, u32 c) const { return PlaygroundPlayer::isEmpty(r, c); }

const PlayerAbstract &Game::get(u32 r, u32 c) const { return PlaygroundPlayer::get(r, c); }

void Game::damagePropagate() {
    PlaygroundDamage::move(*this);
    PlaygroundDamage::attack(*this);
}

void Game::battle() {
    if (PlaygroundEnemy::move(*this, *this)) {
        return notifyGameOver();
    }

    PlaygroundEnemy::attack(*this);
    PlaygroundEnemy::insert();
    Timer::oneSecond();
    PlaygroundPlayer::attack(*this);
}

std::string Game::toString() const {
    std::string jsonString = "\"Game\": {\n";
    jsonString += PlaygroundPlayer::toString();
    // jsonString += ",\n" + PlaygroundEnemy::toString();
    // jsonString += ",\n" + PlaygroundDamage::toString()
    jsonString += "\n";
    jsonString += "}";
    return jsonString;
}

DataManagerInterface *Game::fromString(std::string jsonString) { return PlaygroundPlayer::fromString(jsonString); }