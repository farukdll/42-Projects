#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name);

int main(void) {
    Zombie* zombies;
    zombies = zombieHorde(5, "Foo");
    for(int i = 0; i < 5; i++)
        zombies[i].announce();
    delete[] zombies;
    return(0);
}
