#include "Dog.hpp"

Dog::Dog() 
{
    std::cout << "Dog constructor called"<<std::endl;
    this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = dog;
}

Dog& Dog::operator=(const Dog& dog) 
{
	std::cout << "Dog assignment operator called" << std::endl;
	this->type = dog.type;
	this->brain = new Brain();
	*(this->brain) = *(dog.brain);
	return *this;
}

void Dog::makeSound() const 
{
	std::cout << "Dog: hav havvvv" << std::endl;
}

Dog::~Dog() 
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}
