#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	srand(time(NULL));
	Base *ptr = A::generate();
	std::cout << "--------------------" << std::endl;
    std::cout << ptr << std::endl;

    std::cout << "identify that take pointer" << std::endl;
	A::identify(ptr);
    std::cout << "identify that take reference" << std::endl;
	A::identify(*ptr);
	std::cout << "--------------------" << std::endl;

	delete ptr;
	return (0);
}
