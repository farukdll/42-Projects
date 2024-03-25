#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	
	ScavTrap s;
	s.attack("enemy1");
	s.takeDamage(70);
	s.beRepaired(30);
	s.guardGate();
	FragTrap f;
	f.attack("enemy2");
	f.takeDamage(15);
	f.beRepaired(10);
	f.highFivesGuys();
	return (0);
}
