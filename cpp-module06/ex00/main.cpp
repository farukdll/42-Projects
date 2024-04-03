#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << " You should enter ./convert [value] !! " << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}
