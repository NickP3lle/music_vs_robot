#include "flute.h"
#include "trumpet.h"
#include "violin.h"

int main() {
    Cash *ptr = Cash::getInstance();
    ptr->add(200);
    std::cout << ptr->getTotal() << std::endl;

    Violin v;
    Trumpet t;
    Flute f;

    v.levelUp();
    v.levelUp();
    v.levelUp();
    v.levelUp();

    f.levelUp();
    f.levelUp();
    f.levelUp();
    f.levelUp();

    t.levelUp();
    t.levelUp();
    t.levelUp();

    ptr->add(200);

    t.levelUp();
    t.levelUp();
    t.levelUp();
    t.levelUp();
    t.levelUp();

    return 0;
}