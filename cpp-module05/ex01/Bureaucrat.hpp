#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        Bureaucrat(const std::string &name, int grade);

        // get functions
        const std::string &getName() const;
        int getGrade() const;
        // other functions
        void incrementGrade();
        void decrementGrade();
        void signForm(Form &form);

        //exceptions
        class GradeTooHighException :public std::exception{
            public:
                const char *what() const throw();
        };

        class GradeTooLowException :public std::exception{
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &outputGate, const Bureaucrat &entryClass);

#endif