#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout <<"Zombie is created!" << std::endl;
}

Zombie::Zombie(std::string name) {
    this->name = name;
}

Zombie::~Zombie() {
    std::cout << this->name << " is destroyed." << std::endl;
}

void Zombie::announce() {
    std::cout << this->name <<": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}
