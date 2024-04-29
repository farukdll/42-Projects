#include "BitcoinExchange.hpp"

int main (int ac, char **av) {
	if (ac != 2)
	{
		std::cout << "Error" << std::endl;
		return EXIT_FAILURE;
	}
	
	BitcoinExchange btc(av[1]);

	try{
		btc.func();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}