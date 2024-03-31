#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Form f1("f1", 0, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------------------------------------" << std::endl;
	try {
		Form f2("f2", 151, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------------------------------------" << std::endl;
	try{
		Form f3("f3", 1, 1);
		Bureaucrat b4("b4", 1);
		b4.signForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------------------------------------" << std::endl;
	try{
		Form f4("f4", 5, 5);
		Bureaucrat b5("b5", 2);
		b5.signForm(f4);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
