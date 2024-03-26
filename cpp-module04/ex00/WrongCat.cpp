#include "WrongCat.hpp"

WrongCat::WrongCat() 
{
    this->type = "WrongCat";
    std::cout << this->type << " constructor called"<<std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongCat) : WrongAnimal(wrongCat)
{
	*this = wrongCat;
	std::cout << this->type << " copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& WrongCat) {
	this->type = WrongCat.type;
	std::cout << this->type << " assignment operator called" << std::endl;
	return *this;
}

void WrongCat::makeSound() const 
{
	std::cout << "Wrong Cat: miyavv" << std::endl;
}

WrongCat::~WrongCat() 
{
	std::cout << this->type << " destructor called" << std::endl;
}
