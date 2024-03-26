#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() 
{
    this->type = "WrongAnimal";
    std::cout << "WrongAnimal constructor called"<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& WrongAnimal) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = WrongAnimal;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& WrongAnimal) {
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	this->type = WrongAnimal.type;
	return *this;
}

const std::string& WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::makeSound() const {

}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}