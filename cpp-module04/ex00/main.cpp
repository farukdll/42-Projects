#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << "Animal type is " << dog->getType() << " " << std::endl;
	std::cout << "Animal type is " <<cat->getType() << " " << std::endl;
	meta->makeSound();
	dog->makeSound();
	cat->makeSound();
	wrongCat->makeSound();

	delete meta;
	delete dog;
	delete cat;

	return 0;
}