#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
    if (N <= 1) {
        std::cout << "Enter a valid number (> 0)" << std::endl;
        return (NULL);
    }
    Zombie *horde = new Zombie[N];
    if (horde == NULL)
        return (NULL);
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }
    return (horde);
}