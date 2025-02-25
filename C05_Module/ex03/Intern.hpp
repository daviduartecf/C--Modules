#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Bureaucrat;

class Intern {
    public:
        Intern();
        ~Intern();
        Intern(const Intern& other);
        Intern& operator = (const Intern& other);
        AForm* makeForm(const std::string& formName, const std::string& target);
        class FormNotFoundException : public std::exception {
            public:
                const char* what() const throw();
        };
};

#endif