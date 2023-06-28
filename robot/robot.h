#ifndef ROBOT_H
#define ROBOT_H
#include "../game/define.h"
#include "../game/entity.h"
#include "../util/util.h"

class Robot : public Entity {
  private:
    u32 speed;
    u32 value;
    void getHealth();
    void getPower();
    void getValue();

  public:
    Robot(u32 = 0, u32 = 0, bool = false, bool = false);
    bool takeDamage(u32 &) override;
    u32 attack() const override final;
    virtual Robot *clone() const override;
    virtual u32 move() const;
};

class DefenseRobot : public Robot {
  public:
    bool takeDamage(u32 &) override;
    DefenseRobot *clone() const override;
    DefenseRobot(u32, u32 = 0);
};

class BigRobot : public Robot {
  public:
    u32 move() const override;
    BigRobot *clone() const override;
    BigRobot(u32, u32 = 0);
};

#endif
