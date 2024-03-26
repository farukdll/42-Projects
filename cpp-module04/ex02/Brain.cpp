#include "Brain.hpp"

Brain::Brain() 
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &brain) 
{
	*this = brain;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &brain) {
	for(int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	std::cout << "Brain assignation operator called" << std::endl;
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}
