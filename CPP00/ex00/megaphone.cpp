#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			int j = 0;
			while (argv[i][j])
				std::cout << (char) toupper(argv[i][j++]);
		}
		std::cout << std::endl;
	}
	return (0);
}