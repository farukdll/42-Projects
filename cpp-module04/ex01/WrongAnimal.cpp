#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() 
{
    this->type = "WrongAnimal";
    std::cout << this->type << " constructor called"<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& WrongAnimal) {
	*this = WrongAnimal;
	std::cout << this->type << " copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& WrongAnimal) {
	this->type = WrongAnimal.type;
	std::cout << this->type << " assignment operator called" << std::endl;
	return *this;
}

const std::string& WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::makeSound() const {

}

WrongAnimal::~WrongAnimal() {
	std::cout << this->type << " destructor called" << std::endl;
}