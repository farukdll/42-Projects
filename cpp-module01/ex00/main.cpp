#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void) {
    Zombie* zombie_foo = newZombie("Foo");
    zombie_foo->announce();
    delete zombie_foo;
    randomChump("Boo");
    return(0);
}
