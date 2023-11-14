#include "ScalarConverter.hpp"

int	main(int argc, char **argv )
{
	try 
	{
		if (argc != 2)
		{
			std::cout << "Usage: ./convert arg" << std::endl;
			return (1);
		}
		ScalarConverter::convert(argv[1]);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}