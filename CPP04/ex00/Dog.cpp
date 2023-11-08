#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog const &cp) : Animal(cp._type)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = cp;
    return ;
}

Dog &Dog::operator=(Dog const &dog)
{
    this->_type = dog._type;
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Dog sound" << std::endl;
}