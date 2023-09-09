#pragma once
#include "playground_damage.h"
#include "playground_enemy.h"
#include "playground_player.h"
#include "timer.h"

class Game : public PlaygroundDamage, public PlaygroundEnemy, public PlaygroundPlayer, public ObservableGameInterface {
  private:
    static Game *instance;

  public:
    static Game *getInstance();
    void cleanUp();
    bool insert(u32 r, u32 c, const PlayerAbstract &p);
    bool remove(u32 r, u32 c);
    // bool levelUp(u32 r, u32 c); // don't need to overload, it's already defined
    // and it's not ambiguos
    bool isEmpty(u32 r, u32 c) const;
    const PlayerAbstract &get(u32 r, u32 c) const;
    void damagePropagate();
    void battle();

    std::string toString() const override;
    DataManagerInterface *fromString(std::string) override;
};
