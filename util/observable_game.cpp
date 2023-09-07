#include "observable_game.h"

deque<ObserverGameInterface *> ObservableGameInterface::obs = deque<ObserverGameInterface *>();

void ObservableGameInterface::addObserver(ObserverGameInterface *observer) { obs.push_back(observer); }

void ObservableGameInterface::removeObserver(ObserverGameInterface *observer) { obs.remove(observer); }

void ObservableGameInterface::notifyClearGame() const {
    obs.iter([](auto ob) { ob->clearGame(); });
}

void ObservableGameInterface::notifyGameOver() const {
    obs.iter([](auto ob) { ob->gameOver(); });
}
