#include "Animal.hpp"

Animal::Animal() 
{
    this->type = "Animal";
    std::cout << "Animal constructor called"<<std::endl;
}

Animal::Animal(const Animal& animal) 
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = animal;
}

Animal& Animal::operator=(const Animal& animal) 
{
	std::cout << "Animal assignment operator called" << std::endl;
	this->type = animal.type;
	return *this;
}

const std::string& Animal::getType() const 
{
	return this->type;
}

void Animal::makeSound() const 
{

}

Animal::~Animal() 
{
	std::cout << "Animal destructor called" << std::endl;
}
