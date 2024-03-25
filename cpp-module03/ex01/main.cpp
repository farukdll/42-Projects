#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap scavTrap("ScavTrap");
	scavTrap.attack("Target");
	scavTrap.takeDamage(60);
	scavTrap.beRepaired(30);
	scavTrap.takeDamage(30);
	scavTrap.guardGate();
	return 0;
}