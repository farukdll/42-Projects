#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    this->name = name;
    this->weapon = NULL;
}

HumanB::~HumanB() {}

void HumanB::attack(void) {
    if ( this->weapon )
    {
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    }
    else
    {
        std::cout << this->name << " attacks with his fists" << std::endl;
    }
}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}
