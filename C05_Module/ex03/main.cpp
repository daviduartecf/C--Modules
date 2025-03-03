#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

void	sectionTitle(const std::string& title) {
	std::cout	<< std::endl
				<< "*** " << title << " ***"
				<< std::endl << std::endl;
}

Bureaucrat	david("david", 2);
Intern		intern;

void	testMake(const std::string& formName, const std::string& target) {
	sectionTitle(formName);

	AForm* form = intern.makeForm(formName, target);

	std::cout << *form;
	david.signForm(*form);
	david.executeForm(*form);

	delete form;
}

int	main() {
	std::srand(std::time(0));
	try {
		testMake("robotomy request", "Manuel");
		testMake("presidential pardon", "daduarte");
		testMake("shrubbery creation", "here");
		testMake("not a form", "you");
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
