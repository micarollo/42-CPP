#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << std::endl << "1. Intern creates a shrubbery creation form" << std::endl;
		try
		{
			Intern	SH;
			AForm *	form;

			form = SH.makeForm("ShrubberyCreationForm", "Pedro");
            std::cout << *form << std::endl;
            std::cout << form << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "2. Intern creates a robotomy request" << std::endl;
		try
		{
			Intern	RB;
			AForm *	form;

			form = RB.makeForm("RobotomyRequestForm", "Pedro");
			std::cout << *form << std::endl;
            std::cout << form << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "3. Intern creates a presidential pardon form" << std::endl;
		try
		{
			Intern	Ana;
			AForm *	form;

			form = Ana.makeForm("PresidentialPardonForm", "Pedro");
			std::cout << *form << std::endl;
            std::cout << form << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;

	std::cout << std::endl << "4. Intern intents to create an invalid form" << std::endl;
		try
		{
			Intern	INV;
			AForm *	form;

			form = INV.makeForm("hgello", "Pedro");
			std::cout << "Should be NULL: " << form << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	std::cout << std::endl << "--------------------------------------------------------------------" << std::endl;
    return 0;
}