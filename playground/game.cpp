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

const PlayerAbstract *Game::get(u32 r, u32 c) const { return PlaygroundPlayer::getPtr(r, c); }

void Game::battle() {
    PlaygroundPlayer::attack(*this);

    for (u32 i = 0; i < COLS; ++i) {
        PlaygroundDamage::move(*this);
        PlaygroundDamage::attack(*this);
        // there should be a timer of some kind here
        std::this_thread::sleep_for(std::chrono::milliseconds(80));

    }

    std::cout << "enemy move" << std::endl;
    if (PlaygroundEnemy::move(*this, *this)) {
        return notifyGameOver();
    }

    std::cout << "enemy attack" << std::endl;
    PlaygroundEnemy::attack(*this);
    std::cout << "enemy insert" << std::endl;
    PlaygroundEnemy::insert();
    Timer::oneSecond();
}
