#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    // this->_type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
    this->_brain = new Brain();
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->_brain;
}

Cat::Cat(const Cat &cp) : Animal(cp._type)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->_brain = new Brain();
    *this = cp;
}

Cat &Cat::operator=(Cat const &cat)
{
    this->_type = cat._type;
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Cat sound" << std::endl;
}

Brain & Cat::getBrain(void) const
{
    return (*this->_brain);
}