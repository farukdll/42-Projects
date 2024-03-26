#include "Cat.hpp"

Cat::Cat() 
{
    this->type = "Cat";
	this->brain = new Brain();
    std::cout << this->type << " constructor called"<<std::endl;
}

Cat::Cat(const Cat& cat) : AAnimal(cat)
{
	*this = cat;
	std::cout << this->type << " copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& cat) {
	this->type = cat.type;
	this->brain = new Brain();
	*(this->brain) = *(cat.brain);
	std::cout << this->type << " assignment operator called" << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Cat: miaww" << std::endl;
}

Cat::~Cat() {
	delete brain;
	std::cout << this->type << " destructor called" << std::endl;
}
