#ifndef ENTITY_H
#define ENTITY_H
#include "../util/dataManager.h"
#include "../view/visitors/entityVisitorInterface.h"
#include "cash.h"

/// Classe astratta che rappresenta le entità del gioco
class Entity : public DataManagerInterface {
  private:
    u32 health;
    u32 power;

  public:
    Entity(u32 health, u32 power);
    virtual ~Entity() = default;
    virtual Entity *clone() const = 0;

    virtual bool takeDamage(u32 &amount) = 0;
    virtual u32 attack() const = 0;

    u32 &getHealth();
    u32 &getPower();

    /// Funzione che permette di visitare l'entità
    virtual void accept(EntityVisitorInterface &visitor) const = 0;

    /// Funzione che permette di salvare i dati dell'entità
    virtual std::string saveData() const override;
    virtual Entity *loadData(std::string) override = 0;
};
#endif
