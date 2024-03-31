#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
	(void)copy;
	return *this;
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	if (name == "shrubbery creation form")
		return new ShrubberyCreationForm(target);
	else if (name == "robotomy request form")
		return new RobotomyRequestForm(target);
	else if (name == "presidential pardon form")
		return new PresidentialPardonForm(target);
	else
		throw Intern::UnknownFormException();
}

const char *Intern::UnknownFormException::what() const throw()
{
	return "The entered form is unknown.";
}
