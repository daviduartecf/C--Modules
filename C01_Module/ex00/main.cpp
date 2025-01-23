#include "Zombie.hpp"

int main(void) {
    Zombie zombie("DAVID");
    zombie.announce();
    Zombie *zombie2 = newZombie("MANUEL");
    zombie2->announce();
    randomChump("MIGUEL");
    delete zombie2;
}
