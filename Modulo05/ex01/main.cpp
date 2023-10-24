#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat	bob("bob", 6);

	std::cout << bob << std::endl;
	bob.decreaseGrade();
	std::cout << bob << std::endl;
	bob.increaseGrade();
	bob.increaseGrade();
	bob.increaseGrade();
	bob.increaseGrade();
	std::cout << bob << std::endl;

    try
	{
		Bureaucrat	bob("bob", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

     try
	{
		 Bureaucrat	bob("bob", 2);
	    bob.increaseGrade();
	    std::cout << bob << std::endl;
	    bob.increaseGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

      try
	{
		Bureaucrat	bob("bob", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}