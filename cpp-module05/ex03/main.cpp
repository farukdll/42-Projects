#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	AForm *form;
	Bureaucrat *bureaucrat;
	bureaucrat = new Bureaucrat("buse", 1);
	form = intern.makeForm("shrubbery creation form", "Bender");
	bureaucrat->signForm(*form);
	bureaucrat->executeForm(*form);
	delete bureaucrat;
	delete form;
	return 0;
}