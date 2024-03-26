#include "Cat.hpp"

Cat::Cat() 
{
    std::cout << "Cat constructor called"<<std::endl;
    this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = cat;
}

Cat& Cat::operator=(const Cat& cat) {
	std::cout << "Cat assignment operator called" << std::endl;
	this->type = cat.type;
	this->brain = new Brain();
	*(this->brain) = *(cat.brain);
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Cat: miyavv" << std::endl;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}
