#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;
	public:
		virtual ~AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);

		const std::string& getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		
		virtual void execute(Bureaucrat const &executor) = 0;
		virtual void beSigned(Bureaucrat const &bureaucrat) = 0;

		/*exceptions*/
        class GradeTooHighException :public std::exception
		{
            public:
                virtual const char *what() const throw();
		};

        class GradeTooLowException :public std::exception
		{
            public:
                virtual const char *what() const throw();
        };
        class AlreadySignedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &outputGrade, const AForm &e);

#endif
