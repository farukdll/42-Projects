#include "Cat.hpp"

Cat::Cat() 
{
    this->type = "Cat";
    std::cout << this->type << " constructor called"<<std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	*this = cat;
	std::cout << this->type << " copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& cat) {
	this->type = cat.type;
	std::cout << this->type << " assignment operator called" << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Cat: miyavv" << std::endl;
}

Cat::~Cat() {
	std::cout << this->type << " destructor called" << std::endl;
}
