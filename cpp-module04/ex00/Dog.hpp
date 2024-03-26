#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal{
	public:
		Dog();
		Dog(const Dog& dog);
		Dog& operator=(const Dog& dog);
		std::string getType() const;
		void makeSound() const;
		~Dog();
};


#endif
