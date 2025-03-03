#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ctime>
#include <cstdlib>

int main(void)
{
	std::srand(std::time(0));
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("nabo", 149);
		//AForm *b = new PresidentialPardonForm("default");
		// AForm *b = new RobotomyRequestForm("default");
		AForm *b = new ShrubberyCreationForm("default");
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << *b << std::endl;

		try
		{
			b->beSigned(*a);
			b->execute(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << *b << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		AForm *c = new PresidentialPardonForm("some dude");
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << *c;
		std::cout << std::endl;

		// Try to execute before signing
		try
		{
			c->execute(*b);
		}
	    catch (std::exception &e)
		{
			std::cerr << "\033[33m" << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;
		try
		{
			c->beSigned(*a);
		}
		catch(std::exception &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}

		// CEO signs the Form
		std::cout << std::endl;
		std::cout << *c;
		std::cout << std::endl;
		try
		{
			c->beSigned(*b);
		}
		catch(std::exception &e)
		{
			std::cerr << "\033[33m" << b->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;
		std::cout << *c;
		std::cout << std::endl;

		std::cout << std::endl;
		b->signForm(*c);
		std::cout << std::endl;

		try
		{
			c->execute(*a);
		}
		catch(std::exception &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;

		try
		{
			c->execute(*b);
		}
		catch(std::exception &e)
		{
			std::cerr << "\033[33m" << b->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		PresidentialPardonForm *b = new PresidentialPardonForm("this other dude");
		PresidentialPardonForm *c = new PresidentialPardonForm(*b);
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a->getName() << std::endl;
		std::cout << *b;
		std::cout << *c;
		try {
			b->beSigned(*a);
			a->signForm(*c);
			b->execute(*a);
			a->executeForm(*c);
			c->execute(*a);
		}
		catch(std::exception &e) {
			std::cerr << "\033[33m" << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		RobotomyRequestForm *b = new RobotomyRequestForm("Bender");
		ShrubberyCreationForm *c = new ShrubberyCreationForm("christmas");
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a->getName() << std::endl;
		std::cout << *b << std::endl;
		std::cout << *c << std::endl;
		try {
			b->beSigned(*a);
			a->signForm(*c);
			std::cout << *b << std::endl;
			std::cout << *c << std::endl;
			for (int i= 0; i < 10; i++)
				b->execute(*a);
			// a->executeForm(*c);
			c->execute(*a);
		}
		catch(std::exception &e) {
			std::cerr << "\033[33m" << e.what() << "\033[0m" << std::endl;
		}

		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	return (0);
}
