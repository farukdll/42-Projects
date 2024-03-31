#include "AForm.hpp"

AForm::~AForm()
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) :  name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if  (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	this->isSigned = false;
}

AForm::AForm(const AForm &copy) : name(copy.name), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute)
{
    if (this != &copy)
		*this = copy;
}

AForm &AForm::operator=(const AForm &copy)
{
	std::cout << "Just sign copied, other things const, they can't overwritten."<< std::endl;
	this->isSigned = copy.gradeToSign;
	return *this;
}

void AForm::beSigned(const Bureaucrat &bureaucrat){
	if (this->isSigned == true)
		throw AForm::AlreadySignedException();
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->isSigned = true;
}

const std::string &AForm::getName() const
{
	return this->name;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int AForm::getGradeToSign() const 
{
	return this->gradeToSign;
}

int AForm::getGradeToExecute() const 
{
	return this->gradeToExecute;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "The entered grade is too high.";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "The entered grade is too low.";
}

const char *AForm::AlreadySignedException::what() const throw() {
	return "The form already signed.";
}


std::ostream &operator<<(std::ostream &outputGate, const AForm &e) {
	outputGate << e.getName() << ", form grade to sign " << e.getGradeToSign() << ", grade to execute" << \
	e.getGradeToExecute() << std::endl;
	return outputGate;
}
