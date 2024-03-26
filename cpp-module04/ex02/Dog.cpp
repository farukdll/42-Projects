#include "Dog.hpp"

Dog::Dog() 
{
    std::cout << this->type << " constructor called"<<std::endl;
    this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& dog) : AAnimal(dog)
{
	std::cout << this->type << " copy constructor called" << std::endl;
	*this = dog;
}

Dog& Dog::operator=(const Dog& dog) 
{
	std::cout << this->type << " assignment operator called" << std::endl;
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
	delete brain;
	std::cout << this->type << " destructor called" << std::endl;
}
