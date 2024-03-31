#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("undefined"){
    std::cout << "Bureaucrat default constructor called." << std::endl;
    this->grade = 150;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	if (this != &copy) 
        *this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	this->grade = copy.grade;
	return *this;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

const std::string &Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::incrementGrade() {
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade() 
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void Bureaucrat::signForm(Form &form)
{
	try{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " could not sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "The entered grade is too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "The entered grade is too low.";
}

std::ostream &operator<<(std::ostream &outputGate, const Bureaucrat &entryClass) {
	outputGate << entryClass.getName() << ", bureaucrat grade " << entryClass.getGrade();
	return outputGate;
}
