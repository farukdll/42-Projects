#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "AAnimal.hpp"

int main()
{
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	dog->makeSound();
	cat->makeSound();
	delete cat;
	delete dog;

	return 0;
}