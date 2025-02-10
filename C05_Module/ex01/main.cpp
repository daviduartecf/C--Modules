#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
    std::cout	<< std::endl
				<< "*** constructor ***"
				<< std::endl << std::endl;

	try {
		Bureaucrat	pippo("pippo", 1);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		Bureaucrat	poppi("poppi", -42);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}


	try {
		Bureaucrat	poppi("poppi", 4242);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		Bureaucrat noob("noob", 10);
		Form form("form", 9, 50);
		//form.beSigned(noob);
		noob.signForm(form);
		std::cout << form;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
    std::cout	<< std::endl
            << "*** increment ***"
            << std::endl << std::endl;

	try {
		Bureaucrat	pippo("pippo", 3);
        std::cout << pippo;
		pippo.incrementGrade();
        std::cout << pippo;
		pippo.incrementGrade();
        std::cout << pippo;
		pippo.incrementGrade(); // catch error
        std::cout << "wtf" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

    std::cout	<< std::endl
            << "*** decrement ***"
            << std::endl << std::endl;

	try {
		Bureaucrat	pippo("pippo", 148);
        std::cout << pippo;
		pippo.decrementGrade();
        std::cout << pippo;
		pippo.decrementGrade();
        std::cout << pippo;
		pippo.decrementGrade(); // catch error
        std::cout << "wtf" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}