#include "Form.hpp"
#include "Bureaucrat.hpp"

void    Form::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= _signGrade)
        _signed = true;
    else
        throw GradeTooLowException();
}

Form::Form(const std::string& name, int signGrade, int execGrade)
    : _name(name), 
    _signed(false),
    _signGrade(signGrade), 
    _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    std::cout << "Form custom constructor was called!" << std::endl;
}

Form::Form(): _name("Default Form"), _signed(false), _signGrade(75), _execGrade(75) {
    std::cout << "Form default constructor was called!" << std::endl;
}

Form::~Form() {
    std::cout << "Form destructor was called!" << std::endl;
}
Form::Form(const Form& other)
    : _name(other._name), 
    _signed(false), 
    _signGrade(other._signGrade),
    _execGrade(other._signGrade) {
    std::cout << "Form copy constructor was called!" << std::endl;
}
Form& Form::operator = (const Form& other) {
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

std::ostream& operator << (std::ostream& os, Form& form) {
    os << "Form: " << form.getName() << std::endl;
    os << "Signed: " << (form.getStatus() ? "Yes" : "No") << std::endl;
    os << "Sign Grade: " << form.getSignGrade() << std::endl;
    os << "Exec Grade: " << form.getExecGrade() << std::endl;
    return os;
}

//Getters
int Form::getSignGrade(void) const {
    return _signGrade;
}

int Form::getExecGrade(void) const {
    return _execGrade;
}

bool Form::getStatus(void) {
    return _signed;
}

std::string Form::getName() const {
    return _name;
}

//Exceptions
const char* Form::GradeTooHighException::what() const throw() {
    return "Form: grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form: grade is too low!";
}

