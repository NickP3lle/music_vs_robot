#include "flute.h"
#include "trumpet.h"
#include "violin.h"

int main() {
    Cash *ptr = Cash::getInstance();
    ptr->add(200);
    // std::cout << ptr->getTotal() << std::endl;

    Violin v;
    Trumpet t;
    Flute f;

    // std::cout << v.getMaxHealth() << std::endl;
    v.levelUp();
    // std::cout << v.getMaxHealth() << std::endl;
    v.levelUp();
    // std::cout << v.getMaxHealth() << std::endl;
    v.levelUp();
    // std::cout << v.getMaxHealth() << std::endl;
    v.levelUp();
    // std::cout << v.getMaxHealth() << std::endl;

    // std::cout << f.getMaxHealth() << std::endl;
    f.levelUp();
    // std::cout << f.getMaxHealth() << std::endl;
    f.levelUp();
    // std::cout << f.getMaxHealth() << std::endl;
    f.levelUp();
    // std::cout << f.getMaxHealth() << std::endl;
    f.levelUp();
    // std::cout << f.getMaxHealth() << std::endl;

    // std::cout << t.getMaxHealth() << std::endl;
    t.levelUp();
    // std::cout << t.getMaxHealth() << std::endl;
    t.levelUp();
    // std::cout << t.getMaxHealth() << std::endl;
    t.levelUp();
    // std::cout << t.getMaxHealth() << std::endl;

    ptr->add(200);

    // std::cout << t.getMaxHealth() << std::endl;
    t.levelUp();
    // std::cout << t.getMaxHealth() << std::endl;
    t.levelUp();
    // std::cout << t.getMaxHealth() << std::endl;
    t.levelUp();
    // std::cout << t.getMaxHealth() << std::endl;
    t.levelUp();
    // std::cout << t.getMaxHealth() << std::endl;
    t.levelUp();
    // std::cout << t.getMaxHealth() << std::endl;

    return 0;
}