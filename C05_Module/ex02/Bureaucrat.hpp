#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat& operator = (const Bureaucrat& other);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat(std::string name, int grade);
		const std::string getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(AForm& AForm);
		void executeForm(AForm &form) const;
		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		};
	private:
		std::string const _name;
		int _grade;
};

std::ostream& operator << (std::ostream& os, Bureaucrat& other);

#endif
