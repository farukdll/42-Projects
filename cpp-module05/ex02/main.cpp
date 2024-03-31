#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::cout << "----------------------------------------------------" << std::endl;

	AForm *form = new PresidentialPardonForm("buse");
	Bureaucrat *bureaucrat = new Bureaucrat("ycanga", 27);
	bureaucrat->signForm(*form);
	bureaucrat->executeForm(*form);
	
	std::cout << "----------------------------------------------------" << std::endl;

	Bureaucrat *bureaucrat2 = new Bureaucrat("miskiriksu", 40);
	AForm *form2 = new RobotomyRequestForm("makbulutsu");
	bureaucrat2->signForm(*form2);
	bureaucrat2->executeForm(*form2);
	
	std::cout << "----------------------------------------------------" << std::endl;

	Bureaucrat *bureaucrat3 = new Bureaucrat("başaks", 2);
	AForm *form3 = new ShrubberyCreationForm("Form");
	bureaucrat3->signForm(*form3);
	bureaucrat3->executeForm(*form3);
	
	std::cout << "----------------------------------------------------" << std::endl;

	delete bureaucrat3;
	delete form3;
	delete form2;
	delete bureaucrat2;
	delete bureaucrat;
	delete form;
	return 0;
}