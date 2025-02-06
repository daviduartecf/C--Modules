#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat& operator = (const Bureaucrat& other);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat(std::string name, int grade);
		const std::string getName(void);
		int getGrade(void);
		void incrementGrade(void);
		void decrementGrade(void);
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

#endif
