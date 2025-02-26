#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << "Presidential Form Created" << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "Presidential Form Destroyed" << std::endl;
}
PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& other) {
    if (this != &other) {}
    return *this;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other) {
    *this = other;
}

std::string PresidentialPardonForm::getTarget() const {
    return _target;
}

void PresidentialPardonForm::executeAction() const {
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}