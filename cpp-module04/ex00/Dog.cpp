#include "Dog.hpp"

Dog::Dog() 
{
    this->type = "Dog";
    std::cout << this->type << " constructor called"<<std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
	std::cout << this->type << " copy constructor called" << std::endl;
	*this = dog;
}

Dog& Dog::operator=(const Dog& dog) 
{
	std::cout << this->type << " assignment operator called" << std::endl;
	this->type = dog.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Dog: hav havvvv" << std::endl;
}

Dog::~Dog() {
	std::cout << this->type << " destructor called" << std::endl;
}