#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat1("b1", 160);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat bureaucrat2("b2", -5);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------------------------------------" << std::endl;
	Bureaucrat bureaucrat3("b3", 1);
	try
	{
		bureaucrat3.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------------------------------------" << std::endl;
	Bureaucrat bureaucrat4("b4", 150);
	try
	{
		bureaucrat4.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------------------------------------" << std::endl;
		Bureaucrat bureaucrat5("b5", 120);
	try
	{
		bureaucrat3.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucrat5 << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	Bureaucrat bureaucrat6("b6", 100);
	try
	{
		bureaucrat4.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucrat6 << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	Bureaucrat bureaucrat7("b7", 2);
	Bureaucrat bureaucrat8(bureaucrat7);
	std::cout << bureaucrat8 << std::endl;
	std::cout << bureaucrat7 << std::endl;
	Bureaucrat bureaucrat9("b9", 3);
	bureaucrat9 = bureaucrat7;
	std::cout << bureaucrat9 << std::endl;
	return 0;
}
