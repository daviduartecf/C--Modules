#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name(""), _grade(150) {
	std::cout << "Bureaucrat default constructor was called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) {
	std::cout << "Bureaucrat default constructor was called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor was called" << std::endl;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& other){
	if (this != &other) {
		this->_grade = other._grade;
	}
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
	_grade -= 1;
}

void Bureaucrat::decrementGrade(void) {
	_grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {

}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {

}
