#include "iter.hpp"
#include <iostream>

template < typename T >
void	prints( T c)
{
	std::cout << c << std::endl;
	return ;
}

int	main(void)
{
	int			arrayInt[5] = {0, 1, 2, 3, 4};
	std::string	arrayStr[5] = {"Retsuko", "Fenneko", "Haida", "Washimi", "Gori"};
	const char	*arrayStrC[5] = {"Haida", "Washimi", "Retsuko", "Fenneko", "Gori"};
	char		arrayChar[5] = {'r', 'e', 't', 's', 'u'};
    float       bye[3] = {1.2, 2.3, 3.4};

	iter<int>(arrayInt, 5, prints);
	std::cout << std::endl;
	iter<int>(arrayInt, 2, prints);
	std::cout << std::endl;

	iter<std::string>(arrayStr, 5, prints);
	std::cout << std::endl;

	iter<const char *>(arrayStrC, 5, prints);
	std::cout << std::endl;

	iter<char>(arrayChar, 5, prints);
	std::cout << std::endl;

    iter<float>(bye, 3, prints);
	std::cout << std::endl;

	return (0);
}