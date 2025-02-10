#include "Bureaucrat.hpp"
#include "Form.hpp"

void Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(): _name(""), _grade(150) {
	std::cout << "Bureaucrat default constructor was called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) {
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	std::cout << "Bureaucrat default constructor was called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor was called" << std::endl;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& other){
	if (this != &other) {
		this->_grade = other._grade;
	}
	return *this;
}

std::ostream& operator << (std::ostream& os, Bureaucrat& other) {
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return os;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat copy constructor was called" << std::endl;
}

const std::string Bureaucrat::getName(void) {
	return _name;
}

int Bureaucrat::getGrade(void) {
	return _grade;
}

void Bureaucrat::incrementGrade(void) {
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade -= 1;
}

void Bureaucrat::decrementGrade(void) {
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "Bureaucrat grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "Bureaucrat grade too low!";
}
