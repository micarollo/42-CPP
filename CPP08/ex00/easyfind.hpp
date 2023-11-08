#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
// #include <iterator>
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
typename T::iterator easyfind(const T& container, int value) 
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), value);
    if (it != container.end()) {
        throw EasyFindException();
    } else {
        return (it);
    }
}


#endif