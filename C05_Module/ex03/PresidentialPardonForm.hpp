#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm: public AForm {
    public:
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator = (const PresidentialPardonForm& other);
        void executeAction() const;   
        std::string getTarget() const;
    private:
        const std::string _target;
};

#endif