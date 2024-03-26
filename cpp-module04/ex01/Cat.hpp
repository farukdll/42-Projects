#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{
    private:
        Brain* brain;
    public:
        Cat();
        Cat(const Cat& cat);
	    Cat& operator=(const Cat& cat);
	    void makeSound() const;
	    ~Cat();
};

#endif
