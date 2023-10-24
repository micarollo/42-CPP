#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string.h>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    public:
        Dog(void);
        Dog(Dog const &cp);
        ~Dog();
        Dog &operator=(const Dog &dog);
        virtual void makeSound(void) const;
        Brain & getBrain(void) const;

    private:
        Brain * _brain;
};

#endif