#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);
		AForm *makeForm(const std::string &name, const std::string &target);
		class UnknownFormException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif