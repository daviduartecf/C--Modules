#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "Robotomy Form Created" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "Robotomy Form Destroyed" << std::endl;
}
RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& other) {
    if (this != &other) {
		_target = other.getTarget();
	}
    return *this;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm() {
    *this = other;
}

std::string RobotomyRequestForm::getTarget() const {
    return _target;
}

void RobotomyRequestForm::executeAction() const {
    std::cout << "BRRRRRRRRRRRRRR!!!!!!!" << std::endl;
    if (std::rand() % 2)
        std::cout << this->getTarget() << " was robotomized" << std::endl;
    else
        std::cout << "Robotomy failed" << std::endl;
}
