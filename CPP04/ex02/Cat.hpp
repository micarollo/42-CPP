#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string.h>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    public:
        Cat(void);
        Cat(const Cat &cp);
        ~Cat();
        Cat &operator=(const Cat &cat);
        virtual void makeSound(void) const;
        Brain & getBrain(void) const;
    
    private:
        Brain * _brain;
};

#endif