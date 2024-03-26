#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal 
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& WrongAnimal);
		WrongAnimal& operator=(const WrongAnimal& WrongAnimal);
		const std::string& getType() const;
		void makeSound() const;
		virtual ~WrongAnimal();

	protected:
		std::string type;
};


#endif
