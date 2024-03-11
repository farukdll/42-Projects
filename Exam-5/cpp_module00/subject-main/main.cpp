#include "../Warlock.hpp"

#define TEST 1

int main()
{
    #if TEST
    {
        Warlock bob;
        Warlock jim("Jim", "the nauseating");
        bob = jim;
        Warlock jack(jim);
    }
    #else
    {
        Warlock const richard("Richard", "Mistress of Magma");
        richard.introduce();
        std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

        Warlock* jack = new Warlock("Jack", "the Long");
        jack->introduce();
        jack->setTitle("the Mighty");
        jack->introduce();

        delete jack;
    }
    #endif

}