#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

	class Animal{
		protected:
			std::string type;
		public:
			Animal();
			Animal(const Animal& animal);
			Animal& operator=(const Animal& animal);
			const std::string& getType() const;
			virtual void makeSound() const;
			virtual ~Animal();
	};


#endif