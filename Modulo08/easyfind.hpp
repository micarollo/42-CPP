#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
int easyfind(const T& container, int value) 
{
    auto it = std::find(container.begin(), container.end(), value);
    if (it != container.end()) {
        return std::distance(container.begin(), it); // Found the value, return its index
    } else {
        // If not found, you can throw an exception or return an error value
        throw std::runtime_error("Value not found");
        // Alternatively, you can return -1 as an error value:
        // return -1;
    }
}

#endif