#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(const T& container, int value) 
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), value);
    if (it != container.end()) {
        throw std::exception();
    } else {
        return (it);
    }
}

#endif