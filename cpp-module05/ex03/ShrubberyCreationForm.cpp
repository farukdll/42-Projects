#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructer called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), target(copy.target)
{
	if(this != &copy)
		*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy){
	AForm::operator=(copy);
	this->target = copy.target;
	return *this;
}

void ShrubberyCreationForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (this->isSigned == true)
		throw AForm::AlreadySignedException();
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->isSigned = true;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	if (executor.getGrade() > this->gradeToExecute)
		throw AForm::GradeTooLowException();
	else
	{
		std::ofstream file(this->target + "_shrubbery", std::ios::trunc);
		file << 
"                                                         \n"
		"                      ,@@@@@@@,                          \n"
		"              ,,,.   ,@@@@@@/@@,  .oo8888o.              \n"
		"           ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o            \n"
		"          ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'         \n"
		"           %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'         \n"
		"          %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'           \n"
		"          `&%\\ ` /%&'    |.|        \\ '|8'             \n"
		"              |o|        | |         | |                 \n"
		"              |.|        | |         | |                 \n"
		"        jgs \\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_   \n"
		" -----------------------------------------------------   \n" << std::endl;
		file.close();
		std::cout << this->target + "_shrubbery created" << std::endl;
	}
}

