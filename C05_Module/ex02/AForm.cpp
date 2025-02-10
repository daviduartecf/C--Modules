#include "AForm.hpp"
#include "Bureaucrat.hpp"

void    AForm::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= _signGrade)
        _signed = true;
    else
        throw GradeTooLowException();
}

AForm::AForm(const std::string& name, int signGrade, int execGrade)
    : _name(name), 
    _signed(false),
    _signGrade(signGrade), 
    _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    std::cout << "AForm custom constructor was called!" << std::endl;
}

AForm::AForm(): _name("Default AForm"), _signed(false), _signGrade(75), _execGrade(75) {
    std::cout << "AForm default constructor was called!" << std::endl;
}

AForm::~AForm() {
    std::cout << "AForm destructor was called!" << std::endl;
}
AForm::AForm(const AForm& other)
    : _name(other._name), 
    _signed(false), 
    _signGrade(other._signGrade),
    _execGrade(other._signGrade) {
    std::cout << "AForm copy constructor was called!" << std::endl;
}
AForm& AForm::operator = (const AForm& other) {
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

std::ostream& operator << (std::ostream& os, AForm& AForm) {
    os << "AForm: " << AForm.getName() << std::endl;
    os << "Signed: " << (AForm.getStatus() ? "Yes" : "No") << std::endl;
    os << "Sign Grade: " << AForm.getSignGrade() << std::endl;
    os << "Exec Grade: " << AForm.getExecGrade() << std::endl;
    return os;
}

//Getters
int AForm::getSignGrade(void) const {
    return _signGrade;
}

int AForm::getExecGrade(void) const {
    return _execGrade;
}

bool AForm::getStatus(void) {
    return _signed;
}

std::string AForm::getName() const {
    return _name;
}

//Exceptions
const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm: grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm: grade is too low!";
}

