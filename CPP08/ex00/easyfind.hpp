#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <algorithm>


class	EasyFindException : public std::exception
{
public:
	virtual const char *	what() const throw()
    {
        return ("Value not found in this container");
    }
};

template <typename T>
typename T::iterator easyfind(T & c, int value) 
{
    typename T::iterator it = find(c.begin(), c.end(), value);
    if (it == c.end())
        throw EasyFindException();
    return it;
}

#endif