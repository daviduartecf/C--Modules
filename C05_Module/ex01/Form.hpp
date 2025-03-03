#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    public:
        void    beSigned(Bureaucrat& bureaucrat);
        Form(const std::string& name, int signGrade, int execGrade);
        Form();
        ~Form();
        Form(const Form& other);
        Form& operator = (const Form& other);
        //Getters
        int getSignGrade(void) const;
        int getExecGrade(void) const;
        bool getStatus(void);
        std::string getName() const;
        //Exceptions
        class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		};
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _execGrade;
};

std::ostream& operator << (std::ostream& os, Form& other);

#endif
