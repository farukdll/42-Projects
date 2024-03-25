#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->name = "FragTrap";
	this->hitPoints = 100;
	this->maxHealthP = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << name << " is woke up." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->maxHealthP = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "FragTrap " +  name << " is woke up." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destroyed." << std::endl;
}


FragTrap::FragTrap(const FragTrap &clone) : ClapTrap(clone)
{
	*this = clone;
	std::cout << clone.name << "is cloned." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap) 
{
	this->name = fragTrap.name;
	this->hitPoints = fragTrap.hitPoints;
	this->energyPoints = fragTrap.energyPoints;
	this->attackDamage = fragTrap.attackDamage;
	this->maxHealthP = fragTrap.maxHealthP;
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "FragTrap " << this->name << ": High Five!" <<std::endl;
	}
}