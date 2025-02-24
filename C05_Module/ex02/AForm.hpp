#ifndef AAForm_HPP
#define AAForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    public:
        virtual void executeAction() const = 0;
        void execute(Bureaucrat const &executor) const;
        void    beSigned(Bureaucrat& bureaucrat);
        AForm(const std::string& name, int signGrade, int execGrade);
        //Orthodox Canonical AForm
        AForm();
        virtual ~AForm();
        AForm(const AForm& other);
        AForm& operator = (const AForm& other);
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
        class FormNotSignedException : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _execGrade;
};

std::ostream& operator << (std::ostream& os, AForm& other);

#endif