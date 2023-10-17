#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    // this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
    this->_brain = new Brain();
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->_brain;
}

Dog::Dog(Dog const &cp) : Animal(cp._type)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_brain = new Brain();
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