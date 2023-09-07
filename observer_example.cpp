#include "playground/game.h"
// #include "playground/playground_player.h"

class Prova : public ObserverPlaygroundInterface<PlayerAbstract>,
              public ObserverPlaygroundInterface<EnemyWTool>,
              public ObserverPlaygroundInterface<DamageAbstract>,
              public ObserverGameInterface,
              public ObserverInterface<Cash>,
              public ObserverInterface<Timer> {
private:
  bool l;

public:
  bool lose() { return l; }

  Prova() : l(false) {}

  void update(u32 r, u32 c, const PlayerAbstract *p) override {
    std::cout << "Player: " << r << " " << c << " "
              << (p ? p->toString() : "emptied") << std::endl;
  }

  void update(u32 r, u32 c, const EnemyWTool *e) override {
    if (e) {
    }
    std::cout << "Enemy: " << r << " " << c << " robot" << std::endl;
  }

  void update(u32 r, u32 c, const DamageAbstract *d) override {
    ptr<DamagePlayer> dmg = static_cast<const DamagePlayer *>(d);
    if (d) {
      std::cout << "Damage: " << r << " " << c << " " << dmg->getSlow() << " "
                << dmg->damage() << std::endl;
    }
  }

  void update(const Cash *c) override {
    std::cout << "Prova: " << c->toString() << std::endl;
  }

  void update(const Timer *t) override {
    std::cout << "Prova: " << t->toString() << std::endl;
  }

  void clearGame() override { std::cout << "Prova: clearGame" << std::endl; }

  void gameOver() override {
    std::cout << "Prova: loseGame" << std::endl;
    l = true;
  }
};

int main() {
  Prova p = Prova();
  Game::getInstance()->PlaygroundPlayer::addObserver(&p);
  Game::getInstance()->PlaygroundEnemy::addObserver(&p);
  Game::getInstance()->PlaygroundDamage::addObserver(&p);
  Game::getInstance()->ObservableGameInterface::addObserver(&p);
  Timer::getInstance()->addObserver(&p);
  Cash::getInstance()->addObserver(&p);

  /// these block works
  /*
  Timer::start();
  Timer::oneSecond();
  Timer::cleanUp();
  */

  Cash::add(2000);
  Game::getInstance()->insert(0, 0, Sample());
  Game::getInstance()->levelUp(0, 0);

  Game::getInstance()->insert(2, 3, ThreeRow());
  Game::getInstance()->levelUp(2, 3);

  Game::getInstance()->insert(4, 4, ThreeColumn());

  // these block works
  /*
  Playground::getInstance()->remove(0, 0);
  std::cout << Playground::getInstance()->isEmpty(0, 0) << std::endl;
  Playground::getInstance()->insert(0, 0, new Sample());
  std::cout << Playground::getInstance()->get(0, 0)->toString() <<
  std::endl;
  */

  while (!p.Prova::lose()) {
    Game::getInstance()->battle();
  }
}
