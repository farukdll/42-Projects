#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
    this->name = name;
}

Zombie::~Zombie() {
    std::cout << this->name << " is dead." << std::endl;
}

void Zombie::announce() {
    std::cout << this->name <<": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
