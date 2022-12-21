#include "flute.h"
#include "trumpet.h"
#include "violin.h"

int main() {
    Cash *ptr = Cash::getInstance();
    ptr->add(400);
    // std::cout << ptr->getTotal() << std::endl;

    Violin v;
    Trumpet t;
    Flute f;

    std::cout << v.levelUp() << std::endl;

    std::cout << v.levelUp() << std::endl;

    std::cout << v.levelUp() << std::endl;

    std::cout << v.levelUp() << std::endl;

    std::cout << f.levelUp() << std::endl;

    std::cout << f.levelUp() << std::endl;

    std::cout << f.levelUp() << std::endl;

    std::cout << f.levelUp() << std::endl;

    std::cout << t.levelUp() << std::endl;

    std::cout << t.levelUp() << std::endl;

    ptr->add(200);

    std::cout << t.levelUp() << std::endl;

    std::cout << t.levelUp() << std::endl;

    return 0;
}