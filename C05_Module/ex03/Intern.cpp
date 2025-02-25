#include "Intern.hpp"
#include "AForm.hpp"

Intern::Intern() {

}

Intern::~Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator = (const Intern& other) {
    (void)other;
    return *this;
}

static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    const std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*formCreators[])(const std::string&) = {createShrubbery, createRobotomy, createPardon};
    
    for (size_t i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target); 
        }
    }
    throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what(void) const throw() {
    return "Error: Intern couldn't find the requested form.";
}