#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->name = "ScavTrap";
	this->hitPoints = 100;
	this->maxHealthP = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " is woken up." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->maxHealthP = 100;
	std::cout << "ScavTrap " +  name << " is woken up." << std::endl;
} 

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " destroyed." << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap &clone) : ClapTrap(clone)
{
	*this = clone;
	std::cout << clone.name << "is cloned." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap) 
{
	this->name = scavTrap.name;
	this->hitPoints = scavTrap.hitPoints;
	this->energyPoints = scavTrap.energyPoints;
	this->attackDamage = scavTrap.attackDamage;
	this->maxHealthP = scavTrap.maxHealthP;
	return *this;
}

void ScavTrap::guardGate()
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "ScavTrap " << name << " is guard mode." << std::endl;
	}
}

void ScavTrap::attack(const std::string &damage)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "ScavTrap " + this->name + " attacks " +  damage + ", causing " << this->attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
	else
		std::cout << "ScavTrap " + this->name + "does not have the necessary energy or enough health." << std::endl;
}
